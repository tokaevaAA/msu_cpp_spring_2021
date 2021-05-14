#pragma once

#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <future>


class ThreadPool
{
    std::vector<std::thread> vector_of_threads;
    std::queue<std::function <void()>> queue_of_tasks;
    std::atomic<bool> pool_is_working;
    std::condition_variable my_condvar;
    std::mutex my_mutex_for_queue;

public:
    explicit ThreadPool(size_t poolSize)
    {
        for (size_t i = 0; i < poolSize; i++)
        {
            vector_of_threads.emplace_back([this]()
            {
                while(true)
                {
                    printf("In while true, queue-size=%lu\n",queue_of_tasks.size());
                    std::unique_lock<std::mutex> my_lock(my_mutex_for_queue); //mutex is locked
                    while (pool_is_working && !queue_of_tasks.empty()){
                        printf("is sleeping\n");
                        my_condvar.wait(my_lock); //wait for signal from my-condvar and then grab mutex
                        printf("Got notify\n");
                    }
                    
                    if (!queue_of_tasks.empty() && pool_is_working)
                    {
                        std::function<void()> task = std::move(queue_of_tasks.front());
                        queue_of_tasks.pop();
                        my_lock.unlock();
                        task();
                    }
                    else
                    {
                        return;
                    }
                }
            });
        }
    }

    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>
    {
        using result_type = decltype(func(args...));
        auto future_task = std::make_shared<std::packaged_task<result_type()>>(std::packaged_task<result_type()>(std::move(std::bind(func, args...))));
        std::unique_lock<std::mutex> my_lock(my_mutex_for_queue);
        queue_of_tasks.emplace([future_task](){ (*future_task)(); });
        my_lock.unlock();
        my_condvar.notify_one();
        printf("in exec\n");
        return future_task->get_future();
    }

    ~ThreadPool()
    {
        pool_is_working = false;
        my_condvar.notify_all();
        for (std::thread& elem: vector_of_threads)
            elem.join();
    }
};
