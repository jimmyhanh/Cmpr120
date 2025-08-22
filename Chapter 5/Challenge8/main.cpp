//Hung Anh Ho
//3-28-2023
//Math tutor

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Constant Variables
    const int minimum = 99;
    const int maximum = 999;

    // Variables
    int user_answer;
    int firstNumber;
    int secondNumber;
    int answer;


    do
    {
        //Assign system time to a variable.
        unsigned seed = time(0);

        //Seed random number generator with system time
        srand(seed);

        //Generate two random numbers
        firstNumber = (rand() % (maximum - minimum + 1)) + minimum;

        secondNumber = (rand() % (maximum - minimum + 1)) + minimum;

        //Menu selection
        int menu;
        
        //Menu
        cout << "\nMath Tutor";
        cout << "\n================";
        cout << "\n1. Addtion";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Multiplication";
        cout << "\n0. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> menu;

        switch(menu)
        {
            case 0: //exit
            {
                return 0;
            }

            case 1:
            {
                //Sum of the two random numbers.
                answer = firstNumber + secondNumber;

                //Display math problem & receive answer
                cout << firstNumber << " + " << secondNumber << " = ?\n";
                cout << "Enter your answer: ";
                cin >> user_answer;

                //Decision statement & display
                if (user_answer == answer)
                {
                    cout << "\nCongratulations! You are correct.";
                }

                else
                {
                    cout << "\nIncorrect. Get the correct answer? Press Enter: ";
                    cin.ignore(999, '\n');
                    cin.get();
                    cout << "\nCorrect answer : " << answer;
                }

                break;
            }

            case 2:
            {
                //Subtraction of the two random numbers.
                answer = firstNumber - secondNumber;

                //Display math problem & receive answer
                cout << firstNumber << " - " << secondNumber << " = ?\n";
                cout << "Enter your answer: ";
                cin >> user_answer;

                //Decision statement & display
                if (user_answer == answer)
                {
                    cout << "\nCongratulations! You are correct.";
                }

                else
                {
                    cout << "\nIncorrect. Get the correct answer? Press Press Enter: ";
                    cin.ignore(999, ' ');
                    cin.get();
                    cout << "\nCorrect answer: " << answer;
                }

                break;
            }
            
            case 3:
            {
                //Subtraction of the two random numbers.
                answer = firstNumber * secondNumber;

                //Display math problem & receive answer
                cout << firstNumber << " * " << secondNumber << " = ?\n";
                cout << "Enter your answer:";
                cin >> user_answer;

                //Decision statement & display
                if (user_answer == answer)
                {
                    cout << "\nCongratulations! You are correct.";
                }

                else
                {
                    cout << "\nIncorrect. Get the correct answer? Press Enter ";
                    cin.ignore(999, ' ');
                    cin.get();
                    cout << "\nCorrect answer : " << answer;
                }

                break;
            }

            case 4:
            {
                //Subtraction of the two random numbers.
                answer = firstNumber / secondNumber;

                //Display math problem & receive answer
                cout << firstNumber << " / " << secondNumber << " = ?\n";
                cout << "Enter your answer:";
                cin >> user_answer;

                //Decision statement & display
                if (user_answer == answer)
                {
                    cout << "\nCongratulations! You are correct.";
                }

                else
                {
                    cout << "\nIncorrect. Get the correct answer? Press Enter ";
                    cin.ignore(999, ' ');
                    cin.get();
                    cout << "\nCorrect answer: " << answer;
                }

                break;
            }

            default: //Menu validation
            {
                cout << "\nInvalid option. Enter the another option.";
                break;
            }
        }

        //Try again
        char answer;
        do
        {
            cout << "\nDo you want to continue (Y-N)? ";
            cin >> answer;

            if (answer == 'Y' || answer == 'y')
            {
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

    //Exit
    return 0;
}