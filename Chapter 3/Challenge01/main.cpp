//Hung Anh Ho
//Mar-2-2023
//Chapter 3: Challenge 1 - Miles per Gallon

#include<iostream>;
#include<iomanip>;
#include<cstdlib>;
using namespace std;

int main()
{
	//Input
	double gasTank = 0.0;
	cout << "\nEnter the number of gallons of gas: ";
	cin >> gasTank;

	double miles = 0.0;
	cout << "\nEnter the number of miles: ";
	cin >> miles;

	//Process
	double mpg = miles / gasTank; //mpg(miles per gallon)

	//Output
	cout << "\nMPG (miles per gallon): " << setprecision(2) << setw(10) << right<< mpg << "(mpg)\n";

	return 0;
}