#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>
using namespace std;

class DoubleSubscriptedArray
{
    friend ostream &operator << ( ostream &, const DoubleSubscriptedArray & );
    friend ostream &operator >> ( ostream &, const DoubleSubscriptedArray & );
public:
    DoubleSubscriptedArray(unsigned int, unsigned int);
    int &operator()(unsigned int, unsigned int);
    const int &operator()(unsigned int, unsigned int) const;
    unsigned int getSize() const;
    bool operator==(DoubleSubscriptedArray&) const;
    bool operator!=(DoubleSubscriptedArray& a) const
    {
        return !(*this == a);
    }
    void operator=(DoubleSubscriptedArray&);

private:
    int *doubleArray;
    unsigned int string;
    unsigned int column;
    unsigned int size;
};
#endif
