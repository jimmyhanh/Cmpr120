//Hung Anh Ho
//5-24-2023
//CHapter9

#include <iostream>
#include <string>
#include <algorithm>
#include "input.h"
using namespace std;

void Challenge2();
int* reverseArray(int* array, int size);

void Challenge4();
void getArrayElements(double *, string *, const int);
void displayArray(double *, string *, const int);
void selectionSort(double *, string *, const int);
double averageArrayElements(double *, const int);
void swap(double *, double *);
void swap(string *, string *);

void Challenge7();
void arrSelectSort(int* arr[], int size);
void showArray(const int arr[], int size);
void showArrPtr(int* arr[], int size);

void Challenge10();

void Challenge11();
int *doubleArraySize(int [], const int);
void displayArray(int *, const int);

void Challenge13();
int inputValidation(int);
void getMovieInfo(int *, const int);
int getAverage(int *, const int);
int getMedian(int *, const int);
int getMode(int *, const int);

int main()
{
    do
    {
        system("cls");
        cout << "\n\t\tChapter 9: Pointers by Hung Anh Ho";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t\t  2. Test Score #1";
        cout << "\n\t\t  4. Test Score #2";
        cout << "\n\t\t  7. Case Study Modification #2";
        cout << "\n\t\t 10. Reverse Array";
        cout << "\n\t\t 11. Array Expander";
        cout << "\n\t\t 13. Movie Statistics";
        cout << "\n\t" + string(60, char(196));
        cout << "\n\t\t  0. Quit";
        cout << "\n\t" + string(60, char(205));
        cout << "\n";

        switch (inputInteger("\t\t  Option: ", 0, 13))
        {
        case 0: exit(1); break;
        case 2: Challenge2(); break; //DONE
        case 4: Challenge4(); break; //Extra 20 pts
        case 7: Challenge7(); break; //DONE
        case 10: Challenge10(); break; //DONE
        case 11: Challenge11(); break;
        case 13: Challenge13(); break;
        default: cout << "\t\tERROR - Invalid option."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

void Challenge2()
{
    int size = inputInteger("\nEnter the size of the dynamic array: ", true);

    double* testScores = new double[size]; //dynamic allocate array 

    cout << "\nBefore...";

    double sum = 0.0;

    // input all scores and comut the sum of all scores
    for (int i = 0; i < size; i++)
    {
        *(testScores + i) = inputDouble("\nEnter the score[" + to_string(i + 1) + "] :", 0.0, 100.0);
        cout << *(testScores + i) << "\n";
        sum += *(testScores + i);
    }

    //calculate the average
    double average = sum / size;

    // sort the array in ascending order using function from algorithm library
    sort(testScores, testScores + size);

    cout << "\nAfter...";
    for (int i = 0; i < size; i++)
        cout << "\n" << *(testScores+i) << "\n";

    cout << "\nAverage: " << average << '\n';

    delete[] testScores; //deallocate (purge) the dynamic array
}
//reverseArray display array in reverse
int* reverseArray(int* array, int size)
{
    int* tempArray = new int[size];

    for (int i = 0; i < size; i++)
    {
        tempArray[i] = array[size - 1 - i];
    }

    return tempArray;
}



void Challenge4()
{
    int number_of_test_scores = inputInteger("Enter the number of test scores: ", 0, 100);

    double *test_scores = new double[number_of_test_scores];
    string *student_names = new string[number_of_test_scores];

    cout << "Enter each test score: " << "\n";
    getArrayElements(test_scores, student_names, number_of_test_scores);

    selectionSort(test_scores, student_names, number_of_test_scores);

    double average = averageArrayElements(test_scores, number_of_test_scores);

    cout << "\nSorted test scores:" << "\n";
    displayArray(test_scores, student_names, number_of_test_scores);

    //Return to default
    delete [] test_scores;
    test_scores = nullptr;
    delete [] student_names;
    student_names = nullptr;

    cout << "\nAverage = " << average << "\n";
}

//getArrayElements get input scores
void getArrayElements(double *array, string *student_names, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Student #" << (i + 1);
        *(student_names + i) = inputString(" name      : ", true); // student_names[i];

        cout << "Student #" << (i + 1);
        *(array + i) = inputInteger(" test score: ", 0, 100);
    }

}

//***********************************************************************
// The selectionSort function sorts a string vector in ascending order. *
//***********************************************************************
void selectionSort(double *array, string *student_names, const int SIZE)
{
    int start_index;
    int minIndex;
    double min_test_score;
    string min_test_score_name;

    for (start_index = 0; start_index < (SIZE - 1); start_index++)
    {
        minIndex = start_index;
        min_test_score = *(array + start_index);
        min_test_score_name = *(student_names + start_index); // student_names[start_index];

        for (int index = start_index + 1; index < SIZE; index++)
        {
            if (*(array + index) < min_test_score)
            {
                min_test_score = *(array + index);
                min_test_score_name = *(student_names + index);
                minIndex = index;
            }

        }
        swap(*(array + minIndex), *(array + start_index));
        swap(*(student_names + minIndex), *(student_names + start_index));
    }
}

//***************************************************
// The swap function swaps a and b in memory.       *
//***************************************************
void swap(string *a, string *b)
{
    string *temp = a;
    a = b;
    b = temp;
}

//***************************************************
// The swap function swaps a and b in memory.       *
//***************************************************
void swap(double *a, double *b)
{
    double *temp = a;
    a = b;
    b = temp;
}

//averageArrayElements return average score
double averageArrayElements(double *array, const int SIZE)
{
    double sum = 0;

    for (int i = 0; i < SIZE; i++)
        sum += *(array + i);

    return sum / SIZE;
}

//Display student scores
void displayArray(double *array, string *student_names, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Student #" << (i + 1) << " name      : " << *(student_names + i) << "\n";
        cout << "Student #" << (i + 1) << " test score: " << *(array + i) << "\n";
    }


}



void Challenge7()
{
    const int NUM_DONATIONS = 15;  // Number of donations

    // An array containing the donation amounts.
    int donations[NUM_DONATIONS] = { 5,  100, 5,  25, 10,
        5,  25,  5,  5,  100,
        10, 15,  10, 5,  10 };

    // An array of pointers to int.
    int* arrPtr[NUM_DONATIONS] = { nullptr, nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr, nullptr, nullptr };

    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];

    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, NUM_DONATIONS);

    //sort(donations, donations + NUM_DONATIONS); //DOES NOT WORK!!!

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in descending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
}



void Challenge10()
{
    srand(time_t(0));
    int SIZE = inputInteger("\nEnter a size of array: ", true);

    int* array = new int[SIZE];             //allocate a new original dynamic array of SIZE

    cout << "\nOriginal array:\n";

    //populate with random number element into the array and display
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100 + 1;
        cout << array[i] << " ";
    }
    cout << '\n';

    int* newArray = reverseArray(array, SIZE); //allocate a new reverse array of SIZE

    cout << "\nNew Reversed array:\n";
    //display the new reversed array
    for (int i = 0; i < SIZE; i++)
    {
        cout << newArray[i] << " ";
    }
    cout << "\n";

    //deallocate all dynamic arrays
    delete[] array;
    delete[] newArray;
}

//****************************************************************
// Definition of function arrSelectSort.                         *
// This function performs an ascending order selection sort on   *
// arr, which is an array of pointers. Each element of array     *
// points to an element of a second array. After the sort,       *
// arr will point to the elements of the second array in         *
// ascending order.                                              *
//****************************************************************
void arrSelectSort(int* arr[], int size)
{
    int startScan, minIndex;
    int* minElem;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (*(arr[index]) > *minElem)
            {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of arr. size is the    *
// number of elements.                                        *
//*************************************************************
void showArray(const int arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << "\n";
}

//**************************************************************
// Definition of function showArrPtr.                          *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements.                     *
//**************************************************************
void showArrPtr(int* arr[], int size)
{
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << "\n";
}

void Challenge11()
{
    const int SIZE = 5;
    int numbers[SIZE] = { 6, 7, 6, 8, 18 };

    int *numbers_doubled = doubleArraySize(numbers, SIZE);

    displayArray(numbers, SIZE);
    cout << "\n";

    //new array
    cout << "Array wit a new size that twice the old one: ";
    displayArray(numbers_doubled, (SIZE * 2));
    cout << "\n\n";

    delete [] numbers_doubled;
    numbers_doubled = nullptr;
}

// *doubleArraySize Double the new array size
int *doubleArraySize(int array[], const int SIZE)
{
    const int NEW_SIZE = SIZE * 2;
    int *newArray = new int[NEW_SIZE];

    for (int i = 0; i < NEW_SIZE; i++)
    {
        if (i >= SIZE)
            *(newArray + i) = 0;
        else
            *(newArray + i) = array[i];
    }

    return newArray;
}

//displayArray display the array
void displayArray(int *array, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << *(array + i) << " "; // array[i]
}



void Challenge13()
{
    int number_of_students = inputInteger("How many students surveyed? ", true);
    int *movieInfo = new int[number_of_students];

    getMovieInfo(movieInfo, number_of_students);

    int average = getAverage(movieInfo, number_of_students);
    int median = getMedian(movieInfo, number_of_students);
    int mode = getMode(movieInfo, number_of_students);

    cout << "Average = " << average << "\n";
    cout << "Median = " << median << "\n";

    cout << "Mode = ";
    if (mode != -1)
        cout << mode;
    else
        cout << "no mode";
    cout << "\n";

    delete [] movieInfo;
    movieInfo = nullptr;
}

//getAverage calculate and reutrn average
int getAverage(int *array, const int SIZE)
{
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
        sum += *(array + i); // array[i]

    return sum/SIZE;
}

//getMedian return median
int getMedian(int *array, const int SIZE)
{
    int median = 0;

    if (SIZE % 2 != 0)
        median = *(array + (SIZE / 2)); // array[SIZE / 2]
    else
        median = (*(array + ((SIZE - 1) / 2)) + *(array + (SIZE / 2))) / 2;

    return median;
}

//getMode return mode
int getMode(int *array, const int SIZE)
{
    int mode, maxCount = 0, i, j;

    for (i = 0; i < SIZE; i++)
    {
        int count = 0;

        for (j = 0; j < SIZE; j++)
        {
            if (*(array + j) == *(array + i)) // array[j] == array[i]
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            mode = *(array + i);
        }
        else if (maxCount == 1)
        {
            mode = -1;
        }
    }

    return mode;
}

//getMode return mode
void getMovieInfo(int *movieInfo, const int number_of_students)
{
    cout << "Enter number of movies watched: " << "\n";
    for (int i = 0; i < number_of_students; i++)
    {
        *(movieInfo + i) = inputInteger("\nStudent #" + to_string(i + 1) + ": ", true);
    }
}