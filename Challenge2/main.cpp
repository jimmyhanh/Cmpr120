//Hung Anh Ho
//3-28-2023
//Characters for the Ascii codes

#include<iostream>;
using namespace std;

int main()
{
    // Go through 127 characters 16 each line
	for (int i = 0; i <= 127; i++)
	{
		if (i % 16 != 0)
		{
			cout << char(i) << " "; //Display Ascii characters
		}

		else
		{
			cout << "\n";
		}			
	}
	return (0);
}