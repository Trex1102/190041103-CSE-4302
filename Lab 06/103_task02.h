#pragma once
#include <iostream>

class FLOAT{
private:
	float value;
public:
	FLOAT(float value = 0.0): value(value){}
	~FLOAT(){}
	FLOAT operator + (FLOAT f1);
	FLOAT operator - (FLOAT f1);
	FLOAT operator * (FLOAT f1);
	FLOAT operator / (FLOAT f1);

};