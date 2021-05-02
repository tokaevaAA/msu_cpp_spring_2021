#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <math.h>
#include "BigInt.h"


void BigInt::remove_zeros(){
    int cnt=0;
    if ((*this).my_mas[(*this).my_dlina-cnt-1]==0){
        cnt+=1;
    }
    if (cnt>0){
        (*this).my_dlina-=cnt;
        int32_t* new_mas=new int32_t[(*this).my_dlina];
        for (int i=0; i<(*this).my_dlina; i=i+1){
            new_mas[i]=(*this).my_mas[i];
        }
        delete[] (*this).my_mas;
        (*this).my_mas=new_mas;
    }
    
}



BigInt::BigInt():my_isNeg(false),my_base(1000),my_dlina(0),my_mas(nullptr){}
    
BigInt::BigInt(int32_t a){
    my_isNeg=(a>=0)?false:true;
    if (a<0){a=-a;}
    my_base=1000;
    int cnt=0;
    int32_t a1=a;
    while (a1!=0){
        cnt+=1;
        a1=a1/my_base;
    }
    my_mas=new int32_t[cnt];
    int i=0;
    while (a!=0){
        my_mas[i]=a%my_base;
        a=a/my_base;
        i=i+1;
    }
    my_dlina=cnt;
            
}
    
BigInt::BigInt(std::string a){
    if (a[0]=='-'){my_isNeg=true; a=a.substr(1,a.size()-1);}
    else {my_isNeg=false;}
    my_base=1000;
    if (a.length()%3==1){
        a="00"+a;
    }
    else if (a.length()%3==2){
        a="0"+a;
    }
    my_dlina=a.length()/3;
    //printf("a=%s\n",a.c_str());
    my_mas=new int32_t[my_dlina];
    int j=0;
    for (int i=a.length()-3; i>=0; i=i-3){
        int32_t tek_token=std::stoi(a.substr(i,3));
        //printf("%d\n",tek_token);
        my_mas[j]=tek_token;
        j=j+1;
    }
}


BigInt::BigInt(const BigInt& other){
    //printf("Hello from BigInt(const BigInt& other)\n");
    my_isNeg=other.my_isNeg;
    my_base=other.my_base;
    my_dlina=other.my_dlina;
    my_mas=new int32_t[my_dlina];
    for (int i=0; i<my_dlina; i=i+1){
        my_mas[i]=other.my_mas[i];
    }
}
    
BigInt& BigInt::operator=(const BigInt& other){
    //printf("Hello from BigInt& operator=(const BigInt& other)\n");
    if (this==&other){return *this;}
    if (my_mas!=0){delete []my_mas;}
    my_isNeg=other.my_isNeg;
    my_base=other.my_base;
    my_dlina=other.my_dlina;
    my_mas=new int32_t[my_dlina];
    for (int i=0; i<my_dlina; i=i+1){
        my_mas[i]=other.my_mas[i];
    }
    return *this;
}
    
BigInt::BigInt(BigInt&& other){
    //printf("Hello from BigInt(const BigInt&& other)\n");
    my_isNeg=other.my_isNeg;
    my_base=other.my_base;
    my_dlina=other.my_dlina;
    my_mas=other.my_mas;
    other.my_mas=nullptr;
    other.my_dlina=0;
}
    
BigInt& BigInt::operator=(BigInt&& other){
        //printf("Hello from BigInt& operator=(const BigInt&& other)\n");
        if (this==&other){return *this;}
        if (my_mas!=0){delete []my_mas;}
        my_isNeg=other.my_isNeg;
        my_base=other.my_base;
        my_dlina=other.my_dlina;
        my_mas=other.my_mas;
        other.my_mas=nullptr;
        other.my_dlina=0;
        return *this;
    }

bool abs_of_left_is_greater(const BigInt& lhs, const BigInt& rhs){
    if (lhs.my_dlina > rhs.my_dlina){return true;}
    else if (lhs.my_dlina < rhs.my_dlina){return false;}
    else{for (int i=lhs.my_dlina-1; i>=0; i=i-1){
            if (lhs.my_mas[i]<rhs.my_mas[i]){return false;}
                }
        return true;
    }
}
    
BigInt add_absolute_values(const BigInt& lhs, const BigInt& rhs){
    if (lhs.my_base!=rhs.my_base){printf("Lhs and rhs have different bases; Error\n"); throw std::out_of_range("different bases");}
        
        BigInt otv;
        otv.my_isNeg=false;
        otv.my_base=lhs.my_base;
        otv.my_dlina=fmax(lhs.my_dlina,rhs.my_dlina)+1;
        otv.my_mas=new int32_t[otv.my_dlina];
        for (int i=0; i<otv.my_dlina; i=i+1){
            otv.my_mas[i]=0;
        }
        int perenos=0;
        for (int i=0; i<otv.my_dlina; i=i+1){
            int t=0;
            if (i<lhs.my_dlina){t+=lhs.my_mas[i];}
            if (i<rhs.my_dlina){t+=rhs.my_mas[i];}
            t+=perenos;
            if (t>=lhs.my_base){perenos=t/lhs.my_base; t=t%lhs.my_base;}
            else{perenos=0;}
            otv.my_mas[i]=t;
        }
        otv.remove_zeros();
        return otv;
    
}

BigInt subtract_absolute_values(const BigInt& lhs, const BigInt& rhs){
    if (lhs.my_base!=rhs.my_base){printf("Lhs and rhs have different bases; Error\n"); throw std::out_of_range("different bases");}
        
        BigInt otv;
        otv.my_isNeg=false;
        otv.my_base=lhs.my_base;
        otv.my_dlina=lhs.my_dlina;
        otv.my_mas=new int32_t[otv.my_dlina];
        for (int i=0; i<otv.my_dlina; i=i+1){
            otv.my_mas[i]=0;
        }
        int zaem=0;
        for (int i=0; i<otv.my_dlina; i=i+1){
            int t=lhs.my_mas[i];
            if (i<rhs.my_dlina){t-=rhs.my_mas[i];}
            t-=zaem;
            if (t<0){zaem=1; t=lhs.my_base-fabs(t);}
            else{zaem=0;}
            otv.my_mas[i]=t;
        }
        otv.remove_zeros();
        return otv;
    
}

BigInt operator+(const BigInt& lhs, const BigInt& rhs){
    if (lhs.my_base!=rhs.my_base){printf("Lhs and rhs have different bases; Error\n"); throw std::out_of_range("different bases");}
    
    BigInt otv;
    if ((lhs.my_isNeg== true and rhs.my_isNeg==true) or (lhs.my_isNeg== false and rhs.my_isNeg==false)){
        otv=add_absolute_values(lhs, rhs);
        otv.my_isNeg=lhs.my_isNeg;
        otv.remove_zeros();
        return otv;
    }
    else if (abs_of_left_is_greater(lhs, rhs)){
        otv=subtract_absolute_values(lhs, rhs);
        otv.my_isNeg=lhs.my_isNeg;
        return otv;
    }
    else if (!abs_of_left_is_greater(lhs, rhs)){
        otv=subtract_absolute_values(rhs, lhs);
        otv.my_isNeg=rhs.my_isNeg;
        return otv;
    }
    return otv;
}
    
BigInt operator+(const BigInt& lhs, int32_t a){
    BigInt rhs=BigInt(a);
    BigInt otv=lhs+rhs;
    return otv;
    }
    
BigInt operator-(const BigInt& lhs, const BigInt& rhs){
    if (lhs.my_base!=rhs.my_base){printf("Lhs and rhs have different bases; Error\n"); throw std::out_of_range("different bases");}
    
    BigInt tmp;
    tmp.my_isNeg=!rhs.my_isNeg;
    tmp.my_base=rhs.my_base;
    tmp.my_dlina=rhs.my_dlina;
    tmp.my_mas=new int32_t[tmp.my_dlina];
    for (int i=0; i<tmp.my_dlina; i=i+1){
        tmp.my_mas[i]=rhs.my_mas[i];
    }
    return lhs+tmp;
}


BigInt operator*(const BigInt& lhs, const BigInt& rhs){
    if (lhs.my_base!=rhs.my_base){printf("Lhs and rhs have different bases; Error\n"); throw std::out_of_range("different bases");}
    BigInt otv;
    if ((lhs.my_isNeg== true and rhs.my_isNeg==true) or (lhs.my_isNeg== false and rhs.my_isNeg==false)){ otv.my_isNeg=false;}
    else {otv.my_isNeg=true;}
    otv.my_base=lhs.my_base;
    otv.my_dlina=lhs.my_dlina*rhs.my_dlina;
    otv.my_mas=new int32_t[otv.my_dlina];
    //make nulls in otv.my_mas
    for (int i=0; i<otv.my_dlina; i=i+1){otv.my_mas[i]=0;}
    //multiply
    for (int i=0; i<rhs.my_dlina; i=i+1){
        for (int j=0; j <lhs.my_dlina; j=j+1){
            BigInt tmp=BigInt(rhs.my_mas[i]*lhs.my_mas[j]);
            for (int t=0; t<tmp.my_dlina; t=t+1){
                otv.my_mas[i+j+t]+=tmp.my_mas[t];
            }
        }
    }
    //make perenos
    int perenos=0;
    for (int i=0; i<otv.my_dlina; i=i+1){
        otv.my_mas[i]+=perenos;
        if (otv.my_mas[i] > otv.my_base){
            perenos=otv.my_mas[i]/otv.my_base;
            otv.my_mas[i]=otv.my_mas[i]%otv.my_base;
        }
        else{perenos=0;}
    }
    otv.remove_zeros();
    return otv;
    }
    
BigInt operator*(const BigInt& lhs, int32_t a){
    BigInt rhs=BigInt(a);
    BigInt otv=lhs*rhs;
    return otv;
    }
    
   
    
bool BigInt::operator==(const BigInt& other)const{
    if ((*this).my_isNeg != other.my_isNeg || (*this).my_dlina != other.my_dlina) {return false;}
    else{
        for (int i = 0; i < (*this).my_dlina; i=i+1) {
            if ((*this).my_mas[i] != other.my_mas[i]) {return false;}
        }
    }
    return true;
}
    
bool BigInt::operator!=(const BigInt& other)const{
        return !((*this)==other);
    }
    
bool BigInt::operator<(const BigInt& other)const{
    if ((*this).my_isNeg != other.my_isNeg) {return (*this).my_isNeg;}
    else if (other.my_isNeg){
        if ((*this).my_dlina != other.my_dlina){return (*this).my_dlina > other.my_dlina;}
        else{
            return ((*this)!=other)&&abs_of_left_is_greater((*this),other);
        }
    }
    else if (!other.my_isNeg){
        if ((*this).my_dlina != other.my_dlina){return (*this).my_dlina < other.my_dlina;}
        else{
            return ((*this)!=other)&&(!abs_of_left_is_greater((*this),other));
        }
    }
    return true;
}
    
bool BigInt::operator>(const BigInt& other)const{
    return (!((*this)<other))&&((*this)!=other);
    }
    
BigInt::~BigInt(){delete[] my_mas;}
    
int32_t BigInt::getInt() const{
    int32_t dop=1;
    int32_t otv=0;
    for (int i=0; i<my_dlina; i=i+1){
        otv+=my_mas[i]*dop;
        dop=dop*my_base;
    }
    if ((*this).my_isNeg){otv=-otv;}
    return otv;
}

std::string BigInt::getString()const{
    std::string otv;
    for (int i=0; i<my_dlina; i=i+1){
        std::string tek_token=std::to_string(my_mas[i]);
        if (tek_token.length()==1){tek_token="00"+tek_token;}
        if (tek_token.length()==2){tek_token="0"+tek_token;}
        std::reverse(tek_token.begin(), tek_token.end());
        otv+=tek_token;
    }
    std::reverse(otv.begin(), otv.end());
    //printf("s=%s\n",otv.c_str());
    return otv;
    
}
void BigInt::pechat(bool normal_vid)const{
        if (normal_vid==0){
            if (my_isNeg){printf("-");}
            for (int i=0; i<my_dlina; i=i+1){
                printf("%d ",my_mas[i]);
            }
        }
        else{
            if (my_isNeg){printf("-");}
            for (int i=my_dlina-1; i>=0; i=i-1){
                printf("%d ",my_mas[i]);
            }
        }
        
        printf("\n");
    }
    

