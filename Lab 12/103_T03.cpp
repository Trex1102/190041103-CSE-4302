#include <bits/stdc++.h>
using namespace std;

template<typename T, int n>
class my_stack 
{
private:
    T array[n];
    int totalElements = -1;
public:

    class EmptyStack
    {
    public:
        string msg;
        EmptyStack(string _msg)
        {
            msg = _msg;
        }
    };

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
        if (totalElements != -1)
        {
            T lastElement = array[totalElements];
            totalElements--;
            return lastElement;
        }
        else 
        {
            throw EmptyStack("Cannot pop as Stack is empty");
        }
    }

    T peek()
    {
        return array[0];
    }

};

int main()
{
    try
    {
        my_stack<int, 4> s1;
        cout << s1.pop() << endl;

        my_stack<char, 4> s2;
        cout << s2.pop() << endl;
    }
    catch(my_stack<int,4>::EmptyStack ex)
    {
        cout<<ex.msg<<endl;
    }
    catch(my_stack<char,4>::EmptyStack ex)
    {
        cout<<ex.msg<<endl;
    }
}