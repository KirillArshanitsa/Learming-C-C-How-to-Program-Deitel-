#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#define DIGIT_SIZE 5
#include <string>

class HugeInteger
{
public:
    bool input();
    void output();
    void add(HugeInteger&);
    void subtract(HugeInteger&);
    bool isEqualTo(HugeInteger&);
    bool isEqualToUnsigned(HugeInteger&);
    bool isNotEqualTo(HugeInteger&);
    bool isGreaterThan(HugeInteger&);
    bool isLessThan(HugeInteger&);
    bool isGreaterThanOrEqualTo(HugeInteger&);
    bool isLessThanOrEqualTo(HugeInteger&);
    bool isZero();

private:
    bool isNegativeSign;
    size_t digitSize = DIGIT_SIZE;
    size_t integerSize = 0;
    char hugeInteger[DIGIT_SIZE];
    bool isGreaterThanUnsigned(HugeInteger&);
    void baseSubtract(const HugeInteger&);
    void baseSum(const HugeInteger&);
    static HugeInteger subtractAndReturn(HugeInteger, const HugeInteger&);
};
#endif
