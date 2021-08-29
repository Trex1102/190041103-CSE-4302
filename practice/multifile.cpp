#include <iostream>
using namespace std;

/*
Reason for Multifile Programs:
	1. 	Class Libraries: 
		1. 	Interface
	 	2. 	Implementation: inner workings of the member functions of the various classes don’t need to be
			known by the programmer
			So the source code is not released.
			Rather .obj file or .lib file is distributed
	2. 	Organization and Conceptualization

Inter - file Communication: Cpp files are separately compiled
	-->Distinction between declaration and definition:
		-->Declaration is kind of announcement that this program element is available but
		   how that program element will function is not present in declaration.
 		-->Definition means that how a program element will function.
 		-->Declaration and Definition of
 			Variable
 			Function
			Class

	-->Interfile - Variable:
		int someVar; --> declaration & defination both
		extern int someVar; --> declaration only
	A global variable can be defined in only one place in a program 

	static int a; // in file a
	static int b; // in file b
	it is correct as static global var that each .cpp file has its own copy of the variable

	-->Interfile - Function:
		Same as variables , also same rule for static funciton, it makes invisible to other file
	
	-->Interfile - Class:
		always should be used as defination , forward declaration is used
		-->need of defination: The compiler needs to know the data type of everything that it is compiling
							For classes defination is needed for compiler to know every data type
	
Namespace:
	1. To avoid writing unique identifier name
 	2. Namespace can be declared multiple times
	3. Namespace is normally used in header file

typedef:
	-->Using typedef you can rename any types
 		1. Type of variable
		2. Class name	
*/



int main()
{

}