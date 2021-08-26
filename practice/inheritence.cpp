#include <bits/stdc++.h>
using namespace std;

class Animal // base class
{
private:
	int x;
public:
	Animal(int x= 0):x(x){}
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
	Dog(int x= 0):Animal(x), x(x){} // if base class has constructor it has to be filled first
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
	void bubla(){cout<<"Class B bubla"<<endl;}
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

class ONE{
public:
	void foo(){cout<<"ONE FOO"<<endl;}
};

class TWO: virtual public ONE{ // virtual defines it will only call once
};

class THREE:virtual public ONE{ 
};

class FOUR: public TWO, public THREE{
};

// diamond shape problem: B --> A, C --> A , D --> B,C

// abstract base class
// it corresponds an abstract concept
// at programming level ABC is a class that works as an interface, it has one or more
// pure virtual functions & there will be no instances of ABC
class Shape{
public:
	virtual void draw() const = 0; // pure virtual function --> it indicates the derived
	// class must have this attribute
};

class Circle: public Shape{
public:
	virtual void draw() const {cout<<"This is circle"<<endl;}
};


//when to use:
// to make a body of the project

//pointer to derived class
class Base{
public:
	int base_var;

	virtual void display(){
		cout<<"This is Base class"<<endl;
		cout<<"Base Var: "<<base_var<<endl; 
	}

	void test(){cout<<"testing"<<endl;}
};

class Derived:public Base{
public:
	int derived_var;

	void display(){
		cout<<"This is Derived Class"<<endl;
		cout<<"Derived Var: "<<derived_var<<endl;
		//cout<<"Base Var: "<<base_var<<endl; 
	}

	void hello(){
		cout<<"hello base"<<endl;
	}
};

//virtual function: polymorphism
// 1. A virtual function is a member function which is declared within a base class and is re-
// defined(Overriden) by a derived class. When you refer to a derived class object using a pointer or a
// reference to the base class, you can call a virtual function for that object and execute the derived
// class’s version of the function.

// 1. virtual function ensures the correct function is called regerdless of the pointer
// 2. used to achieve runtime polymorphism --> non virtual compile time
// 3. declared with virtual keyword
// 4. cannot be static
// 5. can be a friend function to another class
// 6. should be accessed using pointer or reference of base class to acheive runtime 
// polymorphism
// 7. prototype should be same
// 8. may have virtual destructor
// 9. always defiend in the base class 


// passing array of objects





int main()
{
	
	C a; // multiplel inheritance
	a.B::bubla(); // multiple inheritance

	FOUR b; // diamond shape problem
	b.foo(); // diamond shape problem


	Circle circle; // abstract class
	circle.draw(); // pure virtual function
	cout<<"new"<<endl;

	Base *base;
	Derived *derived;
	base = new Derived; // derived = base + something new
	base->base_var = 5;
	base ->display(); // showing the derived display --> 
	base -> test();
	base -> hello();
	derived = new Derived;
	derived ->base_var = 6; // calling base class var from derived class pointer
	derived ->derived_var = 7;
	derived -> display();
	derived -> test(); // calling base class function from derived class pointer

	//conclusion : 
	// A pointer to derived class is a pointer of base class pointing to derived class, but it will hold its aspect.
	// This pointer of base class will be able to temper functions and variables of its own class and can still point to derived class object.

	Base* bass = new Base;
	bass->base_var = 10;
	bass -> display();


}