#pragma once

class BigInt{
private:
    int my_base;
    int my_dlina;
    int32_t* my_mas;
public:
    BigInt();
    BigInt(int32_t a);
    BigInt(std::string a);
    BigInt(const BigInt& other);
    BigInt& operator=(const BigInt& other);
    BigInt(BigInt&& other);
    BigInt& operator=(BigInt&& other);
    friend BigInt operator+(const BigInt& lhs, const BigInt& rhs);
    friend BigInt operator+(const BigInt& lhs, int32_t a);
    friend BigInt operator*(const BigInt& lhs, const BigInt& rhs);
    friend BigInt operator*(const BigInt& lhs, int32_t a);
    bool operator==(const BigInt& other)const;
    bool operator!=(const BigInt& other)const;
    bool operator<(const BigInt& other)const;
    bool operator>(const BigInt& other)const;
    ~BigInt();
    int32_t getInt() const;
    std::string getString()const;
    void pechat(bool normal_vid=1)const;
    
};

