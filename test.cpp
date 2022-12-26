#include <iostream>

using namespace std;

template <typename Type_Name>
class vector
{
protected:
    Type_Name *Array;
    int Size;
    int Capacity;

public:
    // create vectors
    vector();
    vector(int Size);
    vector(int Size, Type_Name Value);
    vector(const initializer_list<Type_Name> &List);
    vector(const vector &rhs); // copy constructor
    // vector(const vector &&rhs); // move constructor
    Type_Name &operator=(const vector &rhs);
    ~vector();

    Type_Name *getArray() const
    {
        return Array;
    }

    // Modifiers
    void push_back(int Value);
    void pop_back();
    void push_front(int Value);
    void pop_front();
    void insert(int Index, Type_Name Value);
    void erase(int Index);
    void clear();

    // Iterators
    Type_Name *begin();
    Type_Name *end();

    // Capacity
    bool empty();
    int size() const;
    int capacity() const;

    // elements access
    Type_Name &operator[](int Index);
    Type_Name &front();
    Type_Name &back();

    // print
    template <Type_Name>
    friend ostream &operator<<(ostream &os, const vector &rhs);
    void print();
};
//
template <typename Type_Name>
void vector<Type_Name>::print()
{
    for (int i = 0; i < Size; i++)
    {
        cout << Array[i] << " ";
    }
}
/*================CREATE VECTOR==============*/

// create a vector
template <typename Type_Name>
vector<Type_Name>::vector()
    : Size(0), Capacity(1), Array(new Type_Name[Capacity])
{
}

// overload create a vector with one argument
template <typename Type_Name>
vector<Type_Name>::vector(int Size)
    : Size(Size), Capacity(Size), Array(new Type_Name[Capacity])
{
}

// overload create a vector with two arguments
template <typename Type_Name>
vector<Type_Name>::vector(int Size, Type_Name Value)
    : Size(Size), Capacity(Size), Array(new Type_Name[Capacity])
{
    for (size_t i = 0; i < Size; i++)
    {
        Array[i] = Value;
    }
}

// create vector with list element
template <typename Type_Name>
vector<Type_Name>::vector(const initializer_list<Type_Name> &List)
    : Size(0), Capacity(List.size() + 5)
{
    Array = new Type_Name[Capacity];
    for (int i : List)
        push_back(i);
}

// copy constructor
template <typename Type_Name>
vector<Type_Name>::vector(const vector &rhs)
    : Size(rhs.Size), Capacity(rhs.Capacity), Array(new Type_Name[Capacity])
{
    for (auto i = 0; i < rhs.size(); ++i)
    {
        Array[i] = rhs.Array[i];
    }
}

// copy assignment
template <typename Type_Name>
Type_Name &vector<Type_Name>::operator=(const vector &rhs)
{
    if (rhs.Size > this->Size)
    {
        delete[] Array;
        Capacity = rhs.Size + 5;
        Array = new Type_Name[Capacity];
    }

    for (size_t i = 0; i < rhs.Size; i++)
    {
        Array[i] = rhs.Array[i];
    }
    Size = rhs.Size;
}

// move constructor
// template <typename Type_Name>
// vector<Type_Name>::vector(const vector &rhs)
//     : Size(rhs.Size), Capacity(rhs.Capacity), Array(rhs.Array)
// {
//     rhs.Array = nullptr;   //cout << "Move constructor - moving resource: " << *data << endl;
// }

// destructure for a vector
template <typename Type_Name>
vector<Type_Name>::~vector()
{
    cout << "Destructure is called" << endl;
    delete[] Array;
    Array = NULL;
}

/*================MODIFIERS==============*/

// push back function
template <typename Type_Name>
void vector<Type_Name>::push_back(int Value)
{
    if (Size < Capacity)
    {
        Array[Size] = Value;
        ++Size;
    }
    else
    {
        Capacity = Capacity * 2;
        Type_Name *ArrayTemp = new Type_Name[Capacity];
        for (size_t i = 0; i < Size; i++)
        {
            ArrayTemp[i] = Array[i];
        }
        ArrayTemp[Size] = Value;
        ++Size;
        delete[] Array;
        Array = ArrayTemp;
    }
}

// push back function
template <typename Type_Name>
void vector<Type_Name>::push_front(int Value)
{
    if (Size < Capacity)
    {

        for (int i = Size - 1; i >= 0; --i)
        {
            Array[i + 1] = Array[i];
        }

        Array[0] = Value;
        ++Size;
    }
    else
    {
        Capacity = Capacity * 2;
        for (int i = Size - 1; i >= 0; --i)
        {
            Array[i + 1] = Array[i];
        }

        Array[0] = Value;
        ++Size;
    }
}

// pop back function
template <typename Type_Name>
void vector<Type_Name>::pop_back()
{
    if (!Size)
    {
        throw std::runtime_error("Pop back on empty vector");
    }
    else
        Size--;
}

// pop front function
template <typename Type_Name>
void vector<Type_Name>::pop_front()
{
    if (!Size)
    {
        throw std::runtime_error("Pop back on empty vector");
    }
    else
    {
        for (size_t i = 0; i < Size - 1; i++)
        {
            Array[i] = Array[i + 1];
        }
        --Size;
    }
}
// insert function
template <typename Type_Name>
void vector<Type_Name>::insert(int Index, Type_Name Value)
{
    if (Index < 0 || Index >= Size)
    {
        throw std::runtime_error("Insert - Index out of range");
    }

    if (Size < Capacity)
    {

        for (int i = Size - 1; i >= Index; --i)
        {
            Array[i + 1] = Array[i];
        }

        Array[Index] = Value;
        ++Size;
    }
    else
    {
        Capacity = Capacity * 2;
        for (int i = Size - 1; i >= Index; --i)
        {
            Array[i + 1] = Array[i];
        }

        Array[Index] = Value;
        ++Size;
    }
}

// erase function
template <typename Type_Name>
void vector<Type_Name>::erase(int Index)
{
    if (Index < 0 || Index >= Size)
    {
        throw std::runtime_error("Erase - Index out of range");
    }

    for (size_t i = Index; i < Size - 1; i++)
    {
        Array[i] = Array[i + 1];
    }
    --Size;
}

template <typename Type_Name>
void vector<Type_Name>::clear()
{
    Size = 0;
}

/*================MODIFIERS==============*/

template <typename Type_Name>
Type_Name *vector<Type_Name>::begin()
{
    return &Array[0];
}

template <typename Type_Name>
Type_Name *vector<Type_Name>::end()
{
    return &Array[Size - 1];
}

/*================CAPACITY==============*/

// check a vector is empty or not.
template <typename Type_Name>
bool vector<Type_Name>::empty()
{
    if (!Size)
        return true;
    else
        return false;
}

// check size of a vector
template <typename Type_Name>
int vector<Type_Name>::size() const
{
    return Size;
}

// check allocated capacity for a vector
template <typename Type_Name>
int vector<Type_Name>::capacity() const
{
    return Capacity; // Capacity = 2.Size
}

/*================ELEMENTS ACCESS==============*/

template <typename Type_Name>
Type_Name &vector<Type_Name>::operator[](int Index)
{
    return Array[Index];
}

template <typename Type_Name>
Type_Name &vector<Type_Name>::front()
{
    return Array[0];
}

template <typename Type_Name>
Type_Name &vector<Type_Name>::back()
{
    return Array[Size - 1];
}

template <typename Type_Name>
ostream &operator<<(ostream &os, const vector<Type_Name> &rhs)
{
    Type_Name *ArrayTemp = rhs.getArray();

    for (size_t i = 0; i < rhs.size(); i++)
    {
        os << *(ArrayTemp + i) << " ";
    }
    return os;
}

void print()
{
    vector<int> v(7, 7);

    // check modifiers vector
    v.push_back(8);
    cout << "Vector after push back: ";
    v.print();
    cout << endl;

    v.pop_back();
    cout << "Vector after push back: ";
    v.print();
    cout << endl;

    v.insert(2, 3);
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    v.print();

    v.erase(2);
    cout << endl;
    v.print();

    // check iterator
    for (auto i = v.begin(); i != v.end();)
    {
        cout << i << " ";
        i++;
    }

    // check capacity
    cout << "Size of vector: " << v.size() << endl;
    cout << "Capacity of vector: " << v.capacity() << endl;

    if (v.empty())
        cout << "Vector is empty" << endl;
    else
        cout << "Vector is not empty" << endl;

    // check element access
    cout << "Front of vector: " << v.front() << endl;
    cout << "Back of vector: " << v.back() << endl;

    v.clear();
    cout << "Size of vector after clear: " << v.size() << endl;
}
int main()
{
    int a;
    vector<int> V1{1, 2, 3, 4, 5};
    for (auto i = 0; i < 5; ++i)
    {
        V1.push_back(5);
    }
    for (auto i = 0; i < 5; ++i)
    {
        V1.push_front(8);
    }
    //V1.print();
    cout << endl;
    for (auto i = 0; i < 3; ++i)
    {
        V1.pop_front();
    }
    V1.print();

    return 0;
}
