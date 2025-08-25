//Hung Anh Ho
//4-18-2023
//Chapter 6

#include "input.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Function prototypes
int menuOption();

//Challenge 3
double getSales(string);
void findHighest(double);
void Challenge3();

//Challenge 5
double fallingDistance(double);
void Challenge5();

//Challenge 7
double calculateCelsius(double);
void Challenge7();

//Challenge 9
double presentValue(double, double, double);
void Challenge9();

//Challenge 10
double futureValue(double, double, double);
void Challenge10();

//Challenge 11
double findLowest(double, double, double, double, double);
void calcAverage(double, double, double, double, double);
void Challenge11();

//Challenge 18
void Challenge18();


//Challenge 20
double calculateProfit(double, double, double, double);
void Challenge20();

//Challenge 23
bool isPrime(int, int );
void Challenge23();


//Challenge 24
void winnerSelection(int);
void Challenge24();

int main()
{
    do
    {
        switch (menuOption())
        {
        
            case 0: exit(1); break;
            case 3: Challenge3(); break;
            case 5: Challenge5(); break;
            case 7: Challenge7(); break;
            case 9: Challenge9(); break;
            case 10: Challenge10(); break;
            case 11: Challenge11(); break;
            case 18: Challenge18(); break;
            case 20: Challenge20(); break;
            case 23: Challenge23(); break;
            case 24: Challenge24(); break;
        
            default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        
        system("pause");

    } while (true);

    return EXIT_SUCCESS;

}
//menuOption get user's option and return the value - int type
int menuOption()
{
    system("cls");
    cout << "\n\t\tChapter 6: Functions (page 372-380) by Hung Anh Ho";
    cout << "\n\t" + string(60, char(205));
    cout << "\n\t\t  3. Winning Division          ";
    cout << "\n\t\t  5. Falling Distance          ";
    cout << "\n\t\t  7. Celsius Temperature Table ";
    cout << "\n\t\t  9. Present Value             ";
    cout << "\n\t\t  10. Future Value             ";
    cout << "\n\t\t  11. Lowest Score Drop        ";
    cout << "\n\t\t  18. Paint Job Estimator      ";
    cout << "\n\t\t  20. Stock Profit             ";
    cout << "\n\t\t  23. Prime Number List        ";
    cout << "\n\t\t  24. Rock, Paper, Scissors Game";
    cout << "\n\t" + string(60, char(196));
    cout << "\n\t\t  0. Quit";
    cout << "\n\t" + string(60, char(205));

    int option = inputInteger("\n\t\t  Option: ", 0, 24);

    return option;
}


//getSales get user input and return user input
double getSales(string division)
{
    double sales = inputDouble("\n\t\tEnter the " + division + " division quarterly sales: ", true);
    return sales;
}

//findHighest accepts the value of sales of all branches and return the highest branch
void findHighest(double sales1, double sales2, double sales3, double sales4)
{
    double highest = sales1;
    highest = sales2 >= highest ? sales2 : highest;
    highest = sales3 >= highest ? sales3 : highest;
    highest = sales4 >= highest ? sales4 : highest;
    highest = sales1 >= highest ? sales1 : highest;

    //COmparision of division
    if (sales1 == highest)
    {
        if (sales2 == sales1) //In case of equals
            cout << "\n\t*  NorthEast and SouthEast are the highest.\n";

        else if (sales3 == sales1)
            cout << "\n\t*  NorthEast and NorthWest are the highest.\n";

        else if (sales4 == sales1)
            cout << "\n\t*  NorthEast and SouthEast are the highest.\n";

        else
            cout << "\n\t*  NorthEast are the highest.";
    }

    else if (sales2 == highest)
    {
        if (sales2 == sales1) //In case of equals
            cout << "\n\t*  SouthEast and NorthEast are the highest.\n";

        else if (sales2 == sales3)
            cout << "\n\t*  SouthEast and NorthWest are the highest.\n";

        else if (sales2 == sales4)
            cout << "\n\t*  SouthEast and SouthWest are the highest.\n";

        else
            cout << "\n\t*  SouthEast is the highest.\n";
    }

    else if (sales3 == highest)
    {
        if (sales3 == sales1) //In case of equals
            cout << "\n\t*  NorthWest and NorthEast are the highest.\n";

        else if (sales3 == sales2)
            cout << "\n\t*  NorthWest and SouthEast are the highest.\n";

        else if (sales3 == sales4)
            cout << "\n\t*  NorthWest and SouthWest are the highest.\n";

        else
            cout << "\n\t*  NorthWest is the highest.\n";
    }

    else if (sales4 == highest)
    {
        if (sales4 == sales1) //In case of equals
            cout << "\n\t*  SouthWest and NorthEast are the highest.\n";

        else if (sales4 == sales2)
            cout << "\n\t*  SouthWest and SouthEast are the highest.\n";

        else if (sales4 == sales3)
            cout << "\n\t*  SouthWest and NorthWest are the highest.\n";

        else
            cout << "\n\t*  SouthWest is the highest.\n";
    }
}

void Challenge3()
{
    system("cls");
    cout << "\n\t\tChallenge 3: Winning Division\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    //Input
    double NorthEast_sales = getSales("NorthEast");
    double SouthEast_sales = getSales("SouthEast");
    double NorthWest_sales = getSales("NorthWest");
    double SouthWest_sales = getSales("SouthWest");

    //Output
    findHighest(NorthEast_sales, SouthEast_sales, NorthWest_sales, SouthWest_sales);
}



//FallingDistance accept the falling time and return the falling distance - double type
double fallingDistance(double falling_time)
{
    const double gravity = 9.8;
    return (0.5) * gravity * pow(falling_time, 2);
}

void Challenge5()
{
    double distance;
    double time;

    system("cls");
    cout << "\n\t\tChallenge 5: Falling Distance\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    //Display
    cout << setprecision(3) << fixed << showpoint;
    for (int i = 0; i < 10; i++)
    {
        time = i;
        distance = fallingDistance(time);

        cout << "\n\t\tAt " << time << " seconds =  " << distance << " (meters)\n";
    }
}



//calculateCelsius accepts Fahrenheit and return value in Celsius - double type
double calculateCelsius(double Fahrenheit)
{
    return 5.0 / 9 * (Fahrenheit - 32);
}

void Challenge7()
{
    system("cls");
    cout << "\n\t\tChallenge 7: Celsius Temperature Table\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    double Fahrenheit = inputDouble("Enter the your temperatur in Fahrenheit: ", true);

    //Display
    cout << setprecision(3) << fixed << showpoint;
    cout << "\n\t\tFahrenheit" << "\t" << char(186) << "\t" << "Celsius\n";
    cout << "\t\t" << string(31, char(196)) << "\n";

    //Output
    for (int i = 0; i <= Fahrenheit; i++)
    {
        cout << "\n\t\t" << i << "\t\t" << char(186) << "\t" << calculateCelsius(i);
    }
}



//presentValue accept the future value, annual interest and number of years to return the present value needed - double type
double presentValue(double FutureValue, double annualInterest, double numberOfYears)
{
    annualInterest /= 100 ;
    return FutureValue / pow((1 + annualInterest), numberOfYears);
}

void Challenge9()
{
    system("cls");
    cout << "\n\t\tChallenge 9: Present value\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    double PresentValue;
    double FutureValue;
    double annualInterest;
    double numberOfYears;

    char user_choice;

    do 
    {
        //input
        annualInterest = inputDouble("\tEnter the annual interest rate: ", true);
        FutureValue = inputDouble("\tEnter is the future value: ", true);
        numberOfYears = inputDouble("\tEnter is the number of years: ", true);
        PresentValue = presentValue(FutureValue, annualInterest, numberOfYears);

        //output
        cout<< setprecision(2) << fixed << showpoint;
        cout << "\tThe present value should be: $" << PresentValue << '\n';

        //Try again
        user_choice = inputChar("\tTry again? (y/n):");

    } while (user_choice == 'y' || user_choice == 'Y');

}

//presentValue accept the present value, annual interest and number of years to return the future value - double type
double futureValue(double presentValue, double monthly_interest_rate, double number_of_months)
{
    monthly_interest_rate /= 100 ;

    return presentValue * pow ((1 + monthly_interest_rate), number_of_months);
}

void Challenge10()
{
    system("cls");
    cout << "\n\t\tChallenge 10: Future value\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    double PresentValue;
    double FutureValue;
    double monthly_interest_rate;
    double number_of_months;

    char user_choice;

    do 
    {
        //input
        monthly_interest_rate = inputDouble("\tEnter the monthly interest rate: ", true);
        PresentValue = inputDouble("\tEnter is the present value: ", true);
        number_of_months = inputDouble("\tEnter is the number of months: ", true);
        FutureValue = presentValue(PresentValue, monthly_interest_rate, number_of_months);

        //output
        cout<< setprecision(2) << fixed << showpoint;
        cout << "\tThe future value should be: $" << PresentValue << '\n';

        //Try again
        user_choice = inputChar("\tTry again? (y/n):");

    } while (user_choice == 'y' || user_choice == 'Y');
}




//findLowest accepts the 5 scores and return the lowest - double type
double findLowest(double num1, double num2, double num3, double num4, double num5)
{
    double lowest = num1;
    num2 <= lowest ? lowest = num2: lowest = lowest;
    num3 <= lowest ? lowest = num3: lowest = lowest;
    num4 <= lowest ? lowest = num4: lowest = lowest;
    num5 <= lowest ? lowest = num5: lowest = lowest;

    return lowest;
}

//calcAverage get all the scores and validate to take out the lowest and return the average-double type
void calcAverage(double num1, double num2, double num3, double num4, double num5)
{
    double average;
    double lowest = findLowest(num1, num2, num3, num4, num5);
        
    if (num1 == lowest)
        average = (num2 + num3 + num4 + num5) / 4.0;
    else if (num2 == lowest)
        average = (num1 + num3 + num4 + num5) / 4.0;
    else if (num3 == lowest)
        average = (num1 + num2 + num4 + num5) / 4.0;
    else if (num4 == lowest)
        average = (num1 + num2 + num3 + num5) / 4.0;
    else if (num5 == lowest)
        average = (num1 + num2 + num3 + num4) / 4.0;
    
    cout << setprecision(2) << fixed << showpoint;
    cout << "\n\tThe average is: " << average << "\n";
}

void Challenge11()
{
    system("cls");
    cout << "\n\t\tChallenge 11: Lowest Score Drop\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    double score1;
    double score2;
    double score3;
    double score4;
    double score5;

    score1 = inputDouble("\n\tEnter score number 1: ", 0.0, 100.0);
    score2 = inputDouble("\n\tEnter score number 2: ", 0.0, 100.0);
    score3 = inputDouble("\n\tEnter score number 3: ", 0.0, 100.0);
    score4 = inputDouble("\n\tEnter score number 4: ", 0.0, 100.0);
    score5 = inputDouble("\n\tEnter score number 5: ", 0.0, 100.0);

    calcAverage(score1, score2, score3, score4, score5);
}



//constants for challenge 18
const double spare_feet_of_wall_space = 110.00;
const double gallon_of_paint = 1.00;
const double hour_of_labor = 8.00;
const double charges_per_hour = 25.00;

//getSpaceCost accept paint area, paint cost, paint needed and calculate the total paint, display  and return the value-double type
void getSpaceCost(double paintArea, double paintCost, double paintNeeded, double& totalPaint)
{

    paintNeeded = paintArea / spare_feet_of_wall_space * gallon_of_paint;
    totalPaint = paintNeeded * paintCost;

    cout << "\n\tGallons of paint you will need: " << paintNeeded;
    cout << "\n\tYour total paint cost will be: $" << totalPaint << "\n";
}

//getWorkCost accepts hours, hour cost and space to paint, then calculate the hour cost and display
void getWorkCost(double hours, double hourCost, double spaceToPaint)
{

    hours = (spaceToPaint / spare_feet_of_wall_space) * hour_of_labor;
    hourCost = hours * charges_per_hour;

    cout << "\n\tThe number of hours for the job will be: " << hours << "(hours)";
    cout << "\n\tThe total amount of wages will be: $" << hourCost << "\n";

}

//totalJobCost accepts total paint, hour cost, total cost and return the value of hour cost and display-double type
void totalJobCost(double totalpaint, double& hourCost, double totalJobCost)
{                        
    totalJobCost =  totalpaint + hourCost;

    cout << "\n\tThe total price of your paint job will be: $" << totalJobCost << "\n";
}

void Challenge18()
{
    double area_to_paint;
    double paintCost = 0;
    double paintNeeded = 0;
    double allPaintCost = 0;
    double hoursNeeded = 0;
    double hoursWages = 0;
    double allWages = 0;
    double allJobCost = 0;

    //Input
    area_to_paint =  inputDouble("\n\tEnter the square footage you need to paint: ", true );
    paintCost = inputDouble("\n\tEnter the price by gallons of paint you will use (cannot be less than 10): ", 10.0, true);

    //Output
    getSpaceCost(area_to_paint,paintCost, paintNeeded, allPaintCost);
    getWorkCost(hoursNeeded, hoursWages, area_to_paint);
    totalJobCost(allPaintCost, hoursWages, allJobCost);

}


//calculateProfit accepts number of shares, sales price per share, sales commission and purchase price per share to return profit-double type
double calculateProfit(double number_of_shares, double sales_price_per_share, double sales_commission, double purchase_price_per_share, double purchase_commision)
{

    double profit = ((number_of_shares * sales_price_per_share) - sales_commission) - (((number_of_shares * purchase_price_per_share) + purchase_commision));

    return profit;
}

void Challenge20()
{
    system("cls");
    cout << "\n\t\tChallenge #23: Stock Profit.\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    //Input
    double number_of_shares = inputDouble("\n\tEnter the number of shares: ", true);
    double sales_price_per_share = inputDouble("\tEnter the sales price per share: ", true);
    double sales_commission = inputDouble("\tEnter the price commission: ", true);
    double purchase_price_per_share = inputDouble("\n\tEnter the purchase price per share: ", true);
    double purchase_commision = inputDouble("\tEnter the purchase commission: ", true);

    //Calculate
    double profit = calculateProfit( number_of_shares, sales_price_per_share, sales_commission,  purchase_price_per_share, purchase_commision);

    //Compare and output
    if (profit > 0)
    {
        cout << "\n\tYou have gained profit of " << profit << "(dollars)\n";
    }

    else if (profit == 0)
    {
        cout << "\n\tYou have gained nothing\n";
    }

    else
    {
        cout << "\n\tYou have lost " << profit << "(dollars)\n";
    }
}



// isPrime function accept number and return true if the number is a prime number
// Return boolean True-False
bool isPrime(int number)
{
    int isPrime = 0;

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
            isPrime++;
    }

    return isPrime == 2 ? 1 : 0;

}

//Challenge 23 write number into a file from 1-100
void Challenge23()
{
    system("cls");
    cout << "\n\t\tChallenge #23: Stock Profit.\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    //Open
    ofstream outputFile;
    outputFile.open("primeNumber.txt");

    //Process
    if (outputFile)
    {
        for (int i = 1; i <= 100; i++)
        {
            if(isPrime(i))
                outputFile << i << "\n";
        }

        outputFile.close();

        cout << "\n\t\tNumbers written to file.\n";
    }

    else
        cout << "\n\t\tError opening the file.\n";
}



//winnerSelection accepts user input and computer input to decide the winner
void winnerSelection(int user_choice, int computer_choice)
{
    //Rock
    if (user_choice == 1)
    {
        if (computer_choice == 2)
        {
            cout << "\n\tComputer chose Paper, therefore computer won...\n";
        }

        else if (computer_choice == 3)
        {
            cout << "\n\tComputer chose Scissors, therefore you won...\n";
        }
    }

    //Paper
    if (user_choice == 2)
    {
        if (computer_choice == 1)
        {
            cout << "\n\tComputer chose Rock, therefore you won...\n";
        }

        else if (computer_choice == 3)
        {
            cout << "\n\tComputer chose Scissors, therefore computer won...\n";
        }
    }

    //Scissor
    if (user_choice == 3)
    {
        if (computer_choice == 1)
        {
            cout << "\n\tComputer chose Rock, therefore computer won...\n";
        }

        else if (computer_choice == 2)
        {
            cout << "\n\tComputer chose Paper, therefore you won...\n";
        }
    }
}

void Challenge24()
{
    system("cls");
    cout << "\n\t\tChallenge #24: Rock, Paper , Scissor Game\n";
    cout << "\t" << string(60, char(205)) << "\n";
    cout << "\t" << string(60, char(196)) << "\n";

    char user_choice;
    do 
    {
        do
        {
            //Input
            srand(time(0));
            int computerOption = rand() % 3 + 1;
            int userOption = inputInteger("\n\tEnter 1 - rock, 2 - paper, or 3 - scissors: ", 1, 3);


            //Compare
            if (userOption == computerOption)
                cout << "\n\tIt's a tie. play again...\n";
            else
            {
                //Display
                winnerSelection(userOption, computerOption);
                break;
            } 

        } while (true);

        //Try again
        user_choice = inputChar("\n\tTry again? (y/n): ");

    } while (user_choice == 'y' || user_choice == 'Y');

}
