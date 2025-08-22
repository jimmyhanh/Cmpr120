//Hung Anh Ho
//3-28-2023
//Pattern Displays

#include <iostream>
using namespace std;

int main()
{
    char symbol = '+';

    //Pattern A
    cout << "------------------------\n";
    cout << "Patter A: \n";
    cout << "------------------------\n";
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << symbol;
        }
        cout << "\n";
    }

    //Pattern B
    cout << "\n------------------------\n";
    cout << "Patter B: \n";
    cout << "------------------------\n";
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 10; j >= i; j--)
        {
            cout << symbol;
        }
        cout << "\n";
    }

    return 0;
}