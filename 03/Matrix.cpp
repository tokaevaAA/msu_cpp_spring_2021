#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include "ProxyRow.h"
#include "Matrix.h"

 
Matrix::Matrix():n_rows(0),n_cols(0){
    my_rows=nullptr;
}
    
Matrix::Matrix(size_t r, size_t c):n_rows(r),n_cols(c){
    my_rows=new ProxyRow[n_rows];
    for (size_t i=0; i<n_rows; i=i+1){
        my_rows[i]=ProxyRow(n_cols);
    }
}
    
    
Matrix::Matrix(const Matrix& otherMatrix): n_rows(otherMatrix.getNRows()), n_cols(otherMatrix.getNCols()){
    //if (my_rows!=0){delete[] my_rows;}
    my_rows=new ProxyRow[n_rows];
    for (size_t i=0; i<n_rows; i=i+1){
        my_rows[i]=ProxyRow(n_cols);
    }
    for (size_t i=0; i<n_rows; i=i+1){
        my_rows[i]=otherMatrix[i];
    }
}
    
    
Matrix& Matrix::operator=(const Matrix& otherMatrix){
    if (my_rows!=0){delete[] my_rows;}
    n_rows=otherMatrix.getNRows();
    n_cols=otherMatrix.getNCols();
    my_rows=new ProxyRow[n_rows];
    for (size_t i=0; i<n_rows; i=i+1){
        my_rows[i]=ProxyRow(n_cols);
    }
    for (size_t i=0; i<n_rows; i=i+1){
        my_rows[i]=otherMatrix[i];
    }
    return *this;
}
    
    
Matrix operator+ (const Matrix& lhs, const Matrix& rhs){
    if (lhs.getNRows()!=rhs.getNRows() || lhs.getNCols()!=rhs.getNCols()){throw std::out_of_range("Out5");}
    Matrix tmp = lhs;
    for (size_t i=0; i<lhs.getNRows(); i=i+1){
        tmp[i]=tmp[i]+rhs[i];
    }
    return tmp;
}

    
bool Matrix::operator == (const Matrix& other){
    if (other.getNRows()!=n_rows || other.getNCols()!=n_cols){return false;}
    for (size_t i = 0; i < n_rows; i++){
        if (my_rows[i] != other[i]) {return false;}
    }
    return true;
}
    
bool Matrix::operator != (const Matrix& other){
    if (other.getNRows()!=n_rows || other.getNCols()!=n_cols){return true;}
    for (size_t i = 0; i < n_rows; i++){
        if (my_rows[i] != other[i]) {return true;}
    }
    return false;
}
    
    
Matrix& Matrix::operator *= (int32_t K){
    for (size_t i = 0; i < n_rows; i++){
        my_rows[i] *= K;
    }
    return (*this);
}
    

ProxyRow& Matrix::operator[](size_t i){
    return my_rows[i];
}
    
const ProxyRow& Matrix::operator[] (size_t i)const{
    return my_rows[i];
}
    
    
void Matrix::pechat()const{
    for (size_t i=0; i<n_rows; i=i+1){
        my_rows[i].pechat();
    }
}
    
size_t Matrix::getNRows()const{
    return n_rows;
}
    

size_t Matrix::getNCols()const{
    return n_cols;
}
    
Matrix::~Matrix(){
    //printf("destr Matrix\n");
    for (size_t i=0; i<n_rows; i=i+1){
        //delete my_rows[i];
    }
    delete[] my_rows;
}
    
    
    
