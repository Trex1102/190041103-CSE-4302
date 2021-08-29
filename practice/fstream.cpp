#include <fstream> //file stream
#include <iostream> 
using namespace std;

void output(){ // output to the file inplace of terminal
	string filename;
	cout<<"Enter filename: "; // cout here is an object of ostream class which is declared in iostream header file
	cin>>filename;
	ofstream output (filename+".txt" , ios::app); // creating an object of ofstream class
	// now output & cout are eq in terms of taking output from stream (files, console)
	// cout prints onto the terminal & output prints onto the file
	output << "Hello world"<<endl;
}

void input(){ // input from the file inplace of user
	string filename , line;
	int id;
	int m = 80;
	char buffer[m];
	cout<<"Enter filename: ";
	cin>>filename;
	ifstream input (filename+".txt");
	//using extracting operator

	/*input>>line; // taking the first string 
	cout<<line<<endl; // showing the first string */

	/*while(input.peek()!=EOF){ // input.peek() != EOF is needed to make sure not overwritting is done
		input>>line;
		cout<<line<<endl;
	}*/

	/*while(input.peek()!=EOF){
		input>>id;
		cout<<id<<endl; // we have to maintain the order inorder to extract specific data type
	}*/

	/*while(!input.eof()){
		input.getline(buffer, m);
		cout<<buffer<<endl;
	}
		//The program has no way of knowing in advance how many
		//strings are in the file, so it continues to read one string at a time until it encounters an end-offile.
		//Incidentally, don’t use this program to read random text files. It requires all the text lines
		//to terminate with the ‘\n’ character, and if you encounter a file in which this is not the case,
		//the program will hang.
	*/



}

void input_output(){
	string filename, line;
	char c;
	cout<<"Enter filename: ";
	cin>>filename;
	fstream io(filename+".txt");
	/*while(io.good()){ // until any error occured 
		getline(io, line);
		cout<<line<<endl;
	}*/
}

void char_io(){ // put(), get()
	//ofstream output("a.txt", ios::out);
	string str = "Hello";

	/*for(int i = 0 ; i< str.size(); i++){
		output.put(str[i]);
	}*/

	ifstream input("a.txt", ios::in);
	char ch;

	/*while(input.peek() != EOF){ // this works fine but using input.eof() it gives one extra letter
		input.get(ch);
		cout<<ch;
	}*/

	cout<<input.rdbuf(); // function of ios class // returns the same output
	/*
	This function returns a pointer to the streambuf (or filebuf) object associated with
	the stream object. This object contains a buffer that holds the characters read from the stream,
	so you can use the pointer to it as a data object in its own right.
	*/
	cout<<endl; 

}

void binary_io(){
/*
if you’re storing a large amount
of numerical data it’s more efficient to use binary I/O, in which numbers are stored as they are
in the computer’s RAM memory, rather than as strings of characters:
For example: In binary I/O an int is stored in 4 bytes, whereas its text version might be “12345”, requiring 5 bytes. Similarly, a
float is always stored in 4 bytes, while its formatted version might be “6.02314e13”, requiring
10 bytes.

need to use write() & read()
*/
	int m = 60;
	int buffer[m];
	for(int i =0; i< m; i++)buffer[i]=i;

	ofstream op("edata.dat", ios::binary);
	op.write(reinterpret_cast<char*>(buffer),m*sizeof(int)); // this cast conver one pointer type to another
	op.close();

	for(int i = 0 ; i<m;i++)buffer[i]=0;

	ifstream ip("edata.dat", ios::binary);
	ip.read(reinterpret_cast<char*>(buffer),m*sizeof(int));

	for(int i =0; i< m; i++)cout<<buffer[i]<<' ';
}

// object io

/*class person
{
private:
	int age;
	string name;
public:
	void getData(){
		cout<<"Enter Age: ";cin>>age;
		cout<<"Enter Name: ";cin>>name;
	}
	void showData(){
		cout<<"Age: "<<age<<endl<<"Name: "<<name<<endl;
	}
};*/

/*
It doesn’t matter what member functions you use, since they
are not written to disk along with the object’s data. The data must have the same format, but
inconsistencies in the member functions have no effect. However, this is true only in simple
classes that don’t use virtual functions.

You should also not attempt disk I/O with objects that have pointer data members. As you
might expect, the pointer values won’t be correct when the object is read back into a different
place in memory.


*/

/*

ios::in	Open for input operations.
ios::out	Open for output operations.
ios::binary	Open in binary mode. 
ios::ate	Set the initial position at the end of the file.
If this flag is not set, the initial position is the beginning of the file.
ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

*/

/*
File pointers:
Each file object has associated with it two integer values called the get pointer and the put
pointer. These are also called the current get position and the current put position, or—if it’s
clear which one is meant—simply the current position. These values specify the byte number
in the file where writing or reading will take place. (The term pointer in this context should not
be confused with normal C++ pointers used as address variables.)

The seekg() and tellg() functions allow you to set and
examine the get pointer, and the seekp() and tellp() functions perform these same actions on
the put pointer

--> seekg(bytes from start) --> get to the position
--> seekg(pos1, pos2) --> go to pos1 bytes from pos2
--> tellg() --> find where we are (in bytes)
*/

/*
Error handling in file i/o:
file.eof(), file.good(), file.fail(), file.bad(),
*/
//object the read and write themselves

class person{
private:
	int age;
	string name;
public:
	void getData(){
		cout<<"Enter Age: ";cin>>age;
		cout<<"Enter Name: ";cin>>name;
	}
	void showData(){
		cout<<"Age: "<<age<<endl<<"Name: "<<name<<endl;
	}
	void diskIn(int n){
		ifstream ip("person.dat", ios::binary);
		ip.seekg(n * sizeof(person));
		ip.read((char*)this, sizeof(*this));
	}
	void diskOut(){
		ofstream op ("person.dat", ios::binary|ios::app);
		op.write((char*)this, sizeof(person));
	}

	static int disCount(){
		ifstream ip("person.dat", ios::binary);
		ip.seekg(0, ios::end);
		return (int) ip.tellg()/ sizeof(person);
	}
};

// in the above class to write or read we have to open the same file multiple times which is inefficient
// rather it's better to open the file once --> how to do it
// Static funcitons: gonna need a static pointer array which will hold the pointer
// and static functions which will take input & output


// overload the cin ,cout for a class

class Distance
{
private:
	int x , y;
public:
	friend istream& operator >>(istream& in, Distance& d);
	friend ostream& operator <<(ostream& out, Distance& d);
};

istream& operator >>(istream& in, Distance& d){
	cout<<"Enter X: ";in>>d.x;
	cout<<"Enter Y: ";in>>d.y;
	return in;
}

ostream& operator <<(ostream& out, Distance& d){
	cout<<"X: ";out<<d.x;cout<<endl;
	cout<<"Y: ";out<<d.y;cout<<endl;
	return out;
}

int main()
{
	//output();
	//input();
	//input_output();
	//char_io();
	//binary_io();

	/*
	//single object
	person per;
	per.getData();

	ofstream op ("person.dat" , ios::binary);
	op.write(reinterpret_cast<char*>(&per), sizeof(person)); // char because write & read use it
	op.close();

	ifstream ip ("person.dat" , ios::binary);
	ip.read(reinterpret_cast<char*>(&per), sizeof(person)); // char because write & read use it
	per.showData();
	*/

	//multiple object
	/*
	take input using a single person object multiple time using a loop
	use append
	set the position to first of the file--> file.seekg(0);
	until eof read person data one by one
	*/


	Distance d1;
	cin>>d1;
	cout<<d1;

}