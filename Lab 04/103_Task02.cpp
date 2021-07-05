#include <bits/stdc++.h>
using namespace std;

class BankAccount{
private:
	string account_number;
	string account_holder_name;
	float current_balance;
	string account_type;
	int minimum_balance;
public:
	BankAccount(string an, string ahn, float current_balance , string at, int minimum)
	: account_number(an) , account_holder_name(ahn) , current_balance(current_balance) , account_type(at), minimum_balance(minimum)
	{}

	void setValues(string an, string ahn , float cb , string at, int min){
		account_number = an;
		account_holder_name =ahn;
		current_balance = cb;
		account_type = at;
		minimum_balance = min;
	}
	
	void showInfo(){
		cout << account_number << ' ' << account_holder_name << ' ' << account_type<< ' ' << current_balance << ' '<<endl;
	}

	void showBalance(){
		cout<<current_balance<<endl;
	}

	void deposit(float v){
		current_balance+= v;
	}

	void withdraw(int v){
		int k = current_balance - v;

		if(k < minimum_balance) cout<<"Withdraw Failed"<<endl;
		else current_balance -= v;
	}

	void giveInterest(float i = 2.5){
		float interest = (i / 100) * current_balance;
        float net = interest - (interest * .1);
        deposit(net);
	}

	~BankAccount()
    {
        cout << "Account of " << account_holder_name << " with account no " << account_number << " is destroyed with a balance BDT " << current_balance;
    }
};

int main()
{
	BankAccount b("1234", "Mr.X", 5000, "Current", 500);
	b.showBalance();
	b.showInfo();
	b.withdraw(4500);
	b.giveInterest();
	b.showBalance();
}