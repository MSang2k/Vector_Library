#include <iostream>
#include "\PROGRAMMING\VectorLibrary\include\my_vector.h"

// creat a vector
template <typename Type_Name>
vector<Type_Name>::vector()
    : Size(0), Capacity(5), Array(new Type_Name[Capacity])
{
}

// destructure for a vector
template <typename Type_Name>
vector<Type_Name>::~vector()
{
    delete [] Array;
}

// push back function
template <typename Type_Name>
void vector<Type_Name>::push_pack(int value)
{
    Array[Size] = value;
    ++Size;
}

// check a vector is empty or not.
template <typename Type_Name>
bool vector<Type_Name>::empty()
{
    if(!Size)
        return true;
    else
        return false;
}

// check size of a vector
template <typename Type_Name>
int vector<Type_Name>::size()
{
    return Size;
}

// check allocated capacity for a vector
template <typename Type_Name>
int vector<Type_Name>::capacity()
{
    return Capacity; // Capacity = 2.Size
}