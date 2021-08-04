#include "103_Task01.h"
using namespace std;

const int Current::serviceCharge;
const int Current::accountPrefix;
int Current::nextAccount = 1;

const int Savings::accountPrefix;
int Savings::nextAccount = 1;

const int MonthlyDepositScheme::accountPrefix;
int MonthlyDepositScheme::nextAccount = 1;

const int Loan::accountPrefix;
int Loan::nextAccount = 1;

void interface(){
	string account_Name;
	printf("Type your account type. The options are:\n1. Current\n2. Savings\n3. Monthly Deposite\n4. Loan\n");
	cin>>account_Name;
}

int main()
{
	Current acc1 ("Navid Alvee", 1500) , acc2("Alif Arshad" , 1500);
	Savings acc3("MD. Tanvir Hossain Saikat",4, 1500 , 2000);
	Loan acc4("Reaz Hasan Zoarder" , 4, 3000, 100000);
	

	//cout<< acc2.get_serviceCharge()<<endl;

	//cout<<acc2.get_accountNo()<<endl;
	//cout<<acc2.get_nextAccount();
}