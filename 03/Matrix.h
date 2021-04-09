#pragma once
#include "ProxyRow.h"

class Matrix{
private:
    size_t n_rows;
    size_t n_cols;
    ProxyRow* my_rows;
public:
    Matrix();
    Matrix(size_t r, size_t c);
    Matrix(const Matrix& otherMatrix);
    Matrix& operator=(const Matrix& otherMatrix);
    friend Matrix operator+ (const Matrix& lhs, const Matrix& rhs);
    bool operator == (const Matrix& other);
    bool operator != (const Matrix& other);
    Matrix& operator *= (int32_t K);
    ProxyRow& operator[](size_t i);
    const ProxyRow& operator[] (size_t i)const;
    void pechat()const;
    size_t getNRows()const;
    size_t getNCols()const;
    ~Matrix();
    
    
    
};
