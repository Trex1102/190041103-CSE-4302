#include <iostream>
using namespace std;
// istream is a class in which >> is method so, we can use istream class's >> to overlaod
// using istream class

class Animal{
private:
	int a;
public:
	Animal(int a = 0): a(a){}
	~Animal(){}
	void operator >> (istream& mycin){
		mycin>>a;
	}
	friend void operator<<(Animal& animal , ostream& mycout){
		mycout<<animal.a<<endl;
	}
};

void fucntions(){
	char s[256];
	cin.getline(s, 256); // takes whitespaces as input also
	cout<<cin.gcount()<<endl; // returns the length of the string with extra null char

	
}


int main()
{
	//Animal animal(5);
	//animal >> cin; //  >> (animal , cin)
	//animal << cout; //	<< (animal , cout)

	fucntions();
}