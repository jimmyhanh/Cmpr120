//Hung Anh Ho
//2-21-2023
//Description: Chapter 2 - SalesTax

#include<iostream>;
using namespace std;

int main()
{
	int purchaseCost = 95;
	int salesTax = 4;
	int countryTax = 2;

	double totalTax = (purchaseCost * (salesTax / 100.0)) + (purchaseCost * (salesTax * 100.0));

	cout << "Total tax: $" << totalTax << "\n";

	return 0;
}