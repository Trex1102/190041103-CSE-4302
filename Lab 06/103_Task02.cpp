#include "103_task02.h"
#include <iostream>
using namespace std;

FLOAT::operator int() const
{
	int x = (int)value;
	return x;
}

void FLOAT::display() const
{
	cout<<value<<endl;
}

FLOAT FLOAT::operator + (FLOAT f1)
{
	return FLOAT(value + f1.value);
}

FLOAT FLOAT:: operator - (FLOAT f1)
{
	return FLOAT(value - f1.value);
}

FLOAT FLOAT:: operator * (FLOAT f1)
{
	return FLOAT(value * f1.value);
}

FLOAT FLOAT:: operator / (FLOAT f1)
{
	if(f1.value == 0) return FLOAT(0.0);
	return FLOAT(value / f1.value);
}

int main()
{
	FLOAT f1(5.3) , f2;
	f1.display(); 
	int x = f1;
	cout<< x;
}