#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[20];
    set <int> s;
    int j=0;
    for(int i=0;i<10;i++)
    {
        if(i%2==1)
            s.insert(i);
        else
        {
            arr[j]=i;
            j++;
        }
    }

    vector <int> v(10);
    merge(arr, arr+5, s.begin(), s.end(), v.begin());
    
    for(auto i = v.begin(); i!= v.end(); i++)
    {
        cout<<*i<<endl;
    }

    return 0;
}