//Hung Anh Ho
//4-29-2023
//Exam 2

#include <Windows.h>
#include <cmath>
#include <iostream>         // console input/output library
#include<iomanip>           // input/output manipulation library
#include<fstream>           // file input/output library
#include <vector>           // dynamic array(vector) library
#include "input.h"          // input validate functions library create by Prof Q
using namespace std;

const double PI = 3.14159;

//prototype functions
char mainMenuOption();

void storeDataCircleShapes(vector <double>& array);
double getArea(double radius, double pi);
double getPerimeter(double radius, double pi);
void displayCircleShapes(vector <double> array, ostream& out);

void inputDataEquilateralTriangleShapes(vector <double>& vT);
double getArea(double side);
double getPerimeter(double size);
void displayEquilateralTriangleShapes(const vector <double> vT, ostream& out);

void storeDataAnnulusShapes(vector<vector<double>>& vA);
double getArea(double outerRadius, double innerRadius, double pi);
double getPerimeter(double outerRadius, double innerRadius, double pi);
void displayAnnulusShapes(vector<vector<double>> vA, ostream& out);

void inputDataHeartShapes(vector <double>& vH);
double getAreaHeart(double side);
double getPerimeterHeart(double size);
void displayHeartShapes(vector <double> vH, ostream& out);

void inputDataRegularPolygonShapes(vector <vector<double>>& vP);
double getArea(double sideLength, int numberSides, double pi);
double getPerimeter(double sideLength, int numberSides);
void displayRegularPolygonShapes(vector <vector<double>> vP, ostream& out);

//Case F
const int numberOfShapes = 5;
const int variables = 3;
double largestShape[numberOfShapes][variables];
double smallestShape[numberOfShapes][variables];

int main()
{
    vector<double> equilateralTriangleArray;

    vector<double> circleArray; //decalre a dynamic array(vector) contains data(radii) of circles

    vector<vector<double>> annulusArray; //decalre a dynamic array(vector) contains data(radii) of annuluses

    vector<double> heartArray;

    vector<vector<double>> polygonArray;

    do
    {
        switch (toupper(mainMenuOption()))
        {
            case 'X': //exit option to terminate the program
            {
                exit(0);
                break;
            }


            case 'T': //Triangle option
            {
                bool storeDataCount = false; // Check for entering data before execute

                do
                {

                    system("cls");

                    // display sub menu option
                    cout << "\n\tEquilateral Triangles Menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";
                    cout << "\n\t1. Input from a file";
                    cout << "\n\t2. Output to console";
                    cout << "\n\t" << string(90, char(196)) << "\n";
                    cout << "\n\t0. return main menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";

                    int option = inputInteger("\tOption: ", 0, 2);
                    if (option == 0) break;
                    else if (option == 1)
                    {
                        inputDataEquilateralTriangleShapes(equilateralTriangleArray);     //call function to store data from file into the array(vector)
                        storeDataCount = true;
                    }

                    else
                    {
                        if (storeDataCount == true)
                        {
                            displayEquilateralTriangleShapes(equilateralTriangleArray, cout); //call function to display data from the array(vector) and calcuations
                        }

                        else
                        {
                            cout << "\n\tNo data has been entered. Please go back to step 1.\n";
                        }
                    }


                    system("pause");

                } while (true);

                break;
            }


            case 'C': //circle option
            {
                bool storeDataCount = false; // Check for entering data before execute

                do
                {
                    system("cls");

                    // display sub menu option
                    cout << "\n\tCircle Shape Menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";
                    cout << "\n\t1. Input from a file";
                    cout << "\n\t2. Output to console";
                    cout << "\n\t" << string(90, char(196)) << "\n";
                    cout << "\n\t0. return main menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";

                    int option = inputInteger("\tOption: ", 0, 2);

                    if (option == 0) break;

                    else if (option == 1)
                    {
                        storeDataCircleShapes(circleArray);
                        storeDataCount = true;//call function to store data from file into the array(vector)
                    }

                    else
                    {
                        if (storeDataCount == true)
                        {
                            displayCircleShapes(circleArray, cout); //call function to display data from the array(vector) and calcuations
                        }

                        else
                        {
                            cout << "\n\tNo data has been entered. Please go back to step 1.\n";
                        }
                    }

                    system("pause");

                } while (true);

                break;
            }

            case 'A': //Annuluses option
            {
                bool storeDataCount = false; // Check for entering data before execute

 
                do
                {
                    system("cls");

                    // display sub menu option
                    cout << "\n\tAnnulus Shape Menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";
                    cout << "\n\t1. Input from a file";
                    cout << "\n\t2. Output to console";
                    cout << "\n\t" << string(90, char(196)) << "\n";
                    cout << "\n\t0. Return main menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";

                    int option = inputInteger("\tOption: ", 0, 2);
                    if (option == 0) break;
                    else if (option == 1)
                    {
                        storeDataAnnulusShapes(annulusArray);     //call function to store data from file into the array(vector)
                        storeDataCount = true;
                    }

                    else
                    {
                        if (storeDataCount == true)
                        {
                            displayAnnulusShapes(annulusArray, cout); //call function to display data from the array(vector) and calcuations
                        }

                        else
                        {
                            cout << "\n\tNo data has been entered. Please go back to step 1.\n";
                        }
                    }

                    system("pause");

                } while (true);

                break;
            }

            case 'H': //heart option
            {
                bool storeDataCount = false; // Check for entering data before execute

                do
                {
                    system("cls");

                    // display sub menu option
                    cout << "\n\tHeart Shape Menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";
                    cout << "\n\t1. Input from a file";
                    cout << "\n\t2. Output to console";
                    cout << "\n\t" << string(90, char(196)) << "\n";
                    cout << "\n\t0. return main menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";

                    int option = inputInteger("\tOption: ", 0, 2);

                    if (option == 0) break;

                    else if (option == 1)
                    {
                        inputDataHeartShapes(heartArray);
                        storeDataCount = true;//call function to store data from file into the array(vector)
                    }

                    else
                    {
                        if (storeDataCount == true)
                        {
                            displayHeartShapes(heartArray, cout); //call function to display data from the array(vector) and calcuations
                        }

                        else
                        {
                            cout << "\n\tNo data has been entered. Please go back to step 1.\n";
                        }
                    }

                    system("pause");

                } while (true);

                break;
            }

            case 'P': //polygon option
            {
                bool storeDataCount = false; // Check for entering data before execute

                do
                {
                    system("cls");

                    // display sub menu option
                    cout << "\n\tRegular Polygons Shape Menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";
                    cout << "\n\t1. Input from a file";
                    cout << "\n\t2. Output to console";
                    cout << "\n\t" << string(90, char(196)) << "\n";
                    cout << "\n\t0. return main menu";
                    cout << "\n\t" << string(90, char(205)) << "\n";

                    int option = inputInteger("\tOption: ", 0, 2);

                    if (option == 0) break;

                    else if (option == 1)
                    {
                        inputDataRegularPolygonShapes(polygonArray);
                        storeDataCount = true;//call function to store data from file into the array(vector)
                    }

                    else
                        if (storeDataCount == true)
                        {
                            displayRegularPolygonShapes(polygonArray, cout); //call function to display data from the array(vector) and calcuations
                        }

                        else
                        {
                            cout << "\n\tNo data has been entered. Please go back to step 1.\n";
                        }

                    system("pause");

                } while (true);

                break;
            }

            case 'O':
            {
                system("cls");
                ofstream outputFile;

                //Validate for data to be written
                if (circleArray.empty() && equilateralTriangleArray.empty() && heartArray.empty() && annulusArray.empty() && polygonArray.empty())
                {
                    cout << "\n\tERROR. No data detected\n";
                    system("pause");
                    break;
                }

                //prompt for a data file name
                string fileName = inputString("\n\tEnter a data file name (AllSHAPES.TXT): ", true);

                //open the data file to read 
                outputFile.open(fileName);

                //validate if the file exists
                if (outputFile)
                {
                    cout << "\n\t " << fileName << ", was found.\n";
                    char userInput = inputChar("\tDo you want to overwrite? (Y/N) ", "YN");

                    if (userInput == 'N')
                    {
                        break;
                    }

                    else
                    {
                        // write data and store into the array(vector)
                        if (!circleArray.empty())
                        {
                            displayCircleShapes(circleArray, outputFile);
                        }

                        if (!equilateralTriangleArray.empty())
                        {
                            displayEquilateralTriangleShapes(equilateralTriangleArray, outputFile);
                        }

                        if (!heartArray.empty())
                        {
                            displayHeartShapes(heartArray, outputFile);
                        }

                        if (!annulusArray.empty())
                        {
                            displayAnnulusShapes(annulusArray, outputFile);
                        }

                        if (!polygonArray.empty())
                        {
                            displayRegularPolygonShapes(polygonArray, outputFile);
                        }

                        outputFile.close();

                        //prompt the user of completion

                        cout << "\n\tData from the file have been written into the vector array.\n\n";
                    }
                }
                system("pause");
                break;
            }

            case'F':
            {
                if (circleArray.empty() && equilateralTriangleArray.empty() && heartArray.empty() && annulusArray.empty() && polygonArray.empty())
                {
                    cout << "\n\tERROR. NO data detected\n";
                    system("pause");
                    break;
                }

                else
                {
                    double smallest = NULL;
                    int smallestIndex = 0;

                    for (int i = 0; i < numberOfShapes; i++)
                    {
                        if (smallestShape[i][1] > 0)
                        {
                            if (smallest == NULL)
                            {
                                smallestIndex = i;
                                smallest = smallestShape[i][1];
                            }

                            else if (smallest > smallestShape[i][1])
                            {
                                smallestIndex = i;
                                smallest = smallestShape[i][1];
                            }
                        }
                    }

                    if(smallestIndex == 0)
                    {
                        cout << "\n\t\tThe smallest shape:  " << "\033[92m" << "Equilateral Triangle " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(smallestShape[0][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << smallestShape[0][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << smallestShape[0][2];
                    }

                    else if(smallestIndex == 1)
                    {
                        cout << "\n\t\tThe smallest shape:" << "\033[95m" << "Circle " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(smallestShape[1][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << smallestShape[1][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << smallestShape[1][2];
                    }

                    else if(smallestIndex == 2 )
                    {
                        cout << "\n\t\tThe smallest shape:  " << "\033[93m" << "Annulus " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(smallestShape[2][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << smallestShape[2][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << smallestShape[2][2];
                    }


                    else if(smallestIndex == 3 )
                    {
                        cout << "\n\t\tThe smallest shape:  " << "\033[96m" << "Heart " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(smallestShape[3][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << smallestShape[3][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << smallestShape[3][2];
                    }

                    else if(smallestIndex == 4 )
                    {
                        cout << "\n\t\tThe smallest shape:  " << "\033[94m" << "Regular Polygon " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(smallestShape[4][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << smallestShape[4][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << smallestShape[4][2];                                          
                    }
                    cout << "\n";


                    double largest = NULL;

                    int largestIndex = 0;

                    for (int i = 0; i < numberOfShapes; i++)
                    {
                        if (largestShape[i][1] > 0)
                        {
                            if (largest == NULL)
                            {
                                largestIndex = i;
                                largest = largestShape[i][1];
                            }
                            else if (largest < largestShape[i][1])
                            {
                                largestIndex = i;
                                largest = largestShape[i][1];
                            }
                        }
                    }

                    if(largestIndex == 0 )
                    {
                        cout << "\n\t\tThe largest shape: " << "\033[92m" << "Equilateral Triangle " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(largestShape[0][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << largestShape[0][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << largestShape[0][2];
                    }

                    else if(largestIndex == 1)
                    {
                        cout << "\n\t\tThe largest shape: " << "\033[95m" << "Circle " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(largestShape[1][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << largestShape[1][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << largestShape[1][2];
                    }

                    else if(largestIndex == 2 )
                    {
                        cout << "\n\t\tThe largest shape: " << "\033[93m" << "Annulus " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(largestShape[2][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << largestShape[2][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << largestShape[2][2];
                    }


                    else if(largestIndex == 3 )
                    {
                        cout << "\n\t\tThe largest shape: " << "\033[96m" << "Heart " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(largestShape[3][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << largestShape[3][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << largestShape[3][2];
                    }

                    else if(largestIndex == 4 )
                    {
                        cout << "\n\t\tThe largest shape: " << "\033[94m" << "Regular Polygon " << "\033[0m" << "at index" << "\033[33m" << "[" << static_cast<int>(largestShape[4][0]) << "]" << "\033[0m";
                        cout << "\n\t\t________________________________________________________________________________\n";
                        cout << "\t\t\t     Area:" << setw(20) << largestShape[4][1];
                        cout << "\t\t\tPerimeter:" << setw(20) << largestShape[4][2];
                    }
                    cout << "\n";

                    system("pause");
                    break;
                }
            }
        }

    }while (true);

    return 0;
}

//precondition: none
//postcondition: display the banner and menu, prompt and return user option
char mainMenuOption()
{

    system("cls");
    cout << "\033[92m" << "                 T" << "\033[95m" << "                C.C.C" << "\033[93m" << "             A.A.A" << "\033[96m" << "          H.H     H.H" << "\033[94m" << "          PPP\n";
    cout << "\033[92m" << "                ..." << "\033[95m" << "            C.........C" << "\033[93m" << "       A.........A" << "\033[96m" << "     H.....H H.....H" << "\033[94m" << "     P.......P\n";
    cout << "\033[92m" << "              T.....T" << "\033[95m" << "        C.............C" << "\033[93m" << "   A.....a a.....A" << "\033[96m" << "   H......H......H" << "\033[94m" << "   P...........P\n";
    cout << "\033[92m" << "             ........." << "\033[95m" << "       C......+......C" << "\033[93m" << "   A....a + a....A" << "\033[96m" << "    H...........H" << "\033[94m" << "    P...........P\n";
    cout << "\033[92m" << "           T...........T" << "\033[95m" << "     C.............C" << "\033[93m" << "   A.....a a.....A" << "\033[96m" << "      H.......H" << "\033[94m" << "      P...........P\n";
    cout << "\033[92m" << "          ..............." << "\033[95m" << "      C.........C " << "\033[93m" << "      A.........A" << "\033[96m" << "          H...H" << "\033[94m" << "          P.......P\n";
    cout << "\033[92m" << "        T....T...T...T....T" << "\033[95m" << "       C.C.C" << "\033[93m" << "             A.A.A" << "\033[96m" << "               H" << "\033[94m" << "               PPP\n\n";
    cout << "\033[0m";


    cout << "\n\tThe Elements.This influenced the development of Western mathematics for more than 2000";
    cout << "\n\tyears.Geometry is a branch of mathematics that studies the sizes, shapes, positions";
    cout << "\n\tanglesand dimensions of things.";

    cout << "\n\tCMPR120 Exam2 : Chapter 5, 6, 7 and 7 Shape Geometry by Hung Anh Ho";
    cout << "\n\t==========================================================================================";
    cout << "\033[92m" << "\n\tT.Equilateral Triangles";
    cout << "\033[95m" << "\n\tC.Circles";
    cout << "\033[93m" << "\n\tA.Annuluses";
    cout << "\033[96m" << "\n\tH.Hearts";
    cout << "\033[94m" << "\n\tP.Regular Polygons";
    cout << "\033[0m"; // reset color
    cout << "\n\t------------------------------------------------------------------------------------------";
    cout << "\n\tO.Save ALL available shape information to a text file";
    cout << "\n\t------------------------------------------------------------------------------------------";
    cout << "\n\tF.Find and display the largest and smallest available shape(30 pts Extra)";
    cout << "\n\t------------------------------------------------------------------------------------------";
    cout << "\n\tX.Exit the program";
    cout << "\n\t==========================================================================================";

    //prompt the user for a valid option (char) and return
    return inputChar("\n\tOption: ", static_cast<string>("TCAHPOFX"));
}




//precondition: valid modifiable array(vector) pass by reference) 
//postcondition: return the calculated circumfernece (perimeter) of a triangle
void inputDataEquilateralTriangleShapes(vector <double>& array)
{
    ifstream inputfile;

    do
    {
        //prompt for a data file name
        string filename = inputString("\n\tEnter a data file name (TRIANGLES.TXT): ", true);

        //open the data file to read 
        inputfile.open(filename);

        //validate if the file exists
        if (inputfile.fail())
        {
            cout << "\n\tERROR: file, " << filename << ", cannot be found.\n\n";
        }
        else
            break;

    } while (true);

    // reset(clear) the array(vector) 
    array.clear();

    double value = 0.0;

    // read data and store into the array(vector)
    while (inputfile >> value)
        array.push_back(value);

    inputfile.close();

    //prompt the user of completion
    cout << "\n\tData from the file have been read into the vector array.\n\n";
}

//Get Area for triangles pass in side lengths and return area
double getArea(double side)
{
    return sqrt(3.0) / 4 * pow(side, 2);
}

//Get Perimeter for triangles pass in side lengths and return perimeter
double getPerimeter(double size)
{
    return 3.0 * size;
}

//precondition: valid modifiable array(vector) pass by reference) 
//postcondition: return the calculated circumfernece (perimeter) of a triangle
void displayEquilateralTriangleShapes(const vector <double> array, ostream& out)
{
    system("cls");

    // display pattern
    cout << "\033[92m"; out << "\n\t         T";
    cout << "\033[92m"; out << "\n\t       .....";
    cout << "\033[92m"; out << "\n\t      T.....T";
    cout << "\033[92m"; out << "\n\t    ...........";
    cout << "\033[92m"; out << "\n\t   T...........T"; cout << "\033[93m"; out << "     An equilateral triangle has all three sides of equal length";
    cout << "\033[92m"; out << "\n\t ................";
    cout << "\033[92m"; out << "\n\tT....T......T.....T";
    cout << "\033[0m" << "\n";
    out << fixed << showpoint << setprecision(2);

    out << "\n";
    int count = 0;
    double sumArea = 0.0;
    double sumPerimiter = 0.0;

    int largestIndex = 0;
    double largestTriangle = getArea(array[largestIndex]);

    int smallestIndex = 0;
    double smallestTriangle = NULL;

    // display colume headers
    out << "\n\t__________________________________________________________________________________________\n\n";
    out << setw(39) << right << "Array[index]" << setw(16) << right << "Side length" << setw(16) << right << "Area" << setw(16) << right <<"Perimeter" << "\n";
    out << "\t                _______________ _______________ _______________ _______________\n";

    //use the for loop to process all elements from the array(vector)
    for (int i = 0; i < array.size(); i++)
    {

        //validate only radius in non-negative value
        if (array[i] < 0.0)
        {
            cout << "\033[31m"; out << setw(39) << right << i << setw(16) << right << array[i];
            cout << "\033[31m"; out << " (Invalid)\n";
            cout << "\033[0m";
        }

        else
        {
            out << setw(39) << right << i << setw(16) << right <<  array[i];
            out << setw(16) << right << getArea(array[i]) << setw(16) << right << getPerimeter(array[i]) << '\n';

            count++;                            //keep track of how many valid data

            sumArea += getArea(array[i]);  // sum up all area
            sumPerimiter += getPerimeter(array[i]); // sum up all perimeter

            // keep track of the largest circle using its area
            if (getArea(array[i]) > largestTriangle)
            {

                largestIndex = i;
                largestTriangle = getArea(array[largestIndex]);
            }

            // keep track of the smallest circle using its area
            if (smallestTriangle == NULL)
            {
                smallestIndex = i;
                smallestTriangle = getArea(array[smallestIndex]);
            }

            else if (getArea(array[i]) < smallestTriangle)
            {

                smallestIndex = i;
                smallestTriangle = getArea(array[smallestIndex]);
            }

        }
    }

    //save smallest and biggest shapes
    smallestShape[0][0] = smallestIndex;
    smallestShape[0][1] = smallestTriangle;
    smallestShape[0][2] = getPerimeter(array[smallestIndex]);


    largestShape[0][0] = largestIndex;
    largestShape[0][1] = largestTriangle;
    largestShape[0][2] = getPerimeter(array[largestIndex]);;

    out << "\n\t__________________________________________________________________________________________\n";
    out << setw(55) << right << "Average:" << setw(16) << sumArea / count << setw(16) << sumPerimiter/count << "\n";

    cout << "\033[92m"; out << "\n\t\t\t" << "The largest shape found at index  "; cout << "\033[93m"; out << "[" << largestIndex << "]"; cout << "\033[0m";
    cout << "\033[92m"; out << "\n\t\t\t" << "The smallest shape found at index "; cout << "\033[93m"; out << "[" << smallestIndex << "]"; cout << "\033[0m";
    cout << "\033[0m";
    out << "\n\n";
}




//precondition: valid modifiable array(vector) pass by reference) 
//postcondition: return the calculated circumfernece (perimeter) of a circle
void storeDataCircleShapes(vector <double>& array)
{
    ifstream inputfile;

    do
    {
        //prompt for a data file name
        string filename = inputString("\n\tEnter a data file name (CIRCLES.TXT): ", true);

        //open the data file to read 
        inputfile.open(filename);

        //validate if the file exists
        if (inputfile.fail())
        {
            cout << "\n\tERROR: file, " << filename << ", cannot be found.\n\n";
        }
        else
        {
            break;
        }

    } while (true);

    // reset(clear) the array(vector) 
    array.clear();

    double value = 0.0;

    // read data and store into the array(vector)
    while (inputfile >> value)
        array.push_back(value);

    inputfile.close();

    //prompt the user of completion
    cout << "\n\tData from the file have been read into the vector array.\n\n";

}

//precondition: valid radius and pi values
//postcondition: return the calculated area of a circle
double getArea(double radius, double pi)
{
    return pi * pow(radius, 2);
}

//precondition: valid radius and pi values
//postcondition: return the calculated circumfernece (perimeter) of a circle
double getPerimeter(double radius, double pi)
{
    return 2 * pi * radius;
}

//precondition: valid array(vector) and output stream
//postcondition: display a report of circle data and calculation of area and perimiter
void displayCircleShapes(vector <double> array, ostream& out)
{
    system("cls");

    // display pattern
    cout << "\033[95m"; out << "\n\t        C.C.C";
    cout << "\033[95m"; out << "\n\t    C...........C";
    cout << "\033[95m"; out << "\n\t  C...............C";
    cout << "\033[95m"; out << "\n\t C.................C";
    cout << "\033[95m"; out << "\n\t C....... + .......C";  cout << "\033[93m"; out << "     A circle has the same distance from its center";
    cout << "\033[95m"; out << "\n\t C.................C";
    cout << "\033[95m"; out << "\n\t  C...............C";
    cout << "\033[95m"; out << "\n\t    C...........C";
    cout << "\033[95m"; out << "\n\t        C.C.C";
    cout << "\033[0m"; out << "\n";
    cout << fixed << showpoint << setprecision(2);

    out << "\n";
    int count = 0;
    double sumArea = 0.0;
    double sumPerimiter = 0.0;

    int largestIndex = 0;
    double largestCircle = getArea(array[largestIndex], PI);
    int smallestIndex = 0;
    double smallestCircle = NULL;

    // display colume headers
    out << "\n\t__________________________________________________________________________________________\n\n";
    out << setw(39) << right << "Array[index]" << setw(16) << right << "Radius" << setw(16) << right << "Area" << setw(16) << right <<"Perimeter" << "\n";
    out << "\t                _______________ _______________ _______________ _______________\n";

    //use the for loop to process all elements from the array(vector)
    for (int i = 0; i < array.size(); i++)
    {

        //validate only radius in non-negative value
        if (array[i] < 0.0)
        {
            cout << "\033[31m"; out << setw(39) << right << i << setw(16) << right << array[i];
            cout << "\033[31m"; out << " (Invalid)\n";
            cout << "\033[0m";
        }

        else
        {
            out << setw(39) << right << i << setw(16) << right <<  array[i];
            out << setw(16) << right << getArea(array[i], PI) << setw(16) << right << getPerimeter(array[i], PI) << '\n';

            count++;                            //keep track of how many valid data

            sumArea += getArea(array[i], PI);  // sum up all area
            sumPerimiter += getPerimeter(array[i], PI); // sum up all perimeter

            // keep track of the largest circle using its area
            if (getArea(array[i], PI) > largestCircle)
            {

                largestIndex = i;
                largestCircle = getArea(array[largestIndex], PI);
            }

            // keep track of the smallest circle using its area
            if (smallestCircle == NULL)
            {
                smallestIndex = i;
                smallestCircle = getArea(array[smallestIndex], PI);
            }

            else if (getArea(array[i], PI) < smallestCircle)
            {

                smallestIndex = i;
                smallestCircle = getArea(array[smallestIndex], PI);
            }

        }
    }
    //save smallest and biggest shapes
    smallestShape[1][0] = smallestIndex;
    smallestShape[1][1] = smallestCircle;
    smallestShape[1][2] = getPerimeter(array[smallestIndex], PI);


    largestShape[1][0] = largestIndex;
    largestShape[1][1] = largestCircle;
    largestShape[1][2] = getPerimeter(array[largestIndex], PI);

    out << "\n\t__________________________________________________________________________________________\n";
    out << setw(55) << right << "Average:" << setw(16) << sumArea / count << setw(16) << sumPerimiter/count << "\n";

    cout << "\033[95m";  out << "\n\t\t\t" << "The largest shape found at index  "; cout << "\033[93m"; out << "[" << largestIndex << "]"; cout << "\033[0m";
    cout << "\033[95m"; out << "\n\t\t\t" << "The smallest shape found at index "; cout << "\033[93m"; out << "[" << smallestIndex << "]"; cout << "\033[0m";
    cout << "\033[0m";
    out << "\n\n";
}




//precondition: valid modifiable array(vector) pass by reference) 
//postcondition: return the calculated circumfernece (perimeter) of a annulus
void storeDataAnnulusShapes(vector<vector<double>>& array)
{

    ifstream inputfile;

    do
    {
        //prompt for a data file name
        string filename = inputString("\n\tEnter a data file name (ANNULUSES.TXT): ", true);

        //open the data file to read 
        inputfile.open(filename);

        //validate if the file exists
        if (inputfile.fail())
        {
            cout << "\n\tERROR: file, " << filename << ", cannot be found.\n\n";
        }
        else
            break;

    } while (true);

    // reset(clear) the array(vector) 
    array.clear();

    double outSideRadius = 0.0;
    double insideRadius = 0.0;

    // read data and store into the array(vector)
    while (inputfile >> outSideRadius >> insideRadius)
    {
        vector <double> row;
        row.push_back(outSideRadius);
        row.push_back(insideRadius);
        array.push_back(row);

    }

    inputfile.close();

    //prompt the user of completion
    cout << "\n\tData from the file have been read into the vector array.\n\n";

}

//Get Area for Annulus shape, take in the outer radius and inner radius to return the area
double getArea(double outerRadius, double innerRadius, double pi)
{
    return abs(getArea(outerRadius, pi) - getArea(innerRadius, pi));
}

//Get perimeter for Annulus shape, take in the outer radius and inner radius to return the area
double getPerimeter(double outerRadius, double innerRadius, double pi)
{
    return getPerimeter(outerRadius, pi) + getPerimeter(innerRadius, pi);
}

void displayAnnulusShapes(vector<vector<double>> array, ostream& out)
{
    system("cls");

    // display pattern - you need to code
    // display pattern
    cout << "\033[93m"; out << "\n\t        A.A.A";
    cout << "\033[93m"; out << "\n\t    A ..........A";
    cout << "\033[93m"; out << "\n\t  A......a.a......A";
    cout << "\033[93m"; out << "\n\t A.....a     a.....A";
    cout << "\033[93m"; out << "\n\t A....a   +   a....A"; cout << "\033[93m"; out << "  An annulus is like a ring, or a flattened donut";
    cout << "\033[93m"; out << "\n\t A.....a     a.....A";
    cout << "\033[93m"; out << "\n\t  A......a.a......A";
    cout << "\033[93m"; out << "\n\t    A ......... A";
    cout << "\033[93m"; out << "\n\t        A.A.A";
    cout << "\033[0m"; out << "\n";
    out << fixed << showpoint << setprecision(2);

    out << "\n";
    int count = 0;
    double sumArea = 0.0;
    double sumPerimiter = 0.0;

    int largestIndex = 0;
    double largestAnnulus = getArea(array[largestIndex][0], PI) - getArea(array[largestIndex][0], PI);

    int smallestIndex = 0;
    double smallestAnnulus = NULL;

    // display colume headers
    out << "\n\t        __________________________________________________________________________________________\n\n";
    out << setw(39) << right << "Array[index]" << setw(12) << right << "Radius1" << setw(12) << right << "Radius2" << setw(12) << right << "Area" << setw(12) << right << "Perimeter" << "\n";
    out << "\t                _______________ ___________ ___________ ___________ ___________\n";

    //use the for loop to process all elements from the array(vector)
    for (int i = 0; i < array.size(); i++)
    {
        //validate only radius in non-negative value
        if (array[i][0] < 0.0 || array[i][1] < 0.0)
        {
            cout << "\033[31m"; out << setw(39) << right << i << setw(12) << right << array[i][0] << setw(12) << right << array[i][1];
            cout << "\033[31m"; out << " (Invalid)\n";
            cout << "\033[0m";
        }

        else
        {
            out << setw(39) << right << i << setw(12) << right << array[i][0] << setw(12) << right << array[i][1];
            out << setw(12) << right << getArea(array[i][0], array[i][1], PI) << setw(12) << right << getPerimeter(array[i][0], array[i][1], PI) << '\n';

            count++;                            //keep track of how many valid data

            sumArea += getArea(array[i][0], array[i][1], PI);  // sum up all area
            sumPerimiter += getPerimeter(array[i][0], array[i][1], PI); // sum up all perimeter

            // keep track of the largest circle using its area
            if (getArea(array[i][0], array[i][1], PI) > largestAnnulus)
            {

                largestIndex = i;
                largestAnnulus = getArea(array[largestIndex][0], array[largestIndex][1], PI);
            }

            // keep track of the smallest circle using its area

            if (smallestAnnulus == NULL)
            {
                smallestIndex = i;
                smallestAnnulus = getArea(array[smallestIndex][0], array[smallestIndex][1], PI);
            }
            else if (getArea(array[i][0], array[i][1], PI) < smallestAnnulus)
            {
                smallestIndex = i;
                smallestAnnulus = getArea(array[smallestIndex][0], array[smallestIndex][1], PI);
            }
        }
    }
    //save smallest and biggest shapes
    smallestShape[2][0] = smallestIndex;
    smallestShape[2][1] = smallestAnnulus;
    smallestShape[2][2] = getPerimeter(array[smallestIndex][0], array[smallestIndex][1], PI);


    largestShape[2][0] = largestIndex;
    largestShape[2][1] = largestAnnulus;
    largestShape[2][2] = getPerimeter(array[largestIndex][0], array[largestIndex][1], PI);

    out << "\n\t        __________________________________________________________________________________________\n\n";
    out << setw(63) << right << "Average:" << setw(12) << sumArea / count << setw(12) << sumPerimiter / count << "\n";

    cout << "\033[93m";  out << "\n\t\t\t\t" << "The largest shape found at index  "; cout << "\033[33m"; out << "[" << largestIndex << "]"; cout << "\033[0m";
    cout << "\033[93m";  out << "\n\t\t\t\t" << "The smallest shape found at index "; cout << "\033[33m"; out << "[" << smallestIndex << "]"; cout << "\033[0m";
    out << "\n\n";
}




//precondition: valid modifiable array(vector) pass by reference) 
//postcondition: return the calculated circumfernece (perimeter) of a hear
void inputDataHeartShapes(vector <double>& array)
{
    ifstream inputfile;

    do
    {
        //prompt for a data file name
        string filename = inputString("\n\tEnter a data file name (HEARTS.TXT): ", true);

        //open the data file to read 
        inputfile.open(filename);

        //validate if the file exists
        if (inputfile.fail())
        {
            cout << "\n\tERROR: file, " << filename << ", cannot be found.\n\n";
        }
        else
            break;

    } while (true);

    // reset(clear) the array(vector) 
    array.clear();

    double value = 0.0;

    // read data and store into the array(vector)
    while (inputfile >> value)
        array.push_back(value);

    inputfile.close();

    //prompt the user of completion
    cout << "\n\tData from the file have been read into the vector array.\n\n";
}

//Get Area for hearts pass in side lengths and return area
double getAreaHeart(double side)
{
    return getArea(side) + getArea(side / 4.0, PI);
}

//Get Perimeter for heart pass in side lengths and return perimeter
double getPerimeterHeart(double size)
{
    return getPerimeter(size) + getPerimeter(size / 4.0, PI) - size;
}

void displayHeartShapes(vector <double> array, ostream& out)
{
    system("cls");

    // display pattern
    cout << "\033[96m"; out << "\n\t    H.H.     .H.H";
    cout << "\033[96m"; out << "\n\t  H......H H......H";
    cout << "\033[96m"; out << "\n\t H........H........H";
    cout << "\033[96m"; out << "\n\t  H...............H"; cout << "\033[93m"; out << "     A heart is a shape of two semi-circles place on top of an";;
    cout << "\033[96m"; out << "\n\t    H...........H  "; cout << "\033[93m"; out << "     inverted equilaterial triangle";
    cout << "\033[96m"; out << "\n\t      H.......H";
    cout << "\033[96m"; out << "\n\t        H...H";
    cout << "\033[96m"; out << "\n\t          H";
    cout << "\033[0m"; out << "\n";
    cout << fixed << showpoint << setprecision(2);

    out << "\n";
    int count = 0;
    double sumArea = 0.0;
    double sumPerimiter = 0.0;

    int largestIndex = 0;
    double largestHeart = getAreaHeart(array[largestIndex]);

    int smallestIndex = 0;
    double smallestHeart = NULL;

    // display colume headers
    out << "\n\t__________________________________________________________________________________________\n\n";
    out << setw(39) << right << "Array[index]" << setw(16) << right << "Side length" << setw(16) << right << "Area" << setw(16) << right <<"Perimeter" << "\n";
    out << "\t                _______________ _______________ _______________ _______________\n";

    //use the for loop to process all elements from the array(vector)
    for (int i = 0; i < array.size(); i++)
    {

        //validate only radius in non-negative value
        if (array[i] < 0.0)
        {
            cout << "\033[31m"; out << setw(39) << right << i << setw(16) << right << array[i];
            cout << "\033[31m"; out << " (Invalid)\n";
            cout << "\033[0m";
        }

        else
        {
            out << setw(39) << right << i << setw(16) << right <<  array[i];
            out << setw(16) << right << getAreaHeart(array[i]) << setw(16) << right << getPerimeterHeart(array[i]) << '\n';

            count++;                            //keep track of how many valid data

            sumArea += getAreaHeart(array[i]);  // sum up all area
            sumPerimiter += getPerimeterHeart(array[i]); // sum up all perimeter

            // keep track of the largest circle using its area
            if (getAreaHeart(array[i]) > largestHeart)
            {

                largestIndex = i;
                largestHeart = getAreaHeart(array[largestIndex]);
            }

            // keep track of the smallest circle using its area
            if (smallestHeart == NULL)
            {
                smallestIndex = i;
                smallestHeart = getAreaHeart(array[smallestIndex]);
            }

            else if (getAreaHeart(array[i]) < smallestHeart)
            {

                smallestIndex = i;
                smallestHeart = getArea(array[smallestIndex]);
            }

        }
    }

    //save smallest and biggest shapes
    smallestShape[3][0] = smallestIndex;
    smallestShape[3][1] = smallestHeart;
    smallestShape[3][2] = getPerimeterHeart(array[smallestIndex]);


    largestShape[3][0] = largestIndex;
    largestShape[3][1] = largestHeart;
    largestShape[3][2] = getPerimeterHeart(array[largestIndex]);;

    out << "\n\t__________________________________________________________________________________________\n";
    out << setw(55) << right << "Average:" << setw(16) << sumArea / count << setw(16) << sumPerimiter/count << "\n";

    cout << "\033[96m";  out << "\n\t\t\t" << "The largest shape found at index  "; out << "\033[93m"; out << "[" << largestIndex << "]"; cout << "\033[0m";
    cout << "\033[96m";  out << "\n\t\t\t" << "The smallest shape found at index "; out << "\033[93m"; out << "[" << smallestIndex << "]"; cout << "\033[0m";
    cout << "\033[0m";
    out << "\n\n";
}



//precondition: valid modifiable array(vector) pass by reference) 
//postcondition: return the calculated circumfernece (perimeter) of a Polygon
void inputDataRegularPolygonShapes(vector <vector<double>>& array)
{
    ifstream inputfile;

    do
    {
        //prompt for a data file name
        string filename = inputString("\n\tEnter a data file name (POLYGONS.TXT): ", true);

        //open the data file to read 
        inputfile.open(filename);

        //validate if the file exists
        if (inputfile.fail())
        {
            cout << "\n\tERROR: file, " << filename << ", cannot be found.\n\n";
        }
        else
            break;

    } while (true);

    // reset(clear) the array(vector) 
    array.clear();

    double sideLength = 0.0;
    double numberSides = 0.0;

    // read data and store into the array(vector)
    while (inputfile >> sideLength >> numberSides)
    {
        vector <double> row;
        row.push_back(sideLength);
        row.push_back(numberSides);
        array.push_back(row);

    }

    inputfile.close();

    //prompt the user of completion
    cout << "\n\tData from the file have been read into the vector array.\n\n";
}

//Area of Regular Polygon Inscribed in a Circle
double getArea(double sideLength, int numberSides, double pi)
{
    return (numberSides * sideLength * (sideLength/2*tan(180.0/numberSides))) / 2; //(nr2/2) sin (2π/n) 
}

//Perimeter of Regular Polygon Inscribed in a Circle
double getPerimeter(double sideLength, int numberSides)
{
    return numberSides * sideLength;
}

void displayRegularPolygonShapes(vector<vector<double>> array, ostream& out)
{
    system("cls");

    // display pattern
    cout << "\033[94m"; out << "\n\t         P P P P";
    cout << "\033[94m"; out << "\n\t       P.........P";
    cout << "\033[94m"; out << "\n\t     P.............P";
    cout << "\033[94m"; out << "\n\t   p.................P";
    cout << "\033[94m"; out << "\n\t   P........+........P";
    cout << "\033[94m"; out << "\n\t   p.................P"; cout << "\033[93m"; out << "     A regular polygon has all sides equal and all angles equal";
    cout << "\033[94m"; out << "\n\t     P.............P";
    cout << "\033[94m"; out << "\n\t       P.........P";
    cout << "\033[94m"; out << "\n\t         P P P P";
    cout << "\033[0m"; out << "\n";
    cout << fixed << showpoint << setprecision(2);

    out << "\n";
    int count = 0;
    double sumArea = 0.0;
    double sumPerimiter = 0.0;

    int largestIndex = 0;
    double largestPolygon = NULL;

    int smallestIndex = 0;
    double smallestPolygon = NULL;

    // display colume headers
    // display colume headers
    out << "\n\t        __________________________________________________________________________________________\n\n";
    out << setw(39) << right << "Array[index]" << setw(12) << right << "Side length" << setw(12) << right << "#Sides" << setw(12) << right << "Area" << setw(12) << right << "Perimeter" << "\n";
    out << "\t                _______________ ___________ ___________ ___________ ___________\n";

    //use the for loop to process all elements from the array(vector)
    for (int i = 0; i < array.size(); i++)
    {
        //validate only radius in non-negative value
        if (array[i][0] < 0.0 || array[i][1] < 0.0)
        {
            cout << "\033[31m"; out << setw(39) << right << i << setw(12) << right << array[i][0] << setw(12) << right << static_cast<int>(array[i][1]);
            cout << "\033[31m"; out << " (Invalid)\n";
            cout << "\033[0m";
        }

        else
        {
            out << setw(39) << right << i << setw(12) << right << array[i][0] << setw(12) << right << static_cast<int>(array[i][1]);
            out << setw(12) << right << getArea(array[i][0], array[i][1], PI) << setw(12) << right << getPerimeter(array[i][0], array[i][1], PI) << '\n';

            count++;                            //keep track of how many valid data

            sumArea += getArea(array[i][0], static_cast<int> (array[i][1]), PI);  // sum up all area
            sumPerimiter += getPerimeter(array[i][0], static_cast<int>(array[i][1])); // sum up all perimeter

            // keep track of the largest circle using its area
            if (smallestPolygon == NULL)
            {
                smallestIndex = i;
                smallestPolygon = getArea(array[smallestIndex][0], static_cast<int> (array[smallestIndex][1]), PI);
            }
            else if (getArea(array[i][0], array[i][1], PI) > largestPolygon)
            {
                largestIndex = i;
                largestPolygon = getArea(array[largestIndex][0], static_cast<int> (array[largestIndex][1]), PI);
            }

            // keep track of the smallest circle using its area

            if (smallestPolygon == NULL)
            {
                smallestIndex = i;
                smallestPolygon = getArea(array[smallestIndex][0], static_cast<int> (array[smallestIndex][1]), PI);
            }

            else if (getArea(array[i][0], array[i][1], PI) < smallestPolygon)
            {
                smallestIndex = i;
                smallestPolygon = getArea(array[smallestIndex][0], static_cast<int> (array[smallestIndex][1]), PI);
            }
        }
    }

    //save smallest and biggest shapes
    smallestShape[4][0] = smallestIndex;
    smallestShape[4][1] = smallestPolygon;
    smallestShape[4][2] = getPerimeter(array[smallestIndex][0], static_cast<int>(array[smallestIndex][1]));


    largestShape[4][0] = largestIndex;
    largestShape[4][1] = largestPolygon;
    largestShape[4][2] = getPerimeter(array[largestIndex][0], static_cast<int>(array[largestIndex][1]));

    out << "\n\t        __________________________________________________________________________________________\n\n";
    out << setw(63) << right << "Average:" << setw(12) << sumArea / count << setw(12) << sumPerimiter / count << "\n";

    cout << "\033[94m";  out << "\n\t\t\t\t" << "The largest shape found at index  "; cout << "\033[33m"; out << "[" << largestIndex << "]"; cout << "\033[0m";
    cout << "\033[94m";  out << "\n\t\t\t\t" << "The smallest shape found at index "; cout << "\033[33m"; out << "[" << smallestIndex << "]"; cout << "\033[0m";
    cout << "\n\n";
}
