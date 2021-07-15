#include <iostream>
#include <math.h>
#include "103_task01.cpp"
#include "103_task02.cpp"
#include "103_task03.cpp"

int main()
{
	Coordinate c1(1,2) , c2(2,1);
	c1.display();
	if(c1 == c2) cout<<"same"<<endl;
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
	a.operator--(x);
	a.getInformation(); 
}