#include <bits/stdc++.h>
using namespace std;

class Animal // base class
{
private:
	int x;
public:
	Animal(int x):x(x){}
	friend void setx(int y, Animal &a);
	//void setx(int y) {x = y;}
	void getx(){cout<<x<<endl;}
	void eat(){cout<<"Animal eating"<<endl;}
	void sleep(){cout<<"Animal sleeping"<<endl;}
};

void setx(int y,Animal &a) {
	a.x = y;
}

class Dog : public Animal{ // derived class with access specifier
private:
	int x;
public:
	Dog(int x):Animal(x), x(x){}
	//void getx(){cout<<x<<endl;}
	void eat(){ // overridding
		Animal::eat(); // calling base class function using scope resulation operator
		cout<<"Dog eating"<<endl;
	}
	void bark(){cout<<"Dog barking"<<endl;}
};

//multiple inheritance

class A{
	int a;
public:
	A(int a = 0):a(a){}
	~A(){}
	int geta(){return a;}
	void seta(int x){a=x;}
	void bubla(){cout<<"Class A bubla";}
};

class B{
	int a;
public:
	B(int a=0):a(a){}
	~B(){}
	int geta(){return a;}
	void seta(int x){a=x;}
	void bubla(){cout<<"Class B bubla";}
};

class C: public A, public B{
	int a;
public:
	C(int a=0):a(a){}
	~C(){}
	int geta(){return a;}
	void seta(int x){a=x;}
};

//diamond shape problem


int main()
{
	
	C a;
	a.B::bubla(); // multiple inheritance


}