#pragma once
#include <iostream>
class Coordinate{
private:
	float x, y;
public:
	Coordinate(float x= 0 ,float y = 0): x(x), y(y){}
	~Coordinate(){}
	void display () const;
	float getDistance (Coordinate c) const;
	float getDistance () const;
	void move_x(float val);
	void move_y(float val);
	void move(float val);
	bool operator > (Coordinate c);
	bool operator < (Coordinate c);
	bool operator >= (Coordinate c);
	bool operator <= (Coordinate c);
	bool operator == (Coordinate c);
	bool operator != (Coordinate c);
	Coordinate operator ++();
	Coordinate operator ++(int);
	Coordinate operator --();
	Coordinate operator --(int);
};	