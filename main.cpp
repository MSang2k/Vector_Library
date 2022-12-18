#include <iostream>
#include <my_vector.h>

using namespace std;

int print_element_in_vector(int *V)
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << V[i] << " " ;
    }
    
}
int main()
{
    vector<int> V;

    V.push_pack(9);
    V.push_pack(3);
    V.push_pack(4);
    V.push_pack(6);
    V.push_pack(5);
    V.push_pack(8);
    if(V.empty())
        cout << "A vector is empty" << endl;
    else
        cout << "A vector is not empty" << endl;
    cout << V.size() << endl;
    cout << V.capacity() << endl;
    return 0;
}