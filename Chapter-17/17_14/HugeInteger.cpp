#include "HugeInteger.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::isdigit;


bool HugeInteger::isZero()
{
    if (integerSize == 0)
        return true;
    else
        return false;
}

bool HugeInteger::isLessThanOrEqualTo(HugeInteger &anotherHugeInt)
{
    return !isGreaterThan(anotherHugeInt) || isEqualTo(anotherHugeInt);
}

bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger &anotherHugeInt)
{
    return isGreaterThan(anotherHugeInt) || isEqualTo(anotherHugeInt);
}


bool HugeInteger::isLessThan(HugeInteger &anotherHugeInt)
{
    return !isGreaterThan(anotherHugeInt);
}

bool HugeInteger::isGreaterThanUnsigned(HugeInteger& anotherHugeInt)
{
    if (integerSize < anotherHugeInt.integerSize)
        return false;
    else if(integerSize > anotherHugeInt.integerSize)
        return true;
    else {
        for (size_t i = digitSize - integerSize; i != digitSize; i++) {
            if (hugeInteger[i] > anotherHugeInt.hugeInteger[i])
                return true;
        }
    }
}

bool HugeInteger::isGreaterThan(HugeInteger &anotherHugeInt)
{
    if (isNegativeSign && !anotherHugeInt.isNegativeSign)
        return false;
    else if (!isNegativeSign && anotherHugeInt.isNegativeSign)
        return true;
    else if(!isNegativeSign && !anotherHugeInt.isNegativeSign) {
        if (integerSize > anotherHugeInt.integerSize)
            return true;
        else if(integerSize < anotherHugeInt.integerSize)
            return false;
        else {
            for (size_t i = digitSize - integerSize; i != digitSize; i++) {
                if (hugeInteger[i] < anotherHugeInt.hugeInteger[i])
                    return false;
            }
        }
    }
    else{ //isNegativeSign && anotherHugeInt.isNegativeSign
        if (integerSize < anotherHugeInt.integerSize)
            return true;
        else if(integerSize > anotherHugeInt.integerSize)
            return true;
        else {
            for (size_t i = digitSize - integerSize; i != digitSize; i++) {
                if (hugeInteger[i] > anotherHugeInt.hugeInteger[i])
                    return false;
            }
        }
    }
}

bool HugeInteger::isEqualTo(HugeInteger &anotherHugeInt)
{

    if (isNegativeSign != anotherHugeInt.isNegativeSign)
        return false;

    if (integerSize != anotherHugeInt.integerSize)
        return false;
    else {
        for (size_t i = digitSize - integerSize; i != digitSize ; i++) {
            if (hugeInteger[i] != anotherHugeInt.hugeInteger[i])
                return false;
        }
    }
    return true;
}

bool HugeInteger::isNotEqualTo(HugeInteger &anotherHugeInt)
{
    return !isEqualTo(anotherHugeInt);
}

bool HugeInteger::input()
{
    string enteredInt;
    cout << "Enter integer with max digit size = " << digitSize << endl;
    cin >> enteredInt;

    if (enteredInt[0] == '0'){
        cout << "First char cannot be 0." << endl;
        return false;
    }

    if (enteredInt[0] == '-') {
        isNegativeSign = true;
        integerSize = enteredInt.size() - 1;
    }
    else {
        isNegativeSign = false;
        integerSize = enteredInt.size() ;
    }

    if (digitSize < integerSize) {
        cout << "You enter number with size more than " << digitSize << endl;
        return false;
    }

    //TODO change this if else
    if(isNegativeSign){
        for (size_t e = digitSize, i = integerSize + 1; i != 0; i--, e--) {
            if(enteredInt[i - 1] == '-')
                break;

            if (isdigit(enteredInt[i - 1]))
                hugeInteger[e - 1] = enteredInt[i - 1];
            else {
                cout << "This is not a digit " << enteredInt[i - 1] << endl;
                return false;
            }
        }
    }
    else {
        for (size_t e = digitSize, i = integerSize; i != 0; i--, e--) {
            if (isdigit(enteredInt[i - 1]))
                hugeInteger[e - 1] = enteredInt[i - 1];
            else {
                cout << "This is not a digit " << enteredInt[i - 1] << endl;
                return false;
            }
        }
    }

    if (digitSize != integerSize) {
        for (size_t i = digitSize - integerSize - 1; i != 0; i--)
            hugeInteger[i] = '0';
        hugeInteger[0] = '0';
    }

    return true;
}

void HugeInteger::output()
{
    if (integerSize == 0){
        cout << "Number is null" << endl;
        return;
    }
    if (isNegativeSign){
        cout << '-';
    }

    for(size_t i = digitSize - integerSize; i < digitSize; i++)
        cout << hugeInteger[i];
    cout << endl;
}


void HugeInteger::subtract(HugeInteger &anotherHugeInt)
{
    if (isEqualTo(anotherHugeInt)) { //4 - 4
        integerSize = 1;
        hugeInteger[DIGIT_SIZE - 1] = 48;
    }
    else if (isNegativeSign && anotherHugeInt.isNegativeSign){// -3 - (-2) | -2 - (-3)
        if (isGreaterThanUnsigned(anotherHugeInt)){ // -3 - (-2) = 3 - 2
            baseSubtract(anotherHugeInt);
        }
        else {
            *this = subtractAndReturn(anotherHugeInt, *this); //-2 - (-3) = 3 - 2
            isNegativeSign = false;
        }
    }
    else if(!isNegativeSign && !anotherHugeInt.isNegativeSign) {   // 4 - 1 | 1 - 4
        if (isGreaterThanUnsigned(anotherHugeInt)){ // 4 - 1
            baseSubtract(anotherHugeInt);
        }
        else{// 1 - 4 = 4 - 1
            *this = subtractAndReturn(anotherHugeInt, *this);
            isNegativeSign = true;
        }
    }
    else{ //4 - (-1) |  1- (-4) or -3 - 2 | -2 -3  (!isNegativeSign && anotherHugeInt.isNegativeSign)  (isNegativeSign && !anotherHugeInt.isNegativeSign)
        baseSum(anotherHugeInt);
    }

//    if (!isNegativeSign && anotherHugeInt.isNegativeSign){ //4 - (-1) |  1- (-4)
//        baseSum(anotherHugeInt);
//    }
//    else if(isNegativeSign && !anotherHugeInt.isNegativeSign){ //-3 - 2 | -2 -3
//        baseSum(anotherHugeInt);
//    }
//    else if(isNegativeSign && anotherHugeInt.isNegativeSign){// -3 - (-2) | -2 - (-3)
//        if (isGreaterThanUnsigned(anotherHugeInt)){ // -3 - (-2) = 3 - 2
//            baseSubtract(anotherHugeInt);
//        }
//        else {
//            *this = subtractAndReturn(anotherHugeInt, *this); //-2 - (-3) = 3 - 2
//            isNegativeSign = false;
//        }
//    }
//    else{   // 4 - 1 | 1 - 4
//        if (isGreaterThanUnsigned(anotherHugeInt)){ // 4 - 1
//            baseSubtract(anotherHugeInt);
//        }
//        else{// 1 - 4 = 4 - 1
//            *this = subtractAndReturn(anotherHugeInt, *this);
//            isNegativeSign = true;
//        }
//    }

}


void HugeInteger::add(HugeInteger &anotherHugeInt)
{
    if (isEqualTo(anotherHugeInt)) { //4 - 4
        integerSize = 1;
        hugeInteger[DIGIT_SIZE - 1] = 48;
    }
     else if (!isNegativeSign && anotherHugeInt.isNegativeSign){
         if (isGreaterThanUnsigned(anotherHugeInt)){ //4 + (-1)
            baseSubtract(anotherHugeInt);//4 - 1
         }
         else{                                          //1 + (-4)
             *this = HugeInteger::subtractAndReturn(anotherHugeInt, *this);  //4 - 1
             isNegativeSign = true;
         }
     }
     else if(isNegativeSign && !anotherHugeInt.isNegativeSign){
         if (isGreaterThanUnsigned(anotherHugeInt)){ //-3 + 2
             baseSubtract(anotherHugeInt);//3-2
         }
         else {                                     //-2 + 3
             *this = HugeInteger::subtractAndReturn(anotherHugeInt, *this); //3 - 2
             isNegativeSign = false;
         }
     }
     else
         baseSum(anotherHugeInt);//-+- +++
}




void HugeInteger::baseSum(const HugeInteger &anotherHugeIntRef)
{
    //TODO int ot size_t
    int maxIntSize = anotherHugeIntRef.integerSize;
    int intgerI;
    if (anotherHugeIntRef.integerSize < integerSize)
        maxIntSize = integerSize;

    for (size_t i = digitSize - 1, size = 0; maxIntSize > 0 ; i--, maxIntSize--) {
        intgerI = anotherHugeIntRef.hugeInteger[i] + hugeInteger[i] - 96; // 48 * 2 = 96 for char int
        while (intgerI > 9) {
            hugeInteger[i] = intgerI - 10 + 48; //- 10 + 48 - int to char
            if (i == 0) {
                cout << "Overflow error." << endl;
            }
            intgerI = hugeInteger[i - 1]  + anotherHugeIntRef.hugeInteger[i - 1] - 96 + 1;// 48 * 2 = 96 for char int, + 1 for previous sum
            i--;
            maxIntSize--;
            size++;
            if (size > integerSize)
                integerSize++;
        }
        hugeInteger[i] = intgerI + 48; // +48 - int to char
        size++;
        if (size > integerSize)
            integerSize++;
    }
}


void HugeInteger::baseSubtract(const HugeInteger& anotherHugeInt)
{
    for (size_t currentNumSize = anotherHugeInt.integerSize, i = digitSize - 1, e; currentNumSize != 0; currentNumSize--, i--){
        if (hugeInteger[i] < anotherHugeInt.hugeInteger[i]){
            if (hugeInteger[i] == '0'){
                hugeInteger[i] = (10 - anotherHugeInt.hugeInteger[i] + 48) + 48;// +48 char -int
                e = i - 1;
                while(hugeInteger[e] == '0'){
                    hugeInteger[e] = '9'; //10 -1
                    e--;
                }
                if ((e + integerSize == digitSize) && (hugeInteger[e] == 49)) { //int 49 = char 1
                   integerSize--;
                    continue;
                }
                hugeInteger[e]--;
            }
            else{
                hugeInteger[i] = (10 + hugeInteger[i] - 48 - anotherHugeInt.hugeInteger[i] + 48) + 48;//+ and - 48 convert int -char
                e = i - 1;

                while(hugeInteger[e] == '0'){
                    hugeInteger[e] = '9'; //10 -1
                    e--;
                }
                if ((e + integerSize == digitSize) && (hugeInteger[e] == 49)){ //int 49 =  char 1
                    integerSize--;
                    continue;
                }
                hugeInteger[e]--;
            }
        }
        else{
            hugeInteger[i] = hugeInteger[i] - anotherHugeInt.hugeInteger[i] + 48; //+48 - int and char convert
        }

    }
}


HugeInteger HugeInteger::subtractAndReturn(HugeInteger num1, const HugeInteger& num2)
{
    for (size_t currentNumSize = num2.integerSize, i = num1.digitSize - 1, e; currentNumSize != 0; currentNumSize--, i--){
        if (num1.hugeInteger[i] < num2.hugeInteger[i]){
            if (num1.hugeInteger[i] == '0'){
                num1.hugeInteger[i] = (10 - num2.hugeInteger[i] + 48) + 48;// +48 char -int
                e = i - 1;
                while(num1.hugeInteger[e] == '0'){
                    num1.hugeInteger[e] = '9'; //10 -1
                    e--;
                }
                if (e + num1.integerSize == num1.digitSize) {
                    num1.integerSize--;
                    continue;
                }
                num1.hugeInteger[e]--;
            }
            else{
                num1.hugeInteger[i] = (10 + num1.hugeInteger[i] - 48 - num2.hugeInteger[i] + 48) + 48;//+ and - 48 convert int -char
                e = i - 1;
                while(num1.hugeInteger[e] == '0'){
                    num1.hugeInteger[e] = '9'; //10 -1
                    e--;
                }
                if (e + num1.integerSize == num1.digitSize) {
                    num1.integerSize--;
                    continue;
                }
                num1.hugeInteger[e]--;
            }
        }
        else{
            num1.hugeInteger[i] = num1.hugeInteger[i] - num2.hugeInteger[i] + 48; //+48 - int and char convert
        }
    }
    return num1;
}

