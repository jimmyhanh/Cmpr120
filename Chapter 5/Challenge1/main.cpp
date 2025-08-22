//Hung Anh Ho
//3-28-2023
//Sum of Numbers

#include<iostream>;

using namespace std;

int main()
{
	int number;

	// User input and validation
	do
	{
		cout << "\nEnter a positive number: ";
		cin >> number;

		if (number < 1)
		{
			cout << "Number cannot be less than 1. Try again.";
		}

	} while (number < 1);

	// Sum of numbers
	int sum = 0;
	for (int i = 1; i <= number; i++)
	{
		sum += i;
	}

	cout << "Sum of numbers from 1 to " << number << ": " << sum;
	return 0;

}