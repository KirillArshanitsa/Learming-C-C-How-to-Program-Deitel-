#include "DoubleSubscriptedArray.h"

DoubleSubscriptedArray::DoubleSubscriptedArray(unsigned int string, unsigned int column)
{
    (*this).string = string;
    (*this).column = column;
    size = string * column;
    doubleArray = new int[size];
    for (unsigned int i = 0; i < size; i++)
        doubleArray[i] = 0;
}

ostream &operator << ( ostream &output, const DoubleSubscriptedArray & doubleArray )
{
    for (unsigned int i = 0; i < doubleArray.size ; i++){
        if (i % doubleArray.string)
            output << doubleArray.doubleArray[i] << " ";
        else{
            output << endl;
            output << doubleArray.doubleArray[i] << " ";
        }
    }
    return output;
}

ostream &operator >> ( ostream &output, const DoubleSubscriptedArray & doubleArray )
{
    for (unsigned int i = 0; i < doubleArray.size ; i++){
        output << doubleArray.doubleArray[i] << " ";
    }
    output << endl;
    return output;
}

unsigned int DoubleSubscriptedArray::getSize() const
{
    return size;
}

int & DoubleSubscriptedArray::operator()(unsigned int string, unsigned int column)
{
    return *(doubleArray + (column * (*this).string) - (*this).string +  string - 1);

}

const int & DoubleSubscriptedArray::operator()(unsigned int string, unsigned int column) const
{
    return *(doubleArray + (column * (*this).string) - (*this).string +  string - 1);
}

bool DoubleSubscriptedArray::operator==(DoubleSubscriptedArray &anotherDoubleSubscriptedArray) const
{
    if (size == anotherDoubleSubscriptedArray.size){
        for (unsigned int i = size; i < size; i++){
            if (doubleArray[i] != anotherDoubleSubscriptedArray.doubleArray[i])
                return false;
        }
        return true;
    }
    else
        return false;
}

void DoubleSubscriptedArray::operator=(DoubleSubscriptedArray &anotherDoubleSubscriptedArray)
{
    delete [] doubleArray;
    size = anotherDoubleSubscriptedArray.size;
    string = anotherDoubleSubscriptedArray.string;
    column = anotherDoubleSubscriptedArray.column;
    doubleArray = new int[size];
    //or use memcopy
    for(unsigned int i = 0 ;i < size; i++)
        doubleArray[i] = anotherDoubleSubscriptedArray.doubleArray[i];

}

int DoubleSubscriptedArray::operator[](unsigned int n) const
{
    if (n > size){
        cout << "Error max size array = " << size  << endl;
        return -1;
    }
    else if (n <= 0) {
        cout << "You nust enter umner more than 0." << endl;
        return -1;
    }
    else {
        int* sortCopy = new int[size];
        memcpy(sortCopy, doubleArray, sizeof(int) * size);
        unsigned int tmp;
        for (unsigned int e = 0; e < n; e++) {
            for (unsigned i = e + 1; i < size; i++) {
                if (sortCopy[e] < sortCopy[i]) {
                    tmp = sortCopy[e];
                    sortCopy[e] = sortCopy[i];
                    sortCopy[i] = tmp;
                }
            }
        }

        //cout << endl;
        //for (unsigned i = 0; i < size; i++)
        //    cout << sortCopy[i] << " ";
        //cout << endl;

        return sortCopy[n - 1];
    }
}

