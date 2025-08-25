//Hung Anh Ho
//3-9-2023
//Chapter 4 - Challenge 26 - Mobile Service Provider 2

#include<iostream>;
using namespace std;

int main()
{
	char package = 'N';

	cout << "\nEnter a package plan (A, B or C): ";
	cin >> package;

	if (package != 'A' && package != 'B' && package != 'C' && package != 'a' && package != 'b' && package != 'c')
	{
		cout << "\nERROR: invalid pakage input.\n";
		return -1;
	}

	int gigabytes = 0;
	cout << "\nEnter gigabytes used: ";
	cin >> gigabytes;

	if (gigabytes < 0)
	{
		cout << "\nERROR: Invalid gigabytes input.\n";
		return -2;
	}


	double baseCostA = 39.99;
	double baseCostB = 59.99;
	double baseCostC = 69.99;
	switch (package)
	{
		case 'A' || 'a':
		{
			if (gigabytes > 4)
			{
				cout << "Cost for package A with additional gigabytes used: " << baseCostA + (gigabytes - 4) * 10.0 << "\n";
			}

			else
			{
				cout << "Cost for package A : $" << baseCostA << "\n";
			}
			break;
		}
	
		case 'B':
		{
			if (gigabytes > 8)
			{
				cout << "Cost for package B with additional gigabytes used: " << baseCostB + (gigabytes - 8) * 5.0 << "\n";
			}

			else
			{
				cout << "Cost for package B : $" << baseCostB << "\n";
			}
			break;
		}
	
		case 'C':
		{
			cout << "Unlimited data provided.";
			break;
		}

	}
}