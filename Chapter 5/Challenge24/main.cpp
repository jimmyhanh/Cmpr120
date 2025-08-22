//Hung Anh Ho
//3-28-2023
//Using Files-Numeric Processing

#include <iostream>		// input and output console
#include <fstream>		// file input and output
using namespace std;

int main()
{
	//input from the file
	ifstream inputfile;		//the object file of reading

	inputfile.open("random.txt");		// open the file to read

	int number;
	int count = 0;					// initialize count = 0
	int total = 0;

	while (inputfile >> number)		// while not end of file do this
	{
		cout << number << '\n';		// display the number onto console

		count++;					// keeping track of the number of data

		total = total + number;		// keeping track of the total of all numbers

	}

	//Calcule count
	cout << "\nThe number of data: " << count << "\n";

	//Calculate sum
	cout << "\nThe sum of data: " << total << "\n";

	//Calculate average
	cout << "\nThe average of data: " << static_cast<double>(total) / count << "\n"; //changing the data type

	inputfile.close();				//close the file after using

	return 0;
}