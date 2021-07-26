#include <iostream>
#include <fstream> // file stream
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

	/*cin.getline(s, 256); // takes whitespaces as input also
	cout<<cin.gcount()<<endl; // returns the length of the string with extra null char

	cin.get(s,256); // char by char return ... same as c gets
	cout<<s;*/

	/*char first, last;
	first = cin.get(); // to get the first inputted character
	cin.ignore(256, 'a'); // ignore until 'a' character
	last = cin.get();
	cout<<first<<' '<<last<<endl;*/

	/*cin.read(s, 10); // we have to enter at lease 9 or 10 letters to stop the input
	//cout<<s<<endl;
	cout.write(s, 10); // write the whole string up to 10 character , read & write works together
	cout.put('x'); // puts a single character on the screen*/

	


}


int main()
{
	//Animal animal(5);
	//animal >> cin; //  >> (animal , cin)
	//animal << cout; //	<< (animal , cout)

	fucntions();
}