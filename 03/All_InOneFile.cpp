#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>


    class ProxyRow{
        private:
            size_t row_size;
            int32_t* row_data;
        public:
            ProxyRow():row_size(0),row_data(nullptr){}
            ~ProxyRow(){delete[] row_data;}
            ProxyRow(size_t a_size):row_size(a_size){row_data=new int32_t[a_size];}
        
            ProxyRow(const ProxyRow& otherRow){
                if (row_data!=0){delete [] row_data;}
                row_size=otherRow.getSize();
                row_data=new int32_t[row_size];
                for (size_t i=0; i<row_size; i=i+1){
                    row_data[i]=otherRow[i];
                }
            }
        
            ProxyRow& operator=(const ProxyRow& otherRow){
                if (row_data!=0){delete [] row_data;}
                row_size=otherRow.getSize();
                row_data=new int32_t[row_size];
                for (size_t i=0; i<row_size; i=i+1){
                    row_data[i]=otherRow[i];
                }
                return *this;
            }
          
            friend ProxyRow operator+ (const ProxyRow &lhs, const ProxyRow &rhs){
                //printf("friend ProxyRow operator+ started\n");
                if (lhs.getSize()!=rhs.getSize()){throw std::out_of_range("Out3");}
                lhs.pechat();
                ProxyRow tmp = lhs;
                tmp.pechat();
                for (size_t i=0; i<lhs.getSize(); i=i+1){tmp[i]+=rhs[i];}
                return tmp;
            }
        
            bool operator == (const ProxyRow &other){
                if (row_size != other.getSize ()) {throw std::out_of_range ("Out4");}
                for (size_t i = 0; i < row_size; i++){
                    if (row_data[i] != other[i]) {return false;}
                }
                return true;
            }
        
            bool operator != (const ProxyRow &other){
                if (row_size != other.getSize ()) {throw std::out_of_range ("Out4");}
                for (size_t i = 0; i < row_size; i++){
                    if (row_data[i] != other[i]) {return true;}
                }
                return false;
            }

            ProxyRow& operator *= (int32_t K){
                for (size_t i = 0; i < row_size; i++){row_data[i] *= K;}
                return (*this);
            }

        
        
            int32_t& operator[](size_t j){return row_data[j];}
        
            const int32_t& operator[](size_t j)const{return row_data[j];}
        
            size_t getSize()const {return row_size;}
        
            void pechat()const{
                for (size_t i=0; i<row_size; i=i+1){
                    printf("%d ",row_data[i]);
                }
                printf("\n");
            }
            
        };
   
    
class Matrix{
private:
    size_t n_rows;
    size_t n_cols;
    ProxyRow* my_rows;
public:
    Matrix():n_rows(0),n_cols(0){my_rows=nullptr;}
    
    Matrix(size_t r, size_t c):n_rows(r),n_cols(c){
        my_rows=new ProxyRow[n_rows];
        for (size_t i=0; i<n_rows; i=i+1){
            my_rows[i]=ProxyRow(n_cols);
        }
    }
    
    
    
    Matrix(const Matrix& otherMatrix):n_rows(otherMatrix.getNRows()),n_cols(otherMatrix.getNCols()){
        if (my_rows!=0){delete[] my_rows;}
        my_rows=new ProxyRow[n_rows];
        for (size_t i=0; i<n_rows; i=i+1){
            my_rows[i]=ProxyRow(n_cols);
        }
        for (size_t i=0; i<n_rows; i=i+1){
            my_rows[i]=otherMatrix[i];
        }
    }
    
    
    
    Matrix& operator=(const Matrix& otherMatrix){
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
    
    
    
    friend Matrix operator+ (const Matrix& lhs, const Matrix& rhs){
        
        if (lhs.getNRows()!=rhs.getNRows() || lhs.getNCols()!=rhs.getNCols()){throw std::out_of_range("Out5");}
        
        Matrix tmp = lhs;
        for (size_t i=0; i<lhs.getNRows(); i=i+1){
            tmp[i]=tmp[i]+rhs[i];
            
        }
        return tmp;
    }

    
    bool operator == (const Matrix& other){
        if (other.getNRows()!=n_rows || other.getNCols()!=n_cols){throw std::out_of_range("Out6");}
        for (size_t i = 0; i < n_rows; i++){
            if (my_rows[i] != other[i]) {return false;}
        }
        return true;
    }
    
    bool operator != (const Matrix& other){
        if (other.getNRows()!=n_rows || other.getNCols()!=n_cols){throw std::out_of_range("Out6");}
        for (size_t i = 0; i < n_rows; i++){
            if (my_rows[i] != other[i]) {return true;}
        }
        return false;
    }
    
    
    Matrix& operator *= (int32_t K){
        for (size_t i = 0; i < n_rows; i++){
            my_rows[i] *= K;
            
        }
        return (*this);
    }
    
    
    
   
    
    
    ProxyRow& operator[](size_t i){
            return my_rows[i];
    }
    
    
    
    const ProxyRow& operator[] (size_t i)const{
            return my_rows[i];
    }
    
    
    void pechat()const{
        for (size_t i=0; i<n_rows; i=i+1){
            my_rows[i].pechat();
        }
    }
    
    size_t getNRows()const{return n_rows;}
    size_t getNCols()const{return n_cols;}
    ~Matrix(){
        for (size_t i=0; i<n_rows; i=i+1){
            //delete my_rows[i];
        }
        delete[] my_rows;
        
    }
    
    
    
};



int main(void){
    printf("Hello!\n");
    
    Matrix my_matr1(3,4);
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=i+j;
        }
    }
    
    Matrix my_matr2(3,4);
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            my_matr2[i][j]=1;
        }
    }
    
    //test1
    my_matr1.pechat();
    my_matr2.pechat();
    
    //test2
    printf("Matr1 and Matr2 are equal: %d\n",my_matr1==my_matr2);
    
    //test3
    size_t aaa=my_matr1[0][0];
    printf("aaa=%lu\n",aaa);
    
    
    //test4
    my_matr2*=5;
    my_matr2.pechat();
    
    //test5
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=200;
        }
    }
    
    my_matr1.pechat();
    
    printf("Googbuy!\n");
    
}
