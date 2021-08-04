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



};

//current class

class Current: public Account{ // done
private:
	const static int serviceCharge =100;
	const static int accountPrefix = 100;
	static int nextAccount;
	void nextAccountNo(){
		nextAccount++;
	}
public:
	Current(string name= "" , float _balance = 0){ // sets all the var of base class & further more
		Account::set_accountName(name);
		Account::set_accountNo(to_string(accountPrefix) + to_string(nextAccount)); // setting the account no from base class
		nextAccountNo(); // increasing the account value by 1
		Account::set_balance(_balance);
		description();
	}

	~Current(){
		nextAccount --;
	}
	int get_serviceCharge(){return serviceCharge;}
	int get_accountPrefix(){return accountPrefix;}
	int get_nextAccount() const{
		return nextAccount;
	}

	void set_nextAccount(int _nextAccount){
		nextAccount = _nextAccount;
	}

	void description(){
		cout<<endl;
		cout<<"Initial deposit: "<<Account::get_balance()<<endl;
		cout<<"Your Current Account is being created\nAccount Name: "<<Account::get_accountName()<<endl<<"Account Number: "<<Account::get_accountNo()<<endl<<"Current Balance: "<<Account::get_balance()<<endl<<"You can withdraw your money any time\nThanks for staying with YMMY Bank\n";
	} // showing the current account status & description
};

//saving class

class Savings:public Account{  // done
private:
	float interestRate;
	float monthlyDepositAmount;
	const static int accountPrefix = 200;
	static int nextAccount;
	void nextAccountNo(){
		nextAccount++;
	}
public:
	Savings(string name = "",float interestRate = 3, float monthlyDepositAmount = 500 , float _balance = 0):interestRate(interestRate),monthlyDepositAmount(monthlyDepositAmount){
		Account::set_accountName(name);
		Account::set_accountNo(to_string(accountPrefix) + to_string(nextAccount)); // setting the account no from base class
		nextAccountNo(); // increasing the account value by 1
		Account::set_balance(_balance);
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

	void set_interestRate(float _interestRate){
		interestRate = _interestRate;
	}

	void set_monthlyDepositAmount(float _monthlyDepositAmount){
		monthlyDepositAmount = _monthlyDepositAmount;
	}

	void description(){
		cout<<endl;
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
	void nextAccountNo(){
		nextAccount++;
	}
public:
	MonthlyDepositScheme(float interestRate = 3, float monthlyDepositAmount = 500):interestRate(interestRate),monthlyDepositAmount(monthlyDepositAmount){}
	~MonthlyDepositScheme(){}

	int get_accountPrefix(){return accountPrefix;}
	float get_interestRate()const{
		return interestRate;
	}

	float get_monthlyDepositAmount() const{
		return monthlyDepositAmount;
	}

	void set_interestRate(float _interestRate){
		interestRate = _interestRate;
	}

	void set_monthlyDepositAmount(float _monthlyDepositAmount){
		monthlyDepositAmount = _monthlyDepositAmount;
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
		description();

	}
	~Loan(){}

	int get_accountPrefix(){return accountPrefix;}
	float get_interestRate()const{
		return interestRate;
	}

	float get_monthlyDepositAmount() const{
		return monthlyDepositAmount;
	}

	void set_interestRate(float _interestRate){
		interestRate = _interestRate;
	}

	void set_monthlyDepositAmount(float _monthlyDepositAmount){
		monthlyDepositAmount = _monthlyDepositAmount;
	}

	void description(){
		cout<<endl<<"Your Loan Account is being created\nAccount Name: "<<Account::get_accountName()<<endl<<"Account Number: "<<Account::get_accountNo()<<endl<<"Current Loan Amount: "<<Account::get_balance()<<endl<<"You need to pay atleast "<<monthlyDepositAmount<<" every month to avoid "<<interestRate<<'%'<<" interest\nThanks for staying with YMMY Bank\n";
	}
};

//TWO years MDS

class TwoYearMDS: public MonthlyDepositScheme{
private:
	float maximuminterest;

public:
	TwoYearMDS(string name , ){

	}

	float get_maximuminterest(){
		return maximuminterest;
	}

	void set_maximuminterest(float _maximuminterest){
		_maximuminterest = maximuminterest;
	}
};

//Five year

class FiveYearMDS: public MonthlyDepositScheme{
private:
	float maximuminterest;

public:
	float get_maximuminterest(){
		return maximuminterest;
	}

	void set_maximuminterest(float _maximuminterest){
		_maximuminterest = maximuminterest;
	}
};

//initial dep

class InitialDepositMDS: public MonthlyDepositScheme{
private:
	float maximuminterest;
	float initialDepositAmount;

public:
	float get_maximuminterest(){
		return maximuminterest;
	}

	void set_maximuminterest(float _maximuminterest){
		_maximuminterest = maximuminterest;
	}

	float get_initialDepositAmount(){
		return initialDepositAmount;
	}

	void set_initialDepositAmount(float _initialDepositAmount){
		initialDepositAmount = _initialDepositAmount;
	}
};


