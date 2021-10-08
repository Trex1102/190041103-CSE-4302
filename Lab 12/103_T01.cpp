#include <bits/stdc++.h>
using namespace std;

template<typename T, int n>
class my_stack 
{
private:
    T array[n];
    int totalElements = -1;
public:

    bool push(T x)
    {
        if(totalElements >= n)
        {
            cout<<"Maximum Size Limit Reached"<<endl;
            return false;
        }
        else
        {
            totalElements ++;
            array[totalElements] = x;
            return true;
        }
    }

    T pop()
    {
        if (totalElements != 0)
        {
            T lastElement = array[totalElements];
            totalElements--;
            return lastElement;
        }
        else 
        {
            cout<<"No elements in the stack"<<endl;
        }
    }

    T peek()
    {
        return array[0];
    }

};

int main()
{
    my_stack<int, 4> s1;
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    cout<<s1.pop()<<endl;
    cout<<s1.peek()<<endl;

    my_stack<char, 4>s2;
    s2.push('A');
    s2.push('B');
    s2.push('C');
    s2.push('D');
    cout<<s2.pop()<<endl;
    cout<<s2.peek()<<endl;
}