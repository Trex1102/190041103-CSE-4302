#include <iostream>
#include <ostream>
#include <thread>
#include <chrono>
using namespace std;

// for flush - https://www.geeksforgeeks.org/buffer-flush-means-c/

void functions(){
	char c = 'a';
	cout<<"printing a\n";
	cout.flush(); // ensure cout is written as it outputs from buffer directly
	cout.put(c); // put c on the console
}

int main()
{
	functions();
}