//Hung Anh Ho
//3-28-2023
//Celsius to Fahrenheit table

#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    float Fahrenheit = 0;

    cout << "Celsius to Fahrenheit table";
    cout << "\n=======================================\n";
    cout << "Celsius\t\tFahrenheit";
    cout << "\n***************************************\n";

    cout << setprecision(1) << fixed << right << showpoint;
    cout.fill('0'); //Example page 266

    for (int Celsius = 0; Celsius <= 20; Celsius++)
    {
        // Calculate Fahrenheit
        Fahrenheit = ((9.0 / 5) * Celsius) + 32;
        cout << setw(2) << Celsius << "\t\t" << Fahrenheit << "\n";
    }
    cout << "=======================================\n";

    return 0;
}