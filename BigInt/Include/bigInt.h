#ifndef LONGINTEGER_BIGINT_H
#define LONGINTEGER_BIGINT_H

#include<iostream>
#include <string>

class bigInt {
private:
    bool checkCorrect(std::string stroke);
public:
    std::string num;

    bigInt(std::string num = "0");

    bigInt& operator+(bigInt a);
    bigInt& operator+=(bigInt a);

    bigInt& operator-(bigInt a);
    bigInt& operator-=(bigInt a);

    bigInt& operator*(bigInt a);
    bigInt& operator*=(bigInt a);

    friend std::ostream& operator<<(std::ostream& out, bigInt& num);

    ~bigInt();
};


#endif
