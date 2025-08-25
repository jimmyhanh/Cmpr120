//Hung Anh Ho
//3-9-2023
//Chapter 4 - Challenge 27 - Wifi diagnostic

#include<iostream>;
#include<string>;
using namespace std;

int main()
{
	char answer = 'n';
	cout << "Reboot the computer and try to connect.\n";

	cout << "Did it fix your problem?\n";
	cin >> answer;
		
	if (answer == 'y' || answer == 'Y')
	{
		return 0;
	}

	else
	{
		cout << "Reboot the computer and try to connect.\n";
		
		cout << "Did it fix your problem?\n";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			cout << "Reboot the computer and try to connect.\n";
		}

		else
		{
			cout << "Make sure all the cables between the router and modem are plugged in firmly\n";
			
			cout << "Did it fix your problem?\n";
			cin >> answer;

			if (answer == 'y' || answer == 'Y')
			{
				cout << "Reboot the computer and try to connect.\n";
			}

			else
			{
				cout << "Move the router to a new location and try to connect.\n";

				cout << "Did it fix your problem?\n";
				cin >> answer;

				if (answer == 'y' || answer == 'Y')
				{
					cout << "Reboot the computer and try to connect.\n";
				}

				else
				{
					cout << "Get a new router.\n";
					return 0;
				
				}
			}
		}
	}
	
	return 0;
}