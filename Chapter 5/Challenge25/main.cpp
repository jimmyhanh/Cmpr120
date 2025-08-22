//Hung Anh Ho
//3-28-2023
//Using Files - Student Line Up

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;

    string student;
    string firstName;
    string lastName;

    int num_of_students;

    //Open the file
    inputFile.open("LineUp.txt");

    if (inputFile)
    {
        //Process the file
        inputFile >> student;

        firstName = lastName = student;

        while (inputFile >> student)
        {
            if (student < firstName)
                firstName = student;

            if (student > lastName)
                lastName = student;
        }

        //Close File
        inputFile.close(); 
    }

    else
    {
        cout << "Cannot open file.\n";
    }
    cout << "\nThis program reports which students at first og the line and one at the last base on their names.\n";
    
    //First base on name
    cout << "\nFirst student in line = " << firstName << "\n";

    //Last base on name
    cout << "Last student in line  = " << lastName << "\n";

    return 0;
}