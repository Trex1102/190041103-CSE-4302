#include <iostream>
using namespace std;

class base
{
private:
    int data;
public:
    base(){}
    base(int _data){
        data = _data;
    }
    void display(){cout<<data<<endl;}
    base operator = (base & x){
        this->data = x.data;
        cout<<"\nAssignment operator"<<endl;
        return *this;
    }
    ~base(){}
};

class magma
{
private:
    int* add;
public:
    magma(){}
    magma(int *x){
        add =x;
    }
    void display(){
        cout<<*add<<endl;
        cout<<add<<endl;
    }
    /*magma operator=(magma &x){
        add = new int;
        *(add) = *(x.add);
        return *this;
    }
    magma(magma &x){
        add = new int;
        *(add) = *(x.add);
    }*/
private:
    //magma operator = (magma &x);
    //magma (magma &x);
};

int main()
{
    base b1(3);
    base b2;
    b2 = b1; // assignment operator
    b2.display();
    base b3 = b2; // copy initialization  
    //base b3(b2); // copy initialization
    b3.display();
    ///////////////////////////////////////////
    int n = 5;
    magma m1(&n);
    m1.display();
    magma m2;
    m2 = m1;
    m2.display();
    magma m3(m2);
    m3.display();
}