#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>

class BigInt{
private:
    int my_base;
    int my_dlina;
    int32_t* my_mas;
public:
    BigInt():my_base(1000),my_dlina(0),my_mas(nullptr){}
    
    BigInt(int32_t a){
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
    
    BigInt(std::string a){
        my_base=1000;
        int cnt=0;
        if (a.length()%3==1){
            a="00"+a;
        }
        else if (a.length()%3==2){
            a="0"+a;
        }
        my_dlina=a.length()/3;
        printf("a=%s\n",a.c_str());
        my_mas=new int32_t[my_dlina];
        int j=0;
        for (int i=a.length()-3; i>=0; i=i-3){
            int32_t tek_token=std::stoi(a.substr(i,3));
            //printf("%d\n",tek_token);
            my_mas[j]=tek_token;
            j=j+1;
        }
        
        
        
    }
    BigInt(const BigInt& other){
        printf("Hello from BigInt(const BigInt& other)\n");
        my_base=other.my_base;
        my_dlina=other.my_dlina;
        my_mas=new int32_t[my_dlina];
        for (int i=0; i<my_dlina; i=i+1){
            my_mas[i]=other.my_mas[i];
            
        }
        
    }
    
    BigInt& operator=(const BigInt& other){
        printf("Hello from BigInt& operator=(const BigInt& other)\n");
        if (this==&other){return *this;}
        if (my_mas!=0){delete []my_mas;}
        my_base=other.my_base;
        my_dlina=other.my_dlina;
        my_mas=new int32_t[my_dlina];
        for (int i=0; i<my_dlina; i=i+1){
            my_mas[i]=other.my_mas[i];
        }
        return *this;
    }
    
    BigInt(BigInt&& other){
        printf("Hello from BigInt(const BigInt&& other)\n");
        my_base=other.my_base;
        my_dlina=other.my_dlina;
        my_mas=other.my_mas;
        other.my_mas=nullptr;
        other.my_dlina=0;
        
    }
    
    BigInt& operator=(BigInt&& other){
        printf("Hello from BigInt& operator=(const BigInt&& other)\n");
        if (this==&other){return *this;}
        if (my_mas!=0){delete []my_mas;}
        my_base=other.my_base;
        my_dlina=other.my_dlina;
        my_mas=other.my_mas;
        other.my_mas=nullptr;
        other.my_dlina=0;
        return *this;
    }
    
    friend BigInt operator+(const BigInt& lhs, const BigInt& rhs){
        if (lhs.my_base!=rhs.my_base){printf("Lhs and rhs have different bases; Error\n"); throw std::out_of_range("different bases");}
        BigInt otv;
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
        if (otv.my_mas[otv.my_dlina-1]==0){
            otv.my_dlina-=1;
            int32_t* new_mas=new int32_t[otv.my_dlina];
            for (int i=0; i<otv.my_dlina; i=i+1){
                new_mas[i]=otv.my_mas[i];
            }
            delete[] otv.my_mas;
            otv.my_mas=new_mas;
            
        }
        return otv;
    }
    
    friend BigInt operator+(const BigInt& lhs, int32_t a){
        BigInt rhs=BigInt(a);
        BigInt otv=lhs+rhs;
        return otv;
    }
    
    friend BigInt operator*(const BigInt& lhs, const BigInt& rhs){
        if (lhs.my_base!=rhs.my_base){printf("Lhs and rhs have different bases; Error\n"); throw std::out_of_range("different bases");}
        BigInt otv;
        otv.my_base=lhs.my_base;
        otv.my_dlina=lhs.my_dlina*rhs.my_dlina;
        otv.my_mas=new int32_t[otv.my_dlina];
        //make nulls in otv.my_mas
        for (int i=0; i<otv.my_dlina; i=i+1){
            otv.my_mas[i]=0;
        }
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
        //if first digit=0 =>delete it
        if (otv.my_mas[otv.my_dlina-1]==0){
            otv.my_dlina-=1;
            int32_t* new_mas=new int32_t[otv.my_dlina];
            for (int i=0; i<otv.my_dlina; i=i+1){
                new_mas[i]=otv.my_mas[i];
            }
            delete[] otv.my_mas;
            otv.my_mas=new_mas;
            
        }
        return otv;
    }
    
    friend BigInt operator*(const BigInt& lhs, int32_t a){
        BigInt rhs=BigInt(a);
        BigInt otv=lhs*rhs;
        return otv;
    }
    
   
    
    bool operator==(const BigInt& other){
        int32_t a=(*this).getInt();
        int32_t b=other.getInt();
        return a==b;
    }
    
    bool operator!=(const BigInt& other){
        int32_t a=(*this).getInt();
        int32_t b=other.getInt();
        return a!=b;
    }
    
    bool operator<(const BigInt& other){
        int32_t a=(*this).getInt();
        int32_t b=other.getInt();
        return a<b;
    }
    
    bool operator>(const BigInt& other){
        int32_t a=(*this).getInt();
        int32_t b=other.getInt();
        return a>b;
    }
    
    ~BigInt(){delete[] my_mas;}
    
    int32_t getInt() const{
        int32_t dop=1;
        int32_t otv=0;
        for (int i=0; i<my_dlina; i=i+1){
            otv+=my_mas[i]*dop;
            dop=dop*my_base;
        }
        return otv;
    }
    void pechat(bool normal_vid=1)const{
        if (normal_vid==0){
            for (int i=0; i<my_dlina; i=i+1){
                printf("%d ",my_mas[i]);
            }
        }
        else{
            for (int i=my_dlina-1; i>=0; i=i-1){
                printf("%d ",my_mas[i]);
            }
        }
        
        printf("\n");
    }
    
};

int main(){
    printf("Hello!\n");
    
    BigInt b1=BigInt("1807");
    b1.pechat();
    BigInt b2=BigInt("17534");
    b2.pechat();
    BigInt b3=b1+b2;
    b3.pechat();
    BigInt b4=b1+b2+105007;
    b4.pechat();
    
    printf("-----\n");
    BigInt b5=b1*b2;
    b5.pechat();
    int32_t otvb5=b5.getInt();
    printf("otvb5=%d\n",otvb5);
    
    BigInt b6=BigInt(-6);
    BigInt b7=BigInt(17);
    BigInt b8=b6+b7;
    b8.pechat();
    
    
    printf("Goodbye!\n");
}
