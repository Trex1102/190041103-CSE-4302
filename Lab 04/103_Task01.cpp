#include <bits/stdc++.h>
using namespace std;

class Calculator{
private:
	int value;

public:
	Calculator(){
		value = 0;
	}
	Calculator(int value): value(value){}
	
	int getValue() const{
		return value;
	}
	void setValue(int v){
		value = v;
		display();
	}

	void add(int v){
		value += v;
		display();
	}
	void subtract(int v){
		value -= v;
		display();
	}
	void multiply(int v){
		value *= v;
		display();
	}
	void divideBy(int v){
		if(v ==0 ){
			cout<< "Error: divide by 0 is undefined."<<endl;
			display();
			return;
		}

		value /= v;
		display();

	}
	void clear() {
		value = 0;
		display();
	}

	void display() const{
		cout<<"Calculator display: "<<value<<endl;
	}

	~Calculator(){
		cout<<"Calculator object is destroyed\n";
	}

};


int main()
{
	string c ;
	int x;
	Calculator cal;

	while(cin>> c) {
		if(c=="add"){
			cin>> x;
			cal.add(x);
		}
		if(c=="multiply"){
			cin>> x;
			cal.multiply(x);
		}
		if(c=="divideby"){
			cin>> x;
			cal.divideBy(x);
		}
		if(c=="subtract"){
			cin>> x;
			cal.subtract(x);
		}
		if(c=="clear"){
			cal.clear();
			break;
		}
	}


}