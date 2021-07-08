#include <bits/stdc++.h>
using namespace std;

class Animal
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

class Dog : public Animal{
private:
	int x;
public:
	Dog(int x):Animal(x), x(x){}
	//void getx(){cout<<x<<endl;}
	void eat(){cout<<"Dog eating"<<endl;}
	void bark(){cout<<"Dog barking"<<endl;}
};
int main()
{
	Animal a(4);
	//Dog d2(3);
	Dog *d;

	d = new Dog(5);
	//d->setx(5);
	//d2.eat();
	d->eat();
	//setx(5 , a);
	d->getx();
	//d->getx();
	//a.getx();
}