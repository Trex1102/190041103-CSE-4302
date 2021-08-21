#include <iostream>
using namespace std;
template <typename T> // template <class t> // function is created on the call 
void print(T x){ // doesn't exist 
	cout<<x<<endl;
}
/*points to be noted:
	1. It doesn't exist on the memory it is only created once we call it
	2. If something is wrong with the function we can't see it unless we call it
*/

template<typename T,int N> // as template gets created on the compile time this class will also 
// get created in the compile time so does the array
class Array
{
private:
	T array[N];
public:
	void printSize(){
		cout<< N;
	}
};

int main()
{
	print("Hello"); // print<int> (4);
	Array<int , 6>array;
	array.printSize();
}