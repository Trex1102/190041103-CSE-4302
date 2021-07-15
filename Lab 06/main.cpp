#include <iostream>
#include <math.h>
#include "103_task01.cpp"
#include "103_task02.cpp"
#include "103_task03.cpp"

int main()
{
	int s = 5 ,b ;
	b = ++s;
	cout<<b<<endl;
	cout<<s<<endl;
	Coordinate c1(1,2) , c2(2,1);
	c1.display();
	if(c1 == c2) cout<<"same"<<endl;
	c2 = c1++;
	c2.display();
	ZooAnimal a;
	a.setName("Alan");
	a.setHeight(9);
	a.setWeight(120.3);
	a.setBYear(2010);
	a.setCageNumber(123);
	a.getInformation();
	cout<<a.getAge()<<endl;
	cout<< (a==120)<<endl;
	int x =5;
	a--;
	a.getInformation(); 
	FLOAT f1(5.052);
	int i = f1;
	cout<<i<<endl;

}