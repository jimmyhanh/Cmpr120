//Hung Anh Ho
//2-21-2023
//Description: Chapter 2: CHallenge 6 - Annual Pay

#include<iostream>;
using namespace std;

int main()
{
	//Input
	double payAmount = 2200.00;
	int payPeriods = 26;
	double annualPay;

	//Process
	annualPay = payAmount * payPeriods;

	//Output
	cout << "The annual pay: $" << annualPay << " (dollars)\n";
	return 0;
}