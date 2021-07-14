#include "103_task02.h"
#include <iostream>
using namespace std;

FLOAT operator + (FLOAT f1)
{
	return FLOAT(value + f1.value);
}

FLOAT operator - (FLOAT f1)
{
	return FLOAT(value - f1.value);
}

FLOAT operator * (FLOAT f1)
{
	return FLOAT(value * f1.value);
}

FLOAT operator / (FLOAT f1)
{
	if(f1.value == 0) return FLOAT(0.0);
	return FLOAT(value / f1.value);
}

int main()
{
	
}