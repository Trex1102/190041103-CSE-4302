#include <iostream>
using namespace std;

namespace standard
{
    int a = 5;
}

namespace my_namespace
{
    int a = 6;
}

int main()
{
    cout<<standard::a<<endl<<my_namespace::a<<endl;
}