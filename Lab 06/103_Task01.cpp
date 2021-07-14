#include <iostream>
#include "103_task01.h"
#include <math.h>
using namespace std;

void Coordinate::display() const
{
	cout<<"Abscissa: "<<x<<endl<<"Ordinate: "<<y<<endl;
}

float Coordinate::getDistance (Coordinate c) const
{	
	float res = ((x-c.x)*(x-c.x)) + ((y-c.y) * (y-c.y));
	res = sqrt(res);
	return res;
}

float Coordinate::getDistance () const
{
	float res = (x*x) + (y*y);
	res = sqrt(res);
	return res;
}

void Coordinate::move_x(float val)
{
	x += val;
}

void Coordinate::move_y(float val)
{
	y += val;
}

void Coordinate::move(float val)
{
	move_x(val);
	move_y(val);
}

bool Coordinate::operator > (Coordinate c)
{
	if(x > c.x) return true;
	else return false;
}

bool Coordinate::operator < (Coordinate c)
{
	if(x < c.x) return true;
	else return false;
}

bool Coordinate::operator >= (Coordinate c)
{
	if(x >= c.x) return true;
	else return false;
}

bool Coordinate::operator <= (Coordinate c)
{
	if(x <= c.x) return true;
	else return false;
}
bool Coordinate::operator == (Coordinate c)
{
	//float epsilon = .00000001;
	//if(float(x-c.x) < epsilon) return true;
	//else return false;
	if(x == c.x) return true;
	else return false;
}

bool Coordinate::operator != (Coordinate c)
{
	if(x != c.x) return true;
	else return false;
}

Coordinate Coordinate::operator ++()
{
	return (Coordinate(++x , ++y));
}

Coordinate Coordinate::operator ++(int)
{
	return (Coordinate(++x , ++y));
}
Coordinate Coordinate::operator --()
{
	return (Coordinate(--x , --y));
}

Coordinate Coordinate::operator --(int)
{
	return (Coordinate(--x , --y));
}


int main()
{
	Coordinate a(2.3) , b(2.3);
	if(a==b) cout<<"working";
	else cout<<"not working";
}