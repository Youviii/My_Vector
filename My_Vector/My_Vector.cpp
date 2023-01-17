#include <iostream>
#include "MyVector.h"
using namespace std;

template <class MyType>
void MySwap(MyType& element1, MyType& element2) {
    MyType element3 = element1;
    element1 = element2;
    element2 = element3;
}


int main()
{
    char arr1[5] = { 'a', 'b', 'c', 'd', 'e' };
    char arr2[7] = { 't', 'g', 'd', 'i', 'k', 'y', 'v' };
    int arr3[5] = { 1, 2, 3, 4, 4 };
    //MyVector<char> vec1, vec2, vec3;
    MyVector<int> vec4, vec5, vec6;

    MyVector<int> vec1(arr3, 5), vec2;

    cout << vec1 << endl;

    for (int i = 0; i < 10; i += 1)
    {
        vec4.PushBack(i);
    }
    for (int i = 0; i < 15; i += 1)
    {
        vec5.PushBack(i);
    }
    //vec4 += vec5;
    //vec6 = vec5 + vec4;
    ////MySwap(vec4, vec5);

    //cout << "vec4: " << vec4 << endl;
    //cout << "vec5: " << vec5 << endl;
    //cout << "vec6: " << vec6 << endl;
    //cout << "-----------------------" << endl;

    //cout << "vec4: " << vec4 << endl;
    ////vec5.DeleteIndex(3);
    //cout << "vec5: " << vec5 << endl;
    ////vec6.DeleteAllElem(3);

    //vec6.Insert(0, 5);
    //vec6.Insert(0, 9);
    //vec6.Insert(0, 6);
    //vec6.Insert(0, 15);
    //cout << "vec6: " << vec6 << endl;
    //cout << "-----------------------" << endl;

    vec5 = vec5;
    cout << "vec5: " << vec5 << endl;
}