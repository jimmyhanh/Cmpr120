//Hung Anh Ho
//2-22-2023
//Description: Chapter 2: Challenge 10 - Miles Per Gallon

#include<iostream>;
using namespace std;

int main()
{
	//Input
	double numberGallons = 15.0;
	double milesDriven = 375.0;
	double milesPerGallon;

	//Process
	milesPerGallon = milesDriven / numberGallons;

	//Output
	cout << "Miles per gallon the car has: " << milesPerGallon << " (mpg)\n";

	return 0;
}
