#include <iostream>
#include <exception>
using namespace std;

// exception occurs at runtime
/*
Cause:
	running out of memory,
	not being able to open a file,
	trying to initialize an object to an impossible value
	using an out-of-bounds index to a vector.

Why necessary:
	Otherwise we have to check every functions that make the code
	harder to read. Also there may be some leakage which is hard 
	to catch. Lots of extra codes are needed

Exception Syntax: try, catch , throw


-->throw − A program throws an exception when a problem shows up. This is done using a throw keyword.

-->catch − A program catches an exception with an exception handler at the place in a program where you want to handle the problem. The catch keyword indicates the catching of an exception.

-->try − A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks


1. catch will take that input which is thrown
2. catch(...) it will work for any datatype --> Default exception
3. After throw keyword nothing will be run it will directly go to catch block
4. If an exception is thrown and not caught anywhere, the program terminates abnormally
5. A derived class exception should be caught before a base class exception 


	try {
   // protected code
} catch( ExceptionName e1 ) {
   // catch block
} catch( ExceptionName e2 ) {
   // catch block
} catch( ExceptionName eN ) {
   // catch block
}



*/
class Test {
public:
    Test() { cout << "Constructor of Test " << endl; }
    ~Test() { cout << "Destructor of Test " << endl; }
};


double division(int a , int b){
	/*if(b==0){
		throw "Division by zero undefined!";
		cout<<"It will never be executed"<<endl;
	}*/

	return (a/b);
}
// exception using class
class Calculator{
public:
	class DivideByZero{}; // exception class
	double division(int a , int b){
		if(b==0) throw DivideByZero(); // calling exception class
		return (a/b);
	}
};
// exception with arguments
class Distance{
private:
	int data;
public:
	class TooBig{
	public: // it has to be public to be able to access it from outside or we can use get func
		string msg; 
		int data;
	public:
		TooBig(string m, int d){
			msg = m ;
			data = d;
		}
	};

	Distance(){};	
	Distance(int d){
		//exception will be before the assingment
		if(d >= 15){
			throw TooBig("Distance is too big" , d);
		}
		data = d;
	}

	void showDist(){
		cout<<data<<endl;
	}
};



int main(int argc, char const *argv[])
{
	/*try{
		cout<<division(5,0);
	}
	catch(const char* msg){
		cout<<msg<<endl;
	}*/

	/*
	--nested try blocks:
		try{
			try{
				throw 10;		
			}
			catch(...){
				cout<<"Try 1"<<endl;
				throw; // re throwing the exception
			}
		}
		catch(...){
			cout<<"Try 2"<<endl;
		}
	*/

	/*
	When an exception is thrown, all objects created inside the enclosing try block are destructed before the control is transferred to catch block.

	try {
        Test t1;
        throw 10;
    }
    catch (int i) {
        cout << "Caught " << i << endl;
    }
	*/

	// -- exception handling using classes

	/*try{
		Calculator c1;
		cout<<c1.division(4,0);
	}
	catch(Calculator::DivideByZero){
		cout<<"Divide by zero is not allowed"<<endl;
	}
	output - divide by zero is not allowed*/

	// -- exception handling with arguments
	/*
	In three steps:
		1. Specifying data in exception class
		2. Creating an exception obejct
		3. Extracting data from exception object
	*/
	try{
		Distance d1(16);
		d1.showDist();
	}
	catch(Distance::TooBig ex){ // ex is an exception object
		cout<<ex.msg<<endl;
		cout<<"The number was : "<<ex.data<<endl;
	}
	return 0;
}

/*
Exception Notes:
	1. 	Function Nesting: The statement that causes an exception need not be located directly in the try block
	2.	Not for Every Situation: Exceptions should probably
		not be used for user input errors (such as inserting letters into numerical input) that are easily
		detectable by the program. Instead the program should use normal decisions and loops to
		check the user’s input and ask the user to try again if necessary.
	3.	Destructors Called Automatically: When an exception is thrown, a
		destructor is called automatically for any object that was created by the code up to that point in
		the try block. 
	4. 	Handling Exceptions: In other cases you will not want to terminate your program. Perhaps your program can figure
		out what caused the error and correct it, or the user can be asked to input different data. When
		this is the case, the try and catch blocks are typically embedded in a loop, so control can be
		returned to the beginning of the try block (which the exception mechanism has attempted to
		restore to its initial state).
		If there is no exception handler that matches the exception thrown, the program is unceremoniously
		terminated by the operating system.
*/