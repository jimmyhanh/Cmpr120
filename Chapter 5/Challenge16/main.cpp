//Hung Anh Ho
//3-28-2023
//Saving Account balance

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Number of months per year
    const int months = 12;

    //Annual interest rate
    double annual_interest_rate;
    do
    {
        cout << "\nEnter annual interest rate: ";
        cin >> annual_interest_rate;

        //Validate
        if (annual_interest_rate < 0)
        {
            cout << "Invalid input! Number cannot be less than 0. Try again.";
        }
        else
            break;

    } while (true);


    //Variables
    double amount_deposited = 0.0;
    double amount_withdrawn = 0.0;

    double total_deposits = 0.0;
    double total_withdrawn = 0.0;
    double total_interest_earned = 0.0;

    //User's starting balance
    double starting_balance = 0.0;
    double balance = 0.0;

    do
    {
        cout << "\nEnter your starting balance: ";
        cin >> starting_balance;

        //Validate
        if (annual_interest_rate < 0)
        {
            cout << "Invalid input! Number cannot be less than 0. Try again.";
        }
        else
        {
            balance = starting_balance;
            break;
        }

    } while (true);

    int months_since_established;
    do
    {
        cout << "Enter number of months passed since account was established: ";
        cin >> months_since_established;

        //Validate
        if (months_since_established < 0)
        {
            cout << "Invalid input! Number cannot be less than 0. Try again.";
        }
        else
        {
            break;
        }

    } while (true);

    //Calculate monthly interest
    double interest_rate;
    double monthly_interest_rate;
    monthly_interest_rate = annual_interest_rate / months;

    for (int i = 0; i < months_since_established; i++)
    {
        do
        {
            cout << "Enter the amount deposited for month #" << i + 1 << ": ";
            cin >> amount_deposited;

            //Validate
            if (amount_deposited < 0)
            {
                cout << "Invalid input! Number cannot be less than 0. Try again.";
            }

            else
            {
                //Update the balance for added amount
                total_deposits += amount_deposited;
                balance += amount_deposited;
                break;
            }

        } while (true);


        do
        {
            cout << "Enter the amount withdrawn for month #" << i + 1 << ": ";
            cin >> amount_withdrawn;

            //Validate
            if (amount_withdrawn < 0)
            {
                cout << "Invalid input! Number cannot be less than 0. Try again.";
            }

            else if (amount_withdrawn > balance)
            {
                cout << "Invalid input! Number cannot be more than the starting balance of. $" <<  balance;
            }

            else
            {
                //Update balance after withdrawn
                total_withdrawn += amount_withdrawn;
                balance -= amount_withdrawn;
                break;
            }

        } while (true);

        //Calculates interest
        interest_rate = (monthly_interest_rate/ 100 * balance);
        balance += interest_rate;

        //Validate balance
        if (balance < 0)
            break;

        //Total balance after interest
        total_interest_earned += (interest_rate);
    }

    //Balance validate
    if (balance < 0)
    {
        cout << "Your account has negative balance. Cannot withdrawn anymore.\n"; 
    }

    else
    {
        cout << setprecision(2) << fixed << showpoint;
        cout << "\nStarting balance            = $" << starting_balance;
        cout << "\nEnding balance              = $" << balance;
        cout << "\nTotal amount in deposits    = $" << total_deposits;
        cout << "\nTotal amount in withdrawals = $" << total_withdrawn;
        cout << "\nTotal interest earned       = $" << total_interest_earned;
    }

    return 0;
}