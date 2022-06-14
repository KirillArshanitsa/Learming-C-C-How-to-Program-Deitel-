#ifndef INTEGERSET_H
#define INTEGERSET_H

#define SET_SIZE 100

class IntegerSet
{
public:
    IntegerSet();
    IntegerSet(bool[], int);
    void insertElement(int);
    void deleteElement(int);
    void printSet();
    bool isEqualTo(IntegerSet&);
    IntegerSet unionOfSets(IntegerSet&);
    IntegerSet intersectionOfSets(IntegerSet&);
private:
    bool a[SET_SIZE]{};
    bool isEmpty;
};
#endif // !INTEGERSET_H
