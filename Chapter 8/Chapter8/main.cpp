//Hung Anh Ho
//5-12-2023
//Chapter 8

#include <iostream>
#include<vector>
#include <fstream>
#include "input.h"
using namespace std;

void Challenge1();

void Challenge6();

void Challenge7();

void Challenge8();
void displayArray(string array[], int ARRAY_SIZE, string prompt);

void Challenge9();
void displayArray(int array[], int ARRAY_SIZE, string prompt);

void Challenge11();

bool linearSearch(int array[], int ARRAY_SIZE, int user_number);
void selectionSort(vector<string>& v);
void swap(string& a, string& b);


int main()
{
    do
    {
        system("cls");
        cout << "\n\t\tChapter 8: Searching and sorting arrays by your name";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t\t  1. Charge Account Validation ";
        cout << "\n\t\t  6. String Selection Sort ";
        cout << "\n\t\t  7. Binary String Search ";
        cout << "\n\t\t  8. Search Benchmarks ";
        cout << "\n\t\t  9. Sorting Benchmarks ";
        cout << "\n\t\t 11. Using Files_String Selection Sort Modification ";
        cout << "\n\t" + string(60, char(196));
        cout << "\n\t\t  0. Quit";
        cout << "\n\t" + string(60, char(205)) <<"\n";

        switch (inputInteger("\t\t  Option: ", 0, 11))
        {
        case 0: exit(1); break;
        case 1: Challenge1(); break;
        case 6: Challenge6(); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break;
        case 9: Challenge9(); break;
        case 11: Challenge11(); break;
        default: cout << "\t\tERROR - Invalid option."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}


//***********************************************************************
// The linearSearch function searches a string vector. *
//***********************************************************************
bool linearSearch(int array[], int ARRAY_SIZE, int user_number)
{
    int index = 0;
    bool found = false;

    while (index < ARRAY_SIZE && !found)
    {
        if (array[index] == user_number)
            found = true;
        index++;
    }
    return found;
}

//***********************************************************************
// The linearSearch function searches a integer vector. *
//***********************************************************************
int linearSearch(int array[], int array_size, int search_value, int &number_of_comparisons)
{
    int index = 0,
        position = -1;

    bool found = false;

    while (index < array_size && !found)
    {
        if (array[index] == search_value)
        {
            found = true;
            position = index;
        }

        number_of_comparisons++;
        index++;
    }
    return position;
}


//***********************************************************************
// The selectionSort function sorts a string vector in ascending order. *
//***********************************************************************
void selectionSort(vector<string>& v)
{
    int minIndex;
    string minValue;

    for (int start = 0; start < (v.size() - 1); start++)
    {
        minIndex = start;
        minValue = v[start];
        for (int index = start + 1; index < v.size(); index++)
        {
            if (v[index] < minValue)
            {
                minValue = v[index];
                minIndex = index;
            }
        }
        swap(v[minIndex], v[start]);
    }
}

//***********************************************************************
// The selectionSort function sorts a integer array in ascending order. *
//***********************************************************************
void selectionSort(int array[], int ARRAY_SIZE)
{
    int min_index;
    int min_value;

    // 0 -> 18
    for (int start_index = 0; start_index < (ARRAY_SIZE - 1); start_index++)
    {
        min_index = start_index;
        min_value = array[start_index];

        // 1 -> 19
        for (int index = start_index + 1; index < ARRAY_SIZE; index++)
        {
            if (array[index] < min_value)
            {
                min_value = array[index];
                min_index = index;
            }
        }
        swap(array[min_index], array[start_index]);
    }
}

//***********************************************************************
// The selectionSort function sorts a integer array in ascending order. *
//***********************************************************************
void selectionSort(int array[], int ARRAY_SIZE, int &number_of_exchanges)
{
    int min_index,
        min_value;

    // 0 -> 18
    for (int start_index = 0; start_index < (ARRAY_SIZE - 1); start_index++)
    {
        min_index = start_index;
        min_value = array[start_index];

        // 1 -> 19
        // array[0] array[1]
        for (int index = start_index + 1; index < ARRAY_SIZE; index++)
        {
            if (array[index] < min_value)
            {
                min_value = array[index];
                min_index = index;
                number_of_exchanges++;
            }
        }
        swap(array[min_index], array[start_index]);
    }

}

//***********************************************************************
// The selectionSort function sorts a string array in ascending order. *
//***********************************************************************
void selectionSort(string array[], int ARRAY_SIZE)
{
    int min_index;
    string min_value;

    for (int start_index = 0; start_index < (ARRAY_SIZE - 1); start_index++)
    {
        min_index = start_index;
        min_value = array[start_index];

        for (int index = start_index + 1; index < ARRAY_SIZE; index++)
        {
            if (array[index] < min_value)
            {
                min_value = array[index];
                min_index = index;
            }
        }
        swap(array[min_index], array[start_index]);
    }
}

//***************************************************
// The swap function swaps a and b in memory.       *
//***************************************************
void swap(string& a, string& b)
{
    string temp = a;
    a = b;
    b = temp;
}


//***************************************************
// The binarySearch function searches for a number in memory.       *
//***************************************************
int binarySearch(int array[], int array_size, int search_value, int& number_of_comparisons)
{
    int first = 0;
    int middle;
    int last = array_size - 1;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;    // (0 + 19) / 2 = 9

        if (array[middle] == search_value)      // Middle
        {
            found = true;
            position = middle;
        }

        else if (array[middle] > search_value)  // Lower half
            last = middle - 1;

        else                                    // Upper half
            first = middle + 1;

        number_of_comparisons++;
    }

    return position;
}

//***************************************************
// The binarySearch function searches for a string in memory.       *
//***************************************************
int binarySearch(string array[], int array_size, string user_name)
{
    int first = 0,
        last = array_size - 1,  // 19
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2; // (0 + 19) / 2 = 8

        if (array[middle] == user_name)     // Middle
        {
            position = middle;
            found = true;
        }
        else if (array[middle] > user_name)   // Lower Half
            last = middle - 1; // 8 - 1 = 7  // 8, 4, 4, 3, 2, 3, 
        else                                  // Upper Half
            first = middle + 1;  // 8 + 1 = 9

    }
    return position;
}



//***************************************************
// The bubbleSort function searches for a string in memory.       *
//***************************************************

void bubbleSort(int array[], int ARRAY_SIZE, int &number_of_exchanges)
{
    int max_element, 
        index;
    // <---------
    for (max_element = ARRAY_SIZE - 1; max_element > 0; max_element--)
    {
        // --------->
        for (index = 0; index < max_element; index++)
        {
            // array[0] > array[1];
            if (array[index] > array[index + 1])
            {
                swap(array[index], array[index + 1]);
                number_of_exchanges++;
            }
        } 
    }
}


void Challenge1()
{
    const int NUMBER_OF_ACCOUNTS = 18;

    int accountNumbers[NUMBER_OF_ACCOUNTS] = { 5658845, 4520125, 7895122, 
        8777541, 8451277, 1302850, 
        8080152, 4562555, 5552012, 
        5050552, 7825877, 1250255, 
        1005231, 6545231, 3852085, 
        7576651, 7881200, 4581002 };

    int accountNumber = inputInteger("\nEnter the search account number: ", true);

    bool number_is_valid = linearSearch(accountNumbers, NUMBER_OF_ACCOUNTS, accountNumber);

    if (number_is_valid)
        cout << "Your account number is valid.\n";
    else
        cout << "Your account number is invalid.\n";

}


void Challenge6()
{
    vector<string> namelist = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                               "Taylor, Terri", "Johnson, Jill", 
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", 
                               "James, Jean", "Weaver, Jim", "Pore, Bob", 
                               "Rutherford, Greg", "Javens, Renee", 
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };

    cout << "\nBefore sort:\n";
    for (int i = 0; i < namelist.size(); i++)
        cout << namelist[i] << '\n';

    //sort
    cout << "\n\nAfter sort:\n";
    selectionSort(namelist);

    cout << "\n";
    for (int i = 0; i < namelist.size(); i++)
        cout << namelist[i] << '\n';

}


void Challenge7()
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                                "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                                "Taylor, Terri", "Johnson, Jill", 
                                "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", 
                                "James, Jean", "Weaver, Jim", "Pore, Bob", 
                                "Rutherford, Greg", "Javens, Renee", 
                                "Harrison, Rose", "Setzer, Cathy",
                                "Pike, Gordon", "Holland, Beth" };


    // Insert your code to complete this program
    displayArray(names, NUM_NAMES, "UNSORTED: \n--------------------");
    selectionSort(names, NUM_NAMES);
    displayArray(names, NUM_NAMES, "SORTED: \n-------------------- ");

    string user_name = inputString("Enter a name to search: ", true);

    int position = binarySearch(names, NUM_NAMES, user_name);

    if (position != -1)
        cout << names[position] << " was found.\n";
    else
        cout << user_name << " was not found.\n";
}

//displayArray display aray
void displayArray(string array[], int ARRAY_SIZE, string prompt)
{
    cout << prompt << "\n";
    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << array[i] << "\n";
    cout << "\n";
}


void Challenge8()
{
    const int size = 20;
    int numbers[size];

    srand(unsigned(0));

    for (int i = 0; i < size; i++)
    {
        numbers[i] = rand() % 50 + 1;
    }

    //display before search
    cout << "Before sort:\n---------------\n";

    for (auto element : numbers)
        cout << element << ", ";
    cout << "\n";

    selectionSort(numbers, size);

    cout << "After sort:\n---------------\n";

    for (auto element : numbers)
        cout << element << ", ";

    cout << "\n";

    int search_value = inputInteger("Enter a value : ", true);


    //search
    int number_of_comparisions = 0;
    int results = linearSearch(numbers, size, search_value, number_of_comparisions);
    cout << "\n";


    if (results != -1)
    {
        cout <<"\n" << search_value << " was found at position " << results << '.\n';
        cout <<"\nNumber of comparisons = " << number_of_comparisions << "\n";
    }

    else
    {
        cout <<"\n" << search_value << " was NOT found.\n";
        cout <<"\nNumber of comparisons = " << number_of_comparisions << "\n";
    }

    number_of_comparisions = 0;
    results = binarySearch(numbers, size, search_value, number_of_comparisions);

    cout << "\n";
    if (results != -1)
    {
        cout <<"\n" << search_value << " was found at position " << results << '.\n';
        cout << "\nNumber of comparisons = " << number_of_comparisions << "\n";
    }
    else
    {
        cout << search_value << " was NOT found. " << "\n";
        cout << "\nNumber of comparisons = " << number_of_comparisions << "\n";
    }

}


void Challenge9()
{
    const int ARRAY_SIZE = 20;

    int array_1[ARRAY_SIZE] = {6, 5, 90, 33, 45, 
                               1, 89, 70, 30, 4,
                               55, 60, 2, 9, 11,
                               91, 65, 45, 8, 3};

    int array_2[ARRAY_SIZE] = {6, 5, 90, 33, 45, 
                               1, 89, 70, 30, 4,
                               55, 60, 2, 9, 11,
                               91, 65, 45, 8, 3};

    string unsorted = "UNSORTED-------------------";
    string sorted = "SORTED-------------------";
    
    
    int number_of_exchanges = 0;
    displayArray(array_1, ARRAY_SIZE, unsorted);
    bubbleSort(array_1, ARRAY_SIZE, number_of_exchanges);
    displayArray(array_1, ARRAY_SIZE, sorted);
    cout << "\nNumber of exchanges = " << number_of_exchanges << "\n";

    number_of_exchanges = 0;
    displayArray(array_2, ARRAY_SIZE, unsorted);
    selectionSort(array_2, ARRAY_SIZE, number_of_exchanges);
    displayArray(array_2, ARRAY_SIZE, sorted);
    cout << "\nNumber of exchanges = " << number_of_exchanges << "\n\n";

}

//displayArray display aray
void displayArray(int array[], int ARRAY_SIZE, string prompt)
{
    cout << prompt << "\n";
    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << array[i] << ", ";
    cout << "\n";
}


void Challenge11()
{
    ifstream fileinput;

    fileinput.open("names.txt");

    if (fileinput.fail())
    {
        cout << "\nERROR: File cannot be found.\n";
        return;
    }

    vector<string> namelist;

    string name;
    while (fileinput >> name)
        namelist.push_back(name);

    fileinput.close();

    selectionSort(namelist);

    for (string name : namelist)
        cout << name << "\n";
}

