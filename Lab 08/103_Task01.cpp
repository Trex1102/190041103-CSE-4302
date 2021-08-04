#include "103_Task01.h"
using namespace std;
//declaring static variables
const int Current::serviceCharge;
const int Current::accountPrefix;
int Current::nextAccount = 1;

const int Savings::accountPrefix;
int Savings::nextAccount = 1;

const int MonthlyDepositScheme::accountPrefix;
int MonthlyDepositScheme::nextAccount = 1;

const int Loan::accountPrefix;
int Loan::nextAccount = 1;

int main()
{
	Current acc1 ("Navid Alvee", 1500);
	Savings acc3("MD. Tanvir Hossain Saikat",4, 1500 , 2000);
	Loan acc4("Reaz Hasan Zoarder" , 4, 3000, 100000);
	TwoYearMDS acc5("Alif Arshad");
	FiveYearMDS acc6("Faisal Tariquazzaman");
	InitialDepositMDS acc7("Jawed Ridhi");
}