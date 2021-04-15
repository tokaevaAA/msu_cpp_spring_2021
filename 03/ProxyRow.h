#pragma once

class ProxyRow{
private:
    size_t row_size;
    int32_t* row_data;
public:
    ProxyRow();
    ~ProxyRow();
    ProxyRow(size_t a_size);
    ProxyRow(const ProxyRow& otherRow);
    ProxyRow& operator=(const ProxyRow& otherRow);
    friend ProxyRow operator+ (const ProxyRow &lhs, const ProxyRow &rhs);
    bool operator == (const ProxyRow &other)const;
    bool operator != (const ProxyRow &other)const;
    ProxyRow& operator *= (int32_t K);
    int32_t& operator[](size_t j);
    const int32_t& operator[](size_t j)const;
    size_t getSize()const;
    void pechat()const;
};
   
    
