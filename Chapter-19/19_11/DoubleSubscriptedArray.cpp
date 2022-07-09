#include "DoubleSubscriptedArray.h"

DoubleSubscriptedArray::DoubleSubscriptedArray(unsigned int string, unsigned int column)
{
    (*this).string = string;
    (*this).column = column;
    size = string * column;
    doubleArray = new int[size];
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
    //return *(doubleArray + (column * string) - 1);
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
