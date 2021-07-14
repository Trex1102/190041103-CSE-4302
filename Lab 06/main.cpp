#include <iostream>
#include <math.h>
#include "103_task01.cpp"
#include "103_task02.cpp"

int main()
{
	Coordinate c1(1,2) , c2(2,1);
	c1.display();
	if(c1 == c2) cout<<"same"<<endl; 
}