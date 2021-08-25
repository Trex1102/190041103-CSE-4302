#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int fuel ;
    string owner_name, vehicle_number, company;
protected:
    int getFuel() const{return fuel;}	
    string getOwnerName()const{return owner_name;}
    string getVehicleNumber()const{return vehicle_number;}
    void showInfo()const{
    	cout<<"Vehicle Number: "<<vehicle_number<<endl;
    	cout<<"Owner Name:" <<owner_name<<endl;
    	cout<<"Company: "<<company<<endl;
    	cout<<"Fuel :"<<fuel<<" Litre"<<endl;
    }
    void setFuel(int x){fuel = x;}
    void setOwnerName(string name){owner_name=name;}
    void setVehicleNumber(string vn){vehicle_number = vn;}
public:
    Vehicle(int f=0, string on="Not inserted", string vn="Not inserted" , string comp = "Not inserted")
    : fuel(f) , owner_name(on) , vehicle_number(vn), company(comp)
    {

    }
    ~Vehicle(){}
    void virtual drive()= 0 ; // pure virtual function
    void virtual info() = 0 ; // putre virtual function
};

class Car:protected Vehicle
{
private:
	int year;
protected:
public:
	Car(int f=0, string on="Not inserted", string vn="Not inserted" , string comp ="Not inserted", int year = 2020)
    : Vehicle(f,on,vn, comp) , year(year)
    {

    }
    ~Car(){}

	void drive(){
		cout<<": Driving Car needs focus"<<endl;
	} 

	void info(){
		cout<<"--------------------"<<endl;
		cout<<"Vehicle Type: Car"<<endl;
		Vehicle::showInfo();
		cout<<"Release Year: "<<year<<endl;
	}
};

class Bike:protected Vehicle
{
private:
	int version;
protected:
public:
	Bike(int f=0, string on="Not inserted", string vn="Not inserted" , string comp ="Not inserted", int version = 1)
    : Vehicle(f,on,vn, comp) , version(version)
    {

    }
    ~Bike(){}

	void drive(){
		cout<<": Driving Bike needs skills"<<endl;
	}

	void info(){
		cout<<"--------------------"<<endl;
		cout<<"Vehicle Type: Bike"<<endl;
		Vehicle::showInfo();
		cout<<"Version: "<<version<<endl;
	}
};

class Animal
{
public:
    Animal(){}
    ~Animal(){}
	void virtual sound()= 0 ;
    void virtual info(){
        cout<<"This is an animal"<<endl;
    }
    void virtual lifespan()= 0 ;
};

class Dog:public Animal
{
public:
    Dog(){}
    ~Dog(){}
    void sound(){
        cout<<"Bark Bark !!"<<endl;
    }
    void info(){cout<<"This is a dog"<<endl;}
    void lifespan(){
        cout<<"10-12 years"<<endl;
    }
};

class Cat:public Animal
{
public:
    Cat(){}
    ~Cat(){}
    void sound(){
        cout<<"Meaw Meaw !!"<<endl;
    }
    //void info(){cout<<"This is a cat"<<endl;}
    void lifespan(){
        cout<<"6-8 years"<<endl;
    }
};
class Bat:public Animal
{

};

class Entity
{
public:
    void virtual show(){cout<<"This is an entity"<<endl;}
};

class Hero : public Entity
{  
};


int main()
{
	Car c1(10 , "Jawed Riddhi" , "DHAKAGA1043" , "BMW" , 2006);
	c1.info();
	c1.drive();
	Bike b1(10, "Alif Arshad" ,"DHAKAGA1044" , "Yamaha", 2013);
	b1.info();
	b1.drive();
    cout<<"--------------------"<<endl;
    Animal *a = new Dog;
    a->info();
    a->lifespan();
    a->sound();
    a = new Cat;
    a->info();
    a->lifespan();
    a->sound(); // accessing bcz virutal
    //Animal b; // compile error
    //Bat b; // compile error
    Entity e;
    Hero h;
}