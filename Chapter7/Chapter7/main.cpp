//Hung Anh Ho
//4-27-2023
//Chapter 7

#include <iostream>
#include <vector>
#include "input.h"
#include <iomanip>
#include <fstream>

using namespace std;

//Challenge 4
void getLargerThanN(double list[], int size, double& numberN);
void Challenge4();

//Challenge 6
void RainOrShine();
void Challenge6();

//Challenge 7
int findLowest(vector<int> array);
int findHighest(vector<int> array);
void Challenge7();

//Challenge 8
void Challenge8();

//Challenge 13
void Challenge13();

//Challenge 15
void Challenge15();

//Challenge 17
void getNames(vector<string>& names, string fileName);
int namesMenu();
bool checkNames(vector<string> list, string name);
void Challenge17();

//Cahllenge 18
void Challenge18();

//Challenge 21 //Failed
void Challenge21();

int main()
{
    do
    {
        system("cls");
        cout << "\n\t\tChapter 7: Functions (page 454-462) by Hung Anh Ho";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t\t  4. Larger than n          ";
        cout << "\n\t\t  6. Rain or Shine          ";
        cout << "\n\t\t  7. Number Analysis Program ";
        cout << "\n\t\t  8. Lo Shu Magic Square     ";
        cout << "\n\t\t 13. Grade book Modification ";
        cout << "\n\t\t 15. vector Modification     ";
        cout << "\n\t\t 17. Name Search             ";
        cout << "\n\t\t 18. Tic-Tac-Toe Game        ";
        cout << "\n\t\t 21. 2D Arrays Operations (Failed)";
        cout << "\n\t" + string(60, char(196));
        cout << "\n\t\t  0. Quit";
        cout << "\n\t" + string(60, char(205));
        cout << "\n";

        switch (inputInteger("\t\t  Option: ", 0 ,21))
        {
        case 0: exit(0); break;
        case 4: Challenge4(); break;
        case 6: Challenge6(); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break;
        case 13: Challenge13(); break;
        case 17: Challenge17(); break;
        case 18: Challenge18(); break;
 //       case 21: Challenge21(); break; //Failed
        default: cout << "\t\tERROR - Invalid option."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;
}

//Pre-condition: Takes in an array of integer, the size of the array, and the value(n) to check 
//Post-condition: Display the element is larger than n
void getLargerThanN (double list[], int size, double& numberN)
{  
    numberN = inputDouble("\n\tEnter number N: ", true);
    cout << "\n\tNumbers that are larger than N = " << numberN << ": \n";

    for (int i = 0; i < size; i++)
    {
        if (numberN < list[i])
        {
            cout << list[i];
            cout << "\n";
        }
    }
}

void Challenge4()
{
    const int size = 500;
    double numberN = 0;

    srand(unsigned(time(0)));

    //Dipslay 
    system("cls");
    cout << "\tChapter 7: Challenge 4 Larger than N";
    cout << "\n\t" << string(60, char(205)) << "\n";
    cout << "\n\t" << string(60, char(196)) << "\n";

    double list[size];

    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % size + 1;
    }

    getLargerThanN(list, size, numberN);
}

//Pre-condition: Takes in an array of characters, put in an array and check for rainy days, sunny days and cloudy days
//Post-condition: Display the rainy days, sunny days and cloudy days each month and display the month with the most rain.
void RainOrShine()
{
    char weather[3][30];
    int monthNumber = 3;
    vector <int> totalMonthlyRainyDays (monthNumber, 0);
    int highestRainMonth = 0;

    ifstream inputFile;

    inputFile.open("RainOrShine.TXT");

    int totalRainyDays = 0;
    int totalCloudyDays = 0;
    int totalSunnyDays = 0;

    do
    {
        //Validate input file
        if (inputFile)
        {
            for (int r = 0; r < 3; r++)
            {
                int totalMonthlyCloudydays = 0;
                int totalMonthlySunnydays = 0;

                //Display month
                if (r == 0)
                {
                    cout << "\n\tJune:\n";
                }

                else if (r == 1)
                {
                    cout << "\n\n\tJuly:\n";
                }

                else if (r == 2)
                {
                    cout << "\n\n\tAugust:\n";
                }
                cout << "\n\t" << string(60, char(205)) << "\n\t";

                for (int c = 0; c < 30; c++)
                {
                    inputFile >> weather[r][c];

                    cout << weather[r][c] << " ";

                    if (weather[r][c] == 'R')
                    {
                        totalMonthlyRainyDays[r]++;
                        totalRainyDays++;
                    }
                    else if (weather[r][c] == 'C')
                    {
                        totalMonthlyCloudydays++;
                        totalCloudyDays++;
                    }
                    else if (weather[r][c] == 'S')
                    {
                        totalMonthlySunnydays++;
                        totalSunnyDays++;
                    }



                }
                cout << '\n';

                cout << "\n\tMonthly rainy days: " << totalMonthlyRainyDays[r] << " (days)\n";
                cout << "\n\tMonthly cloudy days: " << totalMonthlyCloudydays << " (days)\n";
                cout << "\n\tMonthly sunny days: " << totalMonthlySunnydays << " (days)\n";

                //determine which month has the most rainy day days???
                if (highestRainMonth < totalMonthlyRainyDays[r])
                {
                    highestRainMonth = totalMonthlyRainyDays[r];
                }
            }

            inputFile.close();

            //Display the month with the most rain
            cout << "\n\tThe highest month with rainy days is ";
            if (highestRainMonth == totalMonthlyRainyDays[0])
            {
                cout << "June: " << totalMonthlyRainyDays[0];
            }

            else if (highestRainMonth == totalMonthlyRainyDays[1])
            {
                cout << "July: " << totalMonthlyRainyDays[1];
            }

            else
            {
                cout << "August: " << totalMonthlyRainyDays[2];
            }

            //Display total
            cout << "\n\tTotal rainy days: " << totalRainyDays << " (days)";
            cout << "\n\tTotal cloudy days: " << totalCloudyDays << " (days)";
            cout << "\n\tTotal sunny days: " << totalSunnyDays << " (days)\n";

            break;
        }
        else
        {
            cout << "\n\tError opening input file. Try again.";
            string file = inputString("\n\tEnter the file correct name: ", true);
            inputFile.open(file);
        }

    } while (!inputFile);
}

void Challenge6()
{
    system("cls");
    cout << "\tChapter 7: Challenge 7 Number Analysis Program";
    cout << "\n\t" << string(60, char(205)) << "\n";
    cout << "\n\t" << string(60, char(196)) << "\n";

    //Display
    RainOrShine();

}


// Take in a vector of data and find the lowest value
int findLowest(vector<int> array)
{
    int result = array[0];

    for (int i = 0; i < array.size(); i++)
        if (array[i] < result)  //find the lowest
            result = array[i];

    return result;
}

// Take in a vector of data and find the highest value
int findHighest(vector<int> array)
{
    int result = array[0];

    for (int i = 0; i < array.size(); i++)
        if (array[i] > result)   //find the highest
            result = array[i];

    return result;
}

void Challenge7()
{
    //Display
    system("cls");
    cout << "\tChapter 7: Challenge 7  Number Analysis Program";
    cout << "\n\t" << string(60, char(205)) << "\n";
    cout << "\n\t" << string(60, char(196)) << "\n";

    //create obj to read text file
    ifstream inputFile;

    do
    {
        // prompt the user for a file name
        string filename = inputString("\n\tEnter the data file: ", true);

        // open the file to read
        inputFile.open(filename);

        //validate if file existed
        if (inputFile)
        {
            //create a vector(dynamic array)
            vector<int> array;

            int value = 0;

            //read data from the file and store into the vector
            while (inputFile >> value)
            {
                array.push_back(value);
                cout << "\n\t" << value << '\n';
            }

            cout << "\n\tThe lowest: " << findLowest(array);
            cout << "\n\tThe highest: " << findHighest(array);

            inputFile.close();

            break;
        }

        else
        {
            cout << "\n\tERROR: file, " << filename << ", cannot be found.\n";
            continue;
        }

    } while (!inputFile);
}



void Challenge8()
{
    const int size = 3;
    int square[size][size];

    const int numberLimit = 9;
    vector<int> count(numberLimit, 0);
    
    //Dipslay 
    system("cls");
    cout << "\tChapter 7: Challenge 8 Lo shu magic square";
    cout << "\n\t" << string(60, char(205)) << "\n";
    cout << "\n\t" << string(60, char(196)) << "\n";

    cout << "Example: a lo shu magic square. Every sum from all sides are equal.";

    //Display example
    cout << "\n\t {4  9  2} \n\t {3  5  7} \n\t {8  1  6} \n\n";

    int input = 0;
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {         
            //Validate input for duplicate number
            do
            {
                input = inputInteger("\n\tEnter a number from 1 - 9 row(" + to_string(row + 1) + "), column(" + to_string(column + 1) + "): ", 1, 9);

                if (count[input - 1] == 0)
                {
                    square[row][column] = input;
                    count[input-1]++;
                    break;
                }
                else
                {
                    cout << "\n\tNumber " << input << " has been chosen.";
                }

            } while (count[input - 1] != 0);
        }
    }

    //Display square
    cout << "\n\t\tDisplay the square:\n";
    for (int row = 0; row < size; row++)
    {
        cout << "\t\t" << string(19, char(196)) << "\n\t\t";
        for (int column = 0; column < size; column++)
        {
            cout << char(179) <<"  " <<  square[row][column] << "  ";
        }
        cout << char(179) << "\n";
        cout << "\t\t" << string(19, char(196)) << "\n";
    }

    //Validate magic square
    if ((square[0][0] + square[0][1] + square[0][2] == 15) && // equal by rows
        (square[1][0] + square[1][1] + square[1][2] == 15) &&
        (square[2][0] + square[2][1] + square[2][2] == 15) &&

        (square[0][0] + square[1][0] + square[2][0] == 15) && // equal by columns
        (square[0][1] + square[1][1] + square[2][1] == 15) &&
        (square[0][2] + square[1][2] + square[2][2] == 15) &&

        (square[0][0] + square[1][1] + square[2][2] == 15) && //diaganal
        (square[0][2] + square[1][1] + square[2][0] == 15))

    {
        cout << "This is a lo shu magic square. Every sum from all sides are equal.";
    }

    else
        cout << "This isn's a lo shu magic square. Every sum from all sides are not equal.";


}



void Challenge13()
{
    const int studentNumber = 5;
    const int testNumber = 5;

    system("cls");
    cout << "\tChapter 7: Challenge 13 Grade book modification";
    cout << "\n\t" << string(60, char(205)) << "\n";
    cout << "\n\t" << string(60, char(196)) << "\n";

    // create a 2D array to store the student test scores
    double gradeBook[studentNumber][testNumber];

    // create a 1D array to store the student names
    string studentNames[studentNumber];
    char letterGrades[studentNumber];

    //input student name and his/her 4 test scores
    for (int i = 0; i < studentNumber; i++)
    {
        studentNames[i] = inputString("\nEnter the student#" + to_string(i + 1) + " name: ", true);

        cout << "\n";

        //Input grade and find lowest
        for (int t = 0; t < testNumber; t++)
        {
            gradeBook[i][t] = inputDouble("Enter the test score#" + to_string(t + 1) + ": ", 0.0, 100.0);
        }

    }


    //output
    cout << '\n';

    for (int i = 0; i < studentNumber; i++)
    {
        double total = 0.0;
        double lowest = 100.0;

        for (int t = 0; t < testNumber; t++)
        {
            total += gradeBook[i][t];
            //Find lowest score to drop
            gradeBook[i][t] <= lowest ? lowest = gradeBook[i][t] : lowest = lowest;
        }

        //Average score with lowest score dropped
        double average = (total - lowest) / 4;


        //Display
        if (average >= 90.0)
            letterGrades[i] = 'A';
        else if (average >= 80.0)
            letterGrades[i] = 'B';
        else if (average >= 70.0)
            letterGrades[i] = 'C';
        else if (average >= 60.0)
            letterGrades[i] = 'D';
        else
            letterGrades[i] = 'F';

        cout << "\nStudent name: " << studentNames[i];
        cout << "\nAverage: " << average;
        cout << "\nLetter Grade: " << letterGrades[i] << '\n';

    }
}



//Takes in file name and put contents into an vector array and return the vector
void getNames(vector<string> &names, string fileName)
{
    ifstream inputFile;

    do
    {
        inputFile.open(fileName);

        if (inputFile.fail())
        {
            cout << "Error opening file " << fileName << ".Try again.\n";
            fileName = inputString("Enter correct file name: ", true);
        }

        else
        {
            string content;

            while (inputFile >> content)
                names.push_back(content);

            inputFile.close();
            break;
        }

    } while (true);

}

//Menu for Challenge 21 return user's choice
int namesMenu()
{
    cout << "\tMenu:\n\t1.Most popular among boys names\n\t2.Most popular among girl names\n\t3. Both\n\t0. Exit\n";
    int input = inputInteger("\tEnter your option: ", 0, 3);
    
    return input;
}

//checkNames check text files for the names and return true-false if exist
bool checkNames(vector<string> list, string name)
{
    for (string i : list)
    {
        i = name;
        return true;
    }

    return false;
}

void Challenge17()
{
    system("cls");
    cout << "\tChapter 7: Challenge 17 Name search";
    cout << "\n\t" << string(60, char(205)) << "\n";
    cout << "\n\t" << string(60, char(196)) << "\n";

    vector<string> boy_names;
    getNames(boy_names,"BoyNames.txt");

    vector<string> girl_names;
    getNames(girl_names, "GirlNames.txt");


    int choice = 0;
    string userName;
    do
    {
        choice = namesMenu();
        cout << "\n";

        switch (choice)
        {
            case 0: break;
            case 1:
            {
                userName = inputString("\tEnter a boy's name: ", true);
                cout << "\t" << userName << (checkNames(boy_names, userName) ? " is" : " isn't") << " among the most popular names.\n\n";

                break;
            }

            case 2:
            {
                userName = inputString("\tEnter a girl's name: ", true);
                cout << "\t" << userName << (checkNames(girl_names, userName) ? " is" : " isn't") << " among the most popular names.\n\n";

                break;

            }

            case 3:
            {
                userName = inputString("\tEnter a boy's name: ", true);
                cout << "\t" << userName << (checkNames(boy_names, userName) ? " is" : " isn't") << " among the most popular names.\n\n";

                userName = inputString("\tEnter a girl's name: ", true);
                cout << "\t" << userName << (checkNames(girl_names, userName) ? " is" : " isn't") << " among the most popular names.\n\n";

                break;
            }
        }

    } while (choice != 0);
}


void Challenge18()
{
    const int size = 3;
    string square[size][size];
    const string player_1 = "   X   ";
    const string player_2 = "   O   ";
    const string blankSpace = "       ";
    bool winner = false;

    //Dipslay 
    system("cls");
    cout << "\tChapter 7: Challenge 18 Tic Tac Toe";
    cout << "\n\t" << string(60, char(205)) << "\n";
    cout << "\n\t" << string(60, char(196)) << "\n";

    //Display square and assign sqaure to blank
    cout << "\n\t\tDisplay the square:\n";
    for (int row = 0; row < size; row++)
    {
        cout << "\t\t" << string(25, char(196)) << "\n\t\t";
        for (int column = 0; column < size; column++)
        {
            square[row][column] = blankSpace;
            cout << char(179) << square[row][column];
        }
        cout << char(179) << "\n";
        cout << "\t\t" << string(25, char(196)) << "\n";
    }

    //Input
    int count = 0;
    do
    {
        if (count == 0 || count == 2 || count == 4 || count == 6 || count == 8)
        {
            cout << "\n\tTurn " << to_string(count + 1) << ": Player 1";
            
            //Validate
            do
            {
                int row = inputInteger("\n\tEnter your row: : ", 1, 3);
                int column = inputInteger("\n\tEnter your column: : ", 1, 3);

                if (square[row - 1 ][column - 1 ] != player_1 && square[row - 1][column - 1] != player_2)
                {
                    square[row - 1][column -1] = player_1;
                    count++;
                    break;
                }

                else
                    cout << "\n\tThis sapce has been already been chosen";

            } while (true);

        }

        else
        {
            cout << "\n\tTurn " << to_string(count + 1) << ": Player 2";
            //Validate
            do
            {
                int row = inputInteger("\n\tEnter your row: : ", 1, 3);
                int column = inputInteger("\n\tEnter your column: : ", 1, 3);

                if (square[row - 1][column - 1] != player_1 && square[row - 1][column - 1] != player_2)
                {
                    square[row - 1][column -1] = player_2;
                    count++;
                    break;
                }

                else
                    cout << "\n\tThis sapce has been already been chosen\n";

            } while (true);
        }


        //Display square
        cout << "\n\t\tDisplay the square:\n";
        for (int row = 0; row < size; row++)
        {
            cout << "\t\t" << string(25, char(196)) << "\n\t\t";
            for (int column = 0; column < size; column++)
            {
                cout << char(179) << square[row][column];
            }
            cout << char(179) << "\n";
            cout << "\t\t" << string(25, char(196)) << "\n";
        }

        //Failed
        /* FAILED
         if ((player_1.compare(square[0][0]) && player_1.compare(square[0][1]) && player_1.compare(square[0][2])) || // equal by rows
             (player_1.compare(square[1][0]) && player_1.compare(square[1][1]) && player_1.compare(square[1][2])) ||
             (player_1.compare(square[2][0]) && player_1.compare(square[2][1]) && player_1.compare(square[2][2])) ||

             (player_1.compare(square[0][0]) && player_1.compare(square[1][0]) && player_1.compare(square[2][0])) || // equal by columns
             (player_1.compare(square[0][1]) && player_1.compare(square[1][1]) && player_1.compare(square[2][1])) ||
             (player_1.compare(square[0][2]) && player_1.compare(square[1][2]) && player_1.compare(square[2][2]) ||

             (player_1.compare(square[0][0]) && player_1.compare(square[1][1]) && player_1.compare(square[2][2])) || //diaganal
             (player_1.compare(square[0][2]) && player_1.compare(square[1][1]) && player_1.compare(square[2][0]))))

         {
             cout << "Player 1 wins";
         }
         else if ((player_2.compare(square[0][0]) && player_2.compare(square[0][1]) && player_2.compare(square[0][2])) || // equal by rows
              (player_2.compare(square[1][0]) && player_2.compare(square[1][1]) && player_2.compare(square[1][2])) ||
              (player_2.compare(square[2][0]) && player_2.compare(square[2][1]) && player_2.compare(square[2][2])) ||

              (player_2.compare(square[0][0]) && player_2.compare(square[1][0]) && player_2.compare(square[2][0])) || // equal by columns
              (player_2.compare(square[0][1]) && player_2.compare(square[1][1]) && player_2.compare(square[2][1])) ||
              (player_2.compare(square[0][2]) && player_2.compare(square[1][2]) && player_2.compare(square[2][2]) ||

              (player_2.compare(square[0][0]) && player_2.compare(square[1][1]) && player_2.compare(square[2][2])) || //diaganal
              (player_2.compare(square[0][2]) && player_2.compare(square[1][1]) && player_2.compare(square[2][0]))))

         {
             cout << "Player 2 wins";
         }
         else
             continue;
        */

        //Validate winner
        if (((square[0][0] == player_1 && square[0][0] == square[0][1] && square[0][0] == square[0][2]) ||// equal by rows
            (square[1][0] == player_1 && square[1][0] == square[1][1] && square[1][0] == square[1][2]) ||
            (square[2][0] == player_1 && square[2][0] == square[2][1] && square[2][0] == square[2][2]) ||

            (square[0][0] == player_1 && square[0][0] == square[1][0] && square[0][0] == square[2][0]) ||// equal by columns
            (square[0][0] == player_1 && square[0][1] == square[1][1] && square[0][1] == square[2][1]) ||
            (square[0][2] == player_1 && square[0][2] == square[1][2] && square[0][2] == square[2][2]) ||

            (square[0][0] == player_1 && square[0][0] == square[1][1] && square[0][0] == square[2][2]) ||//diaganal
            (square[0][2] == player_1 && square[0][2] == square[1][1] && square[0][2] == square[2][0])))
        {
            cout << "\n\tPlayer 1 wins.";
            winner = true;
            break;
        }

        if (((square[0][0] == player_2 && square[0][0] == square[0][1] && square[0][0] == square[0][2]) ||// equal by rows
            (square[1][0] == player_2 && square[1][0] == square[1][1] && square[1][0] == square[1][2]) ||
            (square[2][0] == player_2 && square[2][0] == square[2][1] && square[2][0] == square[2][2]) ||

            (square[0][0] == player_2 && square[0][0] == square[1][0] && square[0][0] == square[2][0]) ||// equal by columns
            (square[0][0] == player_2 && square[0][1] == square[1][1] && square[0][1] == square[2][1]) ||
            (square[0][2] == player_2 && square[0][2] == square[1][2] && square[0][2] == square[2][2]) ||

            (square[0][0] == player_2 && square[0][0] == square[1][1] && square[0][0] == square[2][2]) ||//diaganal
            (square[0][2] == player_2 && square[0][2] == square[1][1] && square[0][2] == square[2][0])))
        {
            cout << "\n\tPlayer 2 wins.";
            winner = true;
            break;
        }

        //Check if tie
        if (count == 9 && winner == false)
        {
            cout << "\n\tIt is a tie. Play again.";
        }

    } while (count < 9);
}


/* //Failed
int getLowestInRow(int array[][3], const int row)
{
int lowest = array[(row - 1)][0];
for(int column = 1; column < 3; column++)
{
if(array[(row - 1)][3] <= lowest)
lowest = array[(row - 1)][3];
}
return lowest;
}

void Challenge21()
{
//Dipslay 
system("cls");
cout << "\tChapter 7: Challenge 21 2D Array operations";
cout << "\n\t" << string(60, char(205)) << "\n";
cout << "\n\t" << string(60, char(196)) << "\n";

srand(time_t(0));

const int rows = 3;
const int columns = 3;

int test_data[rows][columns];

for (int i = 0; i < rows; i++)
{
for (int j = 0; j < columns; i++)
{
test_data[rows][columns] = rand() % 10 + 1;
}
}

displayData(test_data, rows, columns);
}
*/