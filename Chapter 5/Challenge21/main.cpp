//Hung Anh Ho
//3-28-2023
//Random number guessing game enhanced

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    //Variables
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 10;

    int randomNumber;
    int userNumber;
    int number_of_guesses = 0;

    do
    {
        //Seed
        srand(time(0));

        randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

        cout << "Guess a number between 1 and 10: ";
        cin >> userNumber;
        number_of_guesses++;

        while (userNumber != randomNumber)
        {
            cout << "Your number is " << (userNumber < randomNumber ? "too low." : "too high.");
            cout << " Try again: ";

            cin >> userNumber;
            number_of_guesses++;
        }

        cout << "\nCorrect! ";
        cout << "\n\nRandom number      : " << randomNumber;
        cout << "\nYour guess         : " << userNumber;
        cout << "\nNumber of guesses  : " << number_of_guesses;


        //Try again
        char answer;
        do
        {
            cout << "\nDo you want to continue (Y-N)? ";
            cin >> answer;

            if (answer == 'Y' || answer == 'y')
            {
                cout << "\n";
                break;
            }

            else if (answer == 'N' || answer == 'n')
            {
                cout << "\nTerminating program.";
                return 0;
            }
            else
            {
                cout << "\nInvalid answer. Try again.";
            }

        } while (true);

    } while (true);
}