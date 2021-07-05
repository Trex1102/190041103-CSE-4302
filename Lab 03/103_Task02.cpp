#include <iostream>
using namespace std;

class RationalNumber{
private:
	int numerator;
	int denominator;
public:
	void assign(int numerator,int denominator);
	double convert();
	void invert();
	void print();
};

void RationalNumber::assign(int numerator,int denominator){
	if(denominator == 0) {
		cout<< "Error 0 cannot be a denominator\n";
		return;
	}
	this-> numerator = numerator;
	this -> denominator = denominator;
}

double RationalNumber::convert(){
	return (double)this -> numerator / (double)this ->denominator;
}

void RationalNumber::invert() {
	if(numerator == 0) {
		cout<< "Error 0 cannot be a denominator\n";
		return;
	}
	swap(this->denominator , this -> numerator);
}

void RationalNumber::print() {
	cout<<"The Rational Number is "<<this->numerator<<'/'<<this->denominator<<endl;
}

int main() 
{
	RationalNumber a;
	a.assign(5,3);
	a.print();
	cout<<a.convert()<<endl;
	a.invert();
	a.print();
	a.assign(0,5);
	cout<<a.convert()<<endl;
	a.invert();
}