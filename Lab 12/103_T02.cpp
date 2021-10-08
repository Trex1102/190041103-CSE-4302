#include <bits/stdc++.h>
using namespace std;

template<typename T>
T amax(T *arr,int size, int n)
{
    T temp[size];
    copy(arr, arr+size, temp);
    sort(temp, temp+size);
    return temp[size-n];
}

int main()
{
    double a[5] = {1.001, 1.02, 1.03, 1.04, 1.05};
    cout<<amax(a, 5, 2)<<endl;

    int b[5] = {1, 2, 3, 4, 5};
    cout<<amax(b, 5, 3)<<endl;
}