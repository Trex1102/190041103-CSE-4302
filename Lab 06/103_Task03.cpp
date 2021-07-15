#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class ZooAnimal{
private:
	//string nameofAnimal;
	char nameofAnimal[40];
	int birthYear;
	int cageNumber;
	float weight;
	int height;
public:
	ZooAnimal(int b = 2021 , int c = 0, float w = 0.0, int h = 0)
	: birthYear(b), cageNumber(c), weight(w) , height(h)
	{
		strcpy(nameofAnimal, "");
	}

	char* getnameofAnimal() {
		return nameofAnimal;
	}

	int getbirthYear()const {
		return birthYear;
	}
	int getcageNumber()const {
		return cageNumber;
	}

	float getWeight()const {
		return weight;
	}
	int getheight()const {
		return height;
	}

	void setName(const char *name){
		strcpy(nameofAnimal , name);
	}
	void setBYear(int byear = 2021){
		birthYear= byear;
	}
	void setCageNumber(int x){
		cageNumber = x;
	}
	void setWeight(int x){
		weight= x;
	}
	void setHeight(int x) {
		height = x;
	}

	int getAge(){
		return 2021 - birthYear;
	}

	void getInformation(){
		printf("Name: %s",nameofAnimal);
		cout<<" Birth Year: "<<birthYear<<" Cage Number:"<<cageNumber<<" Weight: "<<weight<<" Height: "<<height<<endl;
	}

	int operator ==(int data){
		if((int) weight == data) return 1;
		else return 0;
	}

		
	void operator --(int dec = 1){
		height -= dec;
	}

	~ZooAnimal(){}

};
