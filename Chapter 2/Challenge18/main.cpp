//Hung Anh Ho
//2-23-2023
//Description: Chapter 2: Challenge 11 - Energy Drink Consumption

#include<iostream>;
using namespace std;

int main()
{
	//Input
	int customerNumber = 16500;
	int percentPurchasePerWeek = 15;
	int percentPreferCitrus = 58;
	int peoplePurchasePerWeek;
	int peoplePreferCitrus;

	//Process
	peoplePurchasePerWeek = customerNumber * (percentPurchasePerWeek / 100.0);
	peoplePreferCitrus = peoplePurchasePerWeek * (percentPreferCitrus / 100.0);

	//Output
	cout << "Approximate number of the customers who purchase one or more energy drinks per week: " << peoplePurchasePerWeek << " (people)\n";
	cout << "Approximate number of the customers who purchase one or more energy drinks per week that prefer citrus-flavored: " << peoplePreferCitrus << " (people)\n";

	return 0;
}