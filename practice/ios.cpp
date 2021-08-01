#include <iostream> // input output stream header
#include <iomanip> // manipulator header
#include <vector>
using namespace std;

void display(vector<int> v){
	for(auto i : v)cout<<i<<' ';
	cout<<endl;
}

void display(int a[] , int s){
	for(int i =0 ; i< s; i++) cout<<a[i]<<' ';
	cout<<endl;
}


// ios class
void _width(){
	cout.width(5); // fill the width of a's output with 5's spaces
	char c ='A';
	cout<< c <<"\n";
}

void _precision(){
	cout.precision(5);
	cout<<3.1412;
}

void _fill(){
	char c = 'A';
	cout.fill('*');
	cout.width(5);
	cout<<c;
}

void _setf(){ // will show +100, +200
	int val1=100,val2=200;
    cout.setf(ios::showpos); // showpos --> show positive
    cout<<val1<<" "<<val2<<endl;
    cout.unsetf(ios::showpos);
}

void _unsetf(){
	cout.setf(ios::showpos|ios::showpoint); // set flag
    cout.unsetf(ios::showpos); 
    cout<<200.0;
}

void independent_flags(){
	bool flag = true;
	cout<<"Working of boolalpha:"<<endl;
	cout<<boolalpha<<flag<<endl; // in the place of 1 it will show true
	cout<<noboolalpha<<flag<<endl; // it will show 1

	int n = 20;
	cout<<"Working of showbase:"<<endl;
	//cout<<oct<<noshowbase<<20<<endl; // show pos will not work when oct & hex is on
	//cout<<hex<<noshowbase<<20<<endl;
	cout.unsetf(ios::showbase);

	double a = 30;
	cout<<"Working of showpoint:"<<endl;
	cout.precision(5);
	cout<<showpoint<<a<<endl;
	cout<<noshowpoint<<a<<endl;

	int b = 5;
	cout<<"Working of showpos:"<<endl;
	cout<<showpos<<b<<endl;
	cout.unsetf(ios::showpos);

	//cout<<"Working of uppercase:"<<endl;


}

void adjust_flag(){
	int n = 300;
	cout.width(5);
	cout.fill('*');
	cout<<internal<<n<<endl;
	cout.width(5);
	cout.fill('*');
	cout<<left<<n<<endl;
	cout.width(5);
	cout.fill('*');
	cout<<right<<n<<endl;
	cout.unsetf(ios::right);
}

// we can set any of the flag with cout.setf(ios::flag1|ios::flag2)

void manipulators(){
	char a[256] , b[256];
	//cin>>ws; // this indicates all the whitespaces will be ignored upto the input
	//cin.getline(a,256); // getline gets the whole line after the space also
	//cin>>ws; // eat up the whitespaces
	//cin.getline(b,256);
	//cout<<a<<' '<<b<<endl;
	//this will ignore all the spaces which will be entered after the cin>>ws is called
	// until another cin is called

	cout<<"saikat"<<ends<<"saikat"<<endl; // ends add a null character

	cout<<setbase(8); // same as cout.setf(ios::hex)
	cout<<110<<endl;
	cout.setf(ios::hex);
	cout<<setfill('x')<<setw(5);
	cout<<77<<endl;

	double c = 60.345668;
	cout<<setprecision(5)<<c<<endl;
}

void ios_function(){
	vector<int> v(4);
	fill(v.begin(), v.end(), 3); // fills all the characters as the second arg
	//display(v); // to display the values

	char f = cout.fill();
	cout<<f<<endl;
	// to get the fill character
	// be aware these two fill is totally different

	int p = cout.precision();
	cout<<p<<endl;
	// to get the precision margin

	int w = cout.width(); 
	cout<<w<<endl;

	// setf(flag, field)
}

void showflags(){

}

int main()
{
	// c++ i/o flags
	// format flags
	// cout.flags(ios::hex|ios::showbase)
	// cout.setiosflags(ios::hex|ios::showbase)
	//cout<<resetiosflags(ios::hex|ios::showbase);
	showflags();
	independent_flags();
	_setf();
	adjust_flag();
	manipulators();
	ios_function();
}