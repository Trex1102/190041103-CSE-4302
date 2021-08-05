#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account{
private:
	string accountNo; // will be generated from it's respective account type
	string accountName; // prompt user to input his name which will be used here
	float balance; // depends on the account type
public: 
	Account(){
		
	}

	~Account(){}

	string get_accountName ()const{
		return accountName;
	}

	string get_accountNo ()const{
		return accountNo;
	}

	float get_balance ()const{
		return balance;
	}

	void set_accountName (string account_Name){
		accountName =  account_Name;
	}

	void set_accountNo (string account_No){
		accountNo =  account_No;
	}

	void set_balance(float _balance){
		balance = _balance;
	}
	void description() const{
		cout<<endl<<"Welcome to YMMY Bank"<<endl;
	}

};

//current class

class Current: public Account{ 
private:
	const static int serviceCharge =100;
	const static int accountPrefix = 100;
	static int nextAccount;
	void nextAccountNo(){ // increases next account no by 1
		nextAccount++;
	}
public:
	Current(string name= "" , float _balance = 0){ // sets all the var of base class & further more
		Account::set_accountName(name); 
		Account::set_accountNo(to_string(accountPrefix) + to_string(nextAccount)); // setting the account no from base class
		nextAccountNo(); // increasing the account value by 1
		Account::set_balance(_balance);
		Account::description(); // function overriding
		description(); // gives the details of the account
	}

	~Current(){
		nextAccount --;
	}
	int get_serviceCharge()const {return serviceCharge;}
	int get_accountPrefix()const  {return accountPrefix;}
	int get_nextAccount() const{
		return nextAccount;
	}

	void set_nextAccount(int _nextAccount){
		nextAccount = _nextAccount;
	}

	void description() const{
		cout<<"Initial deposit: "<<Account::get_balance()<<endl;
		cout<<"Your Current Account is being created\nAccount Name: "<<Account::get_accountName()<<endl<<"Account Number: "<<Account::get_accountNo()<<endl<<"Current Balance: "<<Account::get_balance()<<endl<<"You can withdraw your money any time\nThanks for staying with YMMY Bank\n";
	} // showing the current account status & description
};

//saving class

class Savings:public Account{  
private:
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 200;
	static int nextAccount;
	void nextAccountNo(){ // increase the next account no by 1
		nextAccount++;
	}
public:
	Savings(string name = "",float interestRate = 3, float monthlyDepositAmount = 500 , float _balance = 0):interestRate(interestRate),monthlyDepositAmount(monthlyDepositAmount){
		Account::set_accountName(name);
		Account::set_accountNo(to_string(accountPrefix) + to_string(nextAccount)); // setting the account no from base class
		nextAccountNo(); // increasing the account value by 1
		Account::set_balance(_balance);
		Account::description();
		description();
	}
	~Savings(){}

	int get_accountPrefix(){return accountPrefix;}
	float get_interestRate()const{
		return interestRate;
	}

	float get_monthlyDepositAmount() const{
		return monthlyDepositAmount;
	}
	int get_nextAccount() const{
		return nextAccount;
	}

	void set_interestRate(float _interestRate){
		interestRate = _interestRate;
	}

	void set_monthlyDepositAmount(float _monthlyDepositAmount){
		monthlyDepositAmount = _monthlyDepositAmount;
	}

	void description() const{
		cout<<"Initial deposit: "<<Account::get_balance()<<endl;
		cout<<"Your Savings Account is being created\nAccount Name: "<<Account::get_accountName()<<endl<<"Account Number: "<<Account::get_accountNo()<<endl<<"Current Balance: "<<Account::get_balance()<<endl<<"You need to deposit: "<<monthlyDepositAmount<<" Each month to earn "<<interestRate<<"%"<<" interest.\nYou can withdraw your money any time\nThanks for staying with YMMY Bank\n";
	} // showing the current account status & description
};

//monthly Deposit scheme

class MonthlyDepositScheme:public Account{
private:
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 300;
	static int nextAccount;

protected:
	void nextAccountNo(){
		nextAccount++;
	}
public:
	MonthlyDepositScheme(){}
	~MonthlyDepositScheme(){}

	int get_accountPrefix(){return accountPrefix;}
	float get_interestRate()const{
		return interestRate;
	}

	float get_monthlyDepositAmount() const{
		return monthlyDepositAmount;
	}
	int get_nextAccount() const{
		return nextAccount;
	}

	void set_interestRate(float _interestRate){
		interestRate = _interestRate;
	}

	void set_monthlyDepositAmount(float _monthlyDepositAmount){
		monthlyDepositAmount = _monthlyDepositAmount;
	}

	void description() const{
		Account::description();
		cout<<"Monthly Deposit Scheme. You have to pay A fixed amount every month\n";
	}

};

//loan

class Loan:public Account{
private:
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 900;
	static int nextAccount;
	void nextAccountNo(){
		nextAccount++;
	}
public:
	Loan(string name = "",float interestRate = 4 , float monthlyDepositAmount = 1500 , float _balance = 0):interestRate(interestRate),monthlyDepositAmount(monthlyDepositAmount){
		Account::set_accountName(name);
		Account::set_accountNo(to_string(accountPrefix) + to_string(nextAccount)); // setting the account no from base class
		nextAccountNo(); // increasing the account value by 1
		Account::set_balance(_balance);
		Account::description();
		description();

	}
	~Loan(){}

	int get_accountPrefix()const {return accountPrefix;}
	float get_interestRate()const{
		return interestRate;
	}

	float get_monthlyDepositAmount() const{
		return monthlyDepositAmount;
	}
	int get_nextAccount() const{
		return nextAccount;
	}

	void set_interestRate(float _interestRate){
		interestRate = _interestRate;
	}

	void set_monthlyDepositAmount(float _monthlyDepositAmount){
		monthlyDepositAmount = _monthlyDepositAmount;
	}

	void description() const{
		cout<<"Your Loan Account is being created\nAccount Name: "<<Account::get_accountName()<<endl<<"Account Number: "<<Account::get_accountNo()<<endl<<"Current Loan Amount: "<<Account::get_balance()<<endl<<"You need to pay atleast "<<monthlyDepositAmount<<" every month to avoid "<<interestRate<<'%'<<" interest\nThanks for staying with YMMY Bank\n";
	}
};

//TWO years MDS

class TwoYearMDS: public MonthlyDepositScheme{
private:
	float maximuminterest; 

public:
	TwoYearMDS(string name ="" , float interestRate= 5, float monthlyDepositAmount = 500, float maximuminterest = 10 , float _balance = 500 ):maximuminterest(maximuminterest){
		Account::set_accountName(name); // sets the acc name
		Account::set_balance(_balance); 
		string prefix = to_string(MonthlyDepositScheme::get_accountPrefix() ), nextAccount = to_string(MonthlyDepositScheme::get_nextAccount()); // as we can't access derived class from base class
		Account::set_accountNo(prefix + nextAccount); // setting the account no from base class
		MonthlyDepositScheme::nextAccountNo(); // increasing the account value by 1
		MonthlyDepositScheme::set_interestRate(interestRate); // setting monthly deposite scheme's interestrate
		MonthlyDepositScheme::set_monthlyDepositAmount(monthlyDepositAmount); // setting monthly deposite scheme's deposite amount
		MonthlyDepositScheme::description();
		description();
	}

	float get_maximuminterest(){
		return maximuminterest;
	}

	void set_maximuminterest(float _maximuminterest){
		_maximuminterest = maximuminterest;
	}

	void description() const{
		cout<<"Your Two Year Monthly Deposit Scheme Account is being created\nAccount Name: "<<Account::get_accountName()<<endl<<"Account Number: "<<Account::get_accountNo()<<endl<<"Current Balance: "<<Account::get_balance()<<endl<<"You need to deposit atleast "<<MonthlyDepositScheme::get_monthlyDepositAmount()<<" every month to get "<<MonthlyDepositScheme::get_interestRate()<<'%'<<" interest\n"<<"If you don't close within 2 years you will get maximum "<<maximuminterest<<"% "<<"interest\nThanks for staying with YMMY Bank\n";
	}
};

//Five year

class FiveYearMDS: public MonthlyDepositScheme{
private:
	float maximuminterest;

public:
	FiveYearMDS(string name ="" , float interestRate= 5, float monthlyDepositAmount = 1500, float maximuminterest = 12 , float _balance = 500 ):maximuminterest(maximuminterest){
		Account::set_accountName(name);
		Account::set_balance(_balance);
		string prefix = to_string(MonthlyDepositScheme::get_accountPrefix() ), nextAccount = to_string(MonthlyDepositScheme::get_nextAccount()); 
		Account::set_accountNo(prefix + nextAccount); // setting the account no from base class
		MonthlyDepositScheme::nextAccountNo(); // increasing the account value by 1
		MonthlyDepositScheme::set_interestRate(interestRate);
		MonthlyDepositScheme::set_monthlyDepositAmount(monthlyDepositAmount);
		MonthlyDepositScheme::description();
		description();
	}

	void set_maximuminterest(float _maximuminterest){
		_maximuminterest = maximuminterest;
	}

	void description() const{
		cout<<"Your Five Year Monthly Deposit Scheme Account is being created\nAccount Name: "<<Account::get_accountName()<<endl<<"Account Number: "<<Account::get_accountNo()<<endl<<"Current Balance: "<<Account::get_balance()<<endl<<"You need to deposit atleast "<<MonthlyDepositScheme::get_monthlyDepositAmount()<<" every month to get "<<MonthlyDepositScheme::get_interestRate()<<'%'<<" interest\n"<<"If you don't close within 5 years you will get maximum "<<maximuminterest<<"% "<<"interest\nThanks for staying with YMMY Bank\n";
	}
};

//initial dep

class InitialDepositMDS: public MonthlyDepositScheme{
private:
	float maximuminterest;
	float initialDepositAmount;

public:

	InitialDepositMDS(string name ="" , float interestRate= 5, float monthlyDepositAmount = 1500, float maximuminterest = 6 , float _balance = 500 ):maximuminterest(maximuminterest){
		Account::set_accountName(name);
		Account::set_balance(_balance);
		string prefix = to_string(MonthlyDepositScheme::get_accountPrefix() ), nextAccount = to_string(MonthlyDepositScheme::get_nextAccount()); 
		Account::set_accountNo(prefix + nextAccount); // setting the account no from base class
		MonthlyDepositScheme::nextAccountNo(); // increasing the account value by 1
		MonthlyDepositScheme::set_interestRate(interestRate);
		MonthlyDepositScheme::set_monthlyDepositAmount(monthlyDepositAmount);
		MonthlyDepositScheme::description();
		description();
	}

	float get_maximuminterest() const{
		return maximuminterest;
	}

	void set_maximuminterest(float _maximuminterest){
		_maximuminterest = maximuminterest;
	}

	float get_initialDepositAmount() const{
		return initialDepositAmount;
	}

	void set_initialDepositAmount(float _initialDepositAmount){
		initialDepositAmount = _initialDepositAmount;
	}

	void description() const{
		cout<<"Your Initial Deposit Scheme Account is being created\nAccount Name: "<<Account::get_accountName()<<endl<<"Account Number: "<<Account::get_accountNo()<<endl<<"Current Balance: "<<Account::get_balance()<<endl<<"You need to deposit atleast "<<MonthlyDepositScheme::get_monthlyDepositAmount()<<" every month to get "<<MonthlyDepositScheme::get_interestRate()<<'%'<<" interest\n"<<"If you don't close within 2 years you will get maximum "<<maximuminterest<<"% "<<"interest\nThanks for staying with YMMY Bank\n";
	}
};


