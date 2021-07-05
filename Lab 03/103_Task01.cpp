#include <iostream>
using namespace std;
// checking git
class Counter {
private:
	int count = 0;
	int step_val = 0 ;
public:
	int getCount();
	void increment();
	void setIncrementStep(int step_val);
	void resetCount();
};

int Counter::getCount(){
	return this->count;
}

void Counter::increment() {
	this->count += this-> step_val;
}

void Counter:: setIncrementStep(int step_val){
	this -> step_val = step_val;
}
void Counter:: resetCount(){
	this-> count = 0;
}

int main()
{
	Counter c;
	c.setIncrementStep(5);
	c.increment();
	c.increment();
	c.resetCount();
	c.increment();
	cout<<c.getCount();
}