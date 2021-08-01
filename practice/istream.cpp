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

	cin.get(s,256); // char by char return ... same as c gets, won't work without size
	cout<<s;*/

	/*char first, last;
	first = cin.get(); // to get the first inputted character
	cin.ignore(256, 'a'); // don't take input until 'a' character
	last = cin.get();
	cout<<first<<' '<<last<<endl;*/

	/*cin.read(s, 10); // we have to enter at lease 9 or 10 letters to stop the input
	//cout<<s<<endl;
	cout.write(s, 10); // write the whole string up to 10 character , read & write works together
	cout.put('x'); // puts a single character on the screen*/

	
	//cin.getline(s,12,'\n'); // takes input until '\n' is found and 12 characters are being scanned

	string str;
	//getline(cin, str); // for string type
	//cin.getline(str); // will not work for string type , only works for array of char


}

void putback(){
	cout<<"please enter a number or a word: ";
	char c = cin.get();

	if((c >= '0') && (c <= '9')){
		int n ;
		cin.putback(c); // send the c to the input streams once again
		cin>>n; // from the input stram take the same c as an number again
		cout<<"you entered an number: " <<n<<endl;
	}
	else {
		string s;
		cin.putback(c);
		getline(cin , s); // if s is string type then getline will work like this
		cout<<"you entered a word: "<<s<<endl;
	}
}

int peek(){
	cout << "Please, enter a number or a word: ";
  	cout.flush();    // ensure output is written

	cin >> ws;  // eat up any leading white spaces
  	int c = cin.peek();  // peek character but don't extract or take from input stream

  	if ( c == EOF ) return 1;
  	if ( isdigit(c) )
  	{
    	int n;
    	cin >> n;
    	cout << "You entered the number: " << n << '\n';
  	}
  	else
  	{
    	string str;
    	cin >> str;
    	cout << "You entered the word: " << str << '\n';
  	}

  	return 0;
}



int main()
{
	//Animal animal(5);
	//animal >> cin; //  >> (animal , cin)
	//animal << cout; //	<< (animal , cout)

	//fucntions();
	//putback();
	peek();
}