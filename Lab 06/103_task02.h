#pragma once
#include <iostream>

class FLOAT{
private:
	float value;
public:
	FLOAT(float value = 0.0): value(value){}
	~FLOAT(){}
	void display() const;
	FLOAT operator + (FLOAT f1);
	FLOAT operator - (FLOAT f1);
	FLOAT operator * (FLOAT f1);
	FLOAT operator / (FLOAT f1);
	operator int() const;
};