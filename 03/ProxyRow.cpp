#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include "ProxyRow.h"


ProxyRow::ProxyRow():row_size(0),row_data(nullptr)
{}

ProxyRow::~ProxyRow(){
    //printf("destr ProxyRow %p\n",this);
    delete[] row_data;
    
}
ProxyRow::ProxyRow(size_t a_size):row_size(a_size){
    row_data=new int32_t[a_size];
    
}
        
ProxyRow::ProxyRow(const ProxyRow& otherRow){
    //if (row_data!=0){delete [] row_data;}
    row_size=otherRow.getSize();
    row_data=new int32_t[row_size];
    for (size_t i=0; i<row_size; i=i+1){
        row_data[i]=otherRow[i];
    }
}
        
ProxyRow& ProxyRow::operator=(const ProxyRow& otherRow){
    if (row_data!=0){delete [] row_data;}
    row_size=otherRow.getSize();
    row_data=new int32_t[row_size];
    for (size_t i=0; i<row_size; i=i+1){
        row_data[i]=otherRow[i];
    }
    return *this;
}
          
ProxyRow operator+ (const ProxyRow &lhs, const ProxyRow &rhs){
    if (lhs.getSize()!=rhs.getSize()){throw std::out_of_range("Out2");}
    ProxyRow tmp = lhs;
    for (size_t i=0; i<lhs.getSize(); i=i+1){tmp[i]=tmp[i]+rhs[i];}
    return tmp;
}
        
bool ProxyRow::operator==(const ProxyRow& other){
    if (row_size != other.getSize ()) {throw std::out_of_range ("Out3");}
    for (size_t i = 0; i < row_size; i++){
        if (row_data[i] != other[i]) {return false;}
    }
    return true;
}
        
bool ProxyRow::operator !=(const ProxyRow& other){
    if (row_size != other.getSize ()) {throw std::out_of_range ("Out4");}
    for (size_t i = 0; i < row_size; i++){
        if (row_data[i] != other[i]) {return true;}
    }
    return false;
}

ProxyRow& ProxyRow::operator *= (int32_t K){
    for (size_t i = 0; i < row_size; i++){row_data[i] *= K;}
    return (*this);
}

        
int32_t& ProxyRow::operator[](size_t j){
    return row_data[j];
}
        
const int32_t& ProxyRow::operator[](size_t j)const{
    return row_data[j];
}
        
size_t ProxyRow::getSize()const {
    return row_size;
}
        
void ProxyRow::pechat()const{
    for (size_t i=0; i<row_size; i=i+1){
        printf("%d ",row_data[i]);
    }
    printf("\n");
}
            
       
