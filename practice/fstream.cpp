#include <fstream>
#include <iostream>
using namespace std;


void output(){ // output to the file inplace of terminal
	string filename;
	cout<<"Enter filename: "; // cout here is an object of ostream class which is declared in iostream header file
	cin>>filename;
	ofstream output (filename , ios::app); // creating an object of ofstream class
	// now output & cout are eq in terms of taking output from stream (files, console)
	// cout prints onto the terminal & output prints onto the file
	output << "Hello world"<<endl;
	output.close();
}

void input(){ // input from the file inplace of user
	string filename , line;
	cout<<"Enter filename: ";
	cin>>filename;
	ifstream input (filename);

	while(input){
		getline(input, line); 
		cout<<line<<endl;
	}

	input.close();
}

void modes(){
	
}

int main()
{
	//output();
	//input();
}