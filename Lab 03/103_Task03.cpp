#include <iostream>
#include <string.h>
using namespace std;

class Product{
private:
	char name[20];
	double discountPercent = .5;
	double unitPrice = 10; 

public:
	void assignName(char name[]);
	void setPrice(double price);
	void setDiscPercent(double percent); 
	double getSellingPrice(int nos); 
	void display(); 
};

void Product::assignName(char name[]){
	strcpy(this->name, name);
}

void Product::setPrice(double price) {
	if(price < 0.0) {
		cout<<"Sorry dear, money can't be negative\n";
		return;
	}

	this-> unitPrice = price;
}

void Product::setDiscPercent(double percent){
	if(percent > 10){
		cout<<"That would be a loss chief, it has to be within 0-10 %\n";
		return;
	}

	this -> discountPercent = percent / 100;
}

double Product::getSellingPrice(int nos){
	double price = (this -> unitPrice) - (unitPrice*discountPercent);
	price *= nos;
	return price;
}

void Product::display() {
	printf("%s has a unit price BDT %lf. Current discount %lf%%\n" , this-> name, this ->unitPrice , this->discountPercent*100 );
}

int main() {
	Product cocola;
	char name[] ="Cocola Noodle";
	cocola.assignName(name);
	cocola.setPrice(15);
	cocola.setDiscPercent(9);
	cocola.display();
	cout<<cocola.getSellingPrice(5);
}