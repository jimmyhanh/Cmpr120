//Hung Anh Ho
//3-11-2023
//Chapter 3 - Challenge 3 - Test Average

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Input
    const int numOfScores = 5;

    float score_1;
    float score_2;
    float score_3;
    float score_4;
    float score_5;
    float average;
    float total;

    //Program
    cout << "\nThis program will calculate the average of 5 test scores.\n";
    cout << "\nPress enter to continue";
    cin.get();

    //Ask user for 5 test scores
    cout << "\nEnter score #1: ";
    cin >> score_1;
    cout << "\nEnter score #2: ";
    cin >> score_2;
    cout << "\nEnter score #3: ";
    cin >> score_3;
    cout << "\nEnter score #4: ";
    cin >> score_4;
    cout << "\nEnter score #5: ";
    cin >> score_5;

    //Calculate average test score
    total = score_1 + score_2 + score_3 + score_4 + score_5;
    average = total / numOfScores;

    //Output
    cout << setprecision(1) << fixed;
    cout << "\nThe average test score is ";
    cout << average << "\n";

    return 0;
}