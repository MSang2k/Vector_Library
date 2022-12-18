#include <iostream>

using namespace std;

template <typename Type_Name>
class vector
{
private:
    Type_Name *Array;
    int Size;
    int Capacity;
public:
     // create vectors
    vector();
    vector(int Size);
    vector(int Size, Type_Name Value);
    ~vector();

    // Modifiers
    void push_back(int Value);
    void pop_back();

    // Capacity
    bool empty();
    int size();
    int capacity();

    // elements access
    Type_Name& operator[](int Index);
    Type_Name& front();
    Type_Name& back();


};

/*================CREATE VECTOR==============*/

// create a vector
template <typename Type_Name>
vector<Type_Name>::vector()
    : Size(0), Capacity(10), Array(new Type_Name[Capacity])
{
}

//overload create a vector with one argument
template <typename Type_Name>
vector<Type_Name>::vector(int Size)
    : Size(Size), Capacity(2*Size), Array(new Type_Name[Capacity])
{
}

//overload create a vector with two arguments
template <typename Type_Name>
vector<Type_Name>::vector(int Size, Type_Name Value)
    : Size(Size), Capacity(2*Size), Array(new Type_Name[Capacity])
{
    for (size_t i = 0; i < Size; i++)
    {
        Array[i] = Value;
    }
    
}

// destructure for a vector
template <typename Type_Name>
vector<Type_Name>::~vector()
{
    cout << "Destructure is called" << endl;
    delete [] Array;
    Array = NULL;
}

/*================MODIFIERS==============*/

// push back function
template <typename Type_Name>
void vector<Type_Name>::push_back(int Value)
{
    Array[Size] = Value;
    ++Size;
}

// push back function
template <typename Type_Name>
void vector<Type_Name>::pop_back()
{
    if(!Size)
    {
        throw std::runtime_error("Pop back on empty vector");
    }
    else
        Size--;
}

/*================CAPACITY==============*/

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

/*================ELEMENTS ACCESS==============*/

template <typename Type_Name>
Type_Name& vector<Type_Name>::operator[](int Index)
{
    return Array[Index];
}

template <typename Type_Name>
Type_Name& vector<Type_Name>::front()
{
    return Array[0];
}

template <typename Type_Name>
Type_Name& vector<Type_Name>::back()
{
    return Array[Size - 1];
}

int main()
{
    //vector<int> V;
    vector<int> V1(3);

    cout << "Size of V1 vector: "<< V1.size() << endl;
    cout << "Capacity of V1 vector: "<< V1.capacity() << endl;
    cout << "Font element: " << V1.front() << endl;
    cout << "Back element: " << V1.back() << endl;

    cout << "Elements in V1 vector: ";
    for (size_t i = 0; i < V1.size(); i++)
    {
        cout << V1[i] << " ";
    }

    V1.pop_back();
    cout << V1[V1.size()+1] << endl;

    cout << "=================================" << endl;
    vector<float> V(3, 5.6);

    cout << "Size of V vector: "<< V.size() << endl;
    cout << "Capacity of V vector: "<< V.capacity() << endl;
    cout << "\nFont element: " << V.front() << endl;
    cout << "Back element: " << V.back() << endl;

    cout << "Elements in V vector: ";
    for (size_t i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }

    V.pop_back();
    cout << V[V.size()+1] << endl;

    return 0;
}