#pragma once

template<class T>
class Iterator{
    T* tek;
public:
    Iterator(T* given=nullptr);
    T& operator*() const;
    Iterator<T>& operator++();
    Iterator<T> operator++(int);
    Iterator<T>& operator--();
    Iterator<T> operator--(int);
    Iterator operator-(size_t n) const;
    bool operator==(const Iterator<T>& other)const;
    bool operator!=(const Iterator<T>& other)const;
    bool operator<(const Iterator<T>& other)const;
    bool operator>(const Iterator<T>& other)const;
    bool operator>=(const Iterator<T>& other)const;
    bool operator<=(const Iterator<T>& other)const;
};

