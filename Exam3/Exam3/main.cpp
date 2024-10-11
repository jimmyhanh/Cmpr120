//Hung Anh Ho
//5-25-2023
//Exam 3

#include <Windows.h>
#include <cmath>
#include <iostream>         // console input/output library
#include <iomanip>           // input/output manipulation library
#include <fstream>           // file input/output library
#include <vector>           // dynamic array(vector) library
#include "input.h"          // input validate functions library create by Prof Q

using namespace std;

char menuOption();
void inputData(vector<string>&, vector<char>&, int&, int&);
int countVowels(vector<char>);
int countConsonants(vector<char>);
void displayData(vector<char>, int[], int[], int, int*, int, int, int, ostream&);
char caseCMenu();

//main
int main()
{
	//Store lines
	vector<string> database;
	//Store characters
	vector<char> everyWord;

	const int sizeAlphabet = 26; // {A, B, C, D, E, F, G, H, I, J,  K,  L,  M,  N,  O,  P,  Q,  R,  S,  T,  U,  V,  W,  X,  Y,  Z};
	int alphabethCountUpper [sizeAlphabet] = {0};    // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}
	int alphabethCountLower [sizeAlphabet] = {0};

	int totalDigits = 0;

	const int zero_to_ten = 10;
	int digitCount[zero_to_ten] = {0}; // 0-9
	int punctuationCount = 0;
	int spaceCount = 0;
	int otherCharacters = 0;

	int numberOfLines = 0;
	int charactersCount = 0;

	do
	{
		switch (toupper(menuOption()))
		{
			//Read and store data
			case 'A':
			{
				//Store
				inputData(database, everyWord, numberOfLines, charactersCount);

				//Count characters
				for(char i : everyWord)
				{
					//Alphabet
					if (isalpha(i))
					{
						if(i == 'a')
							alphabethCountLower[0]++;

						else if(i == 'A')
							alphabethCountUpper[0]++;
						
						
						
						else if(i == 'b')
							alphabethCountLower[1]++;

						else if(i == 'B')
							alphabethCountUpper[1]++;

						
						
						else if(i == 'c')
							alphabethCountLower[2]++;

						else if(i == 'C')
							alphabethCountUpper[2]++;
			
						
						
						else if(i == 'd')
							alphabethCountLower[3]++;

						else if(i == 'D')
							alphabethCountUpper[3]++;
	
						
						
						else if(i == 'e')
							alphabethCountLower[4]++;

						else if(i == 'E')
							alphabethCountUpper[4]++;

						
						
						else if(i == 'f')
							alphabethCountLower[5]++;

						else if(i == 'F')
							alphabethCountUpper[5]++;

						
						
						else if(i == 'g')
							alphabethCountLower[6]++;

						else if(i == 'G')
							alphabethCountUpper[6]++;

						
						
						else if(i == 'h')
							alphabethCountLower[7]++;

						else if(i == 'H')
							alphabethCountUpper[7]++;

						
						
						else if(i == 'i')
							alphabethCountLower[8]++;

						else if(i == 'I')
							alphabethCountUpper[8]++;

						
						
						else if(i == 'j')
							alphabethCountLower[9]++;

						else if(i == 'J')
							alphabethCountUpper[9]++;

						
						
						else if(i == 'k')
							alphabethCountLower[10]++;

						else if(i == 'K')
							alphabethCountUpper[10]++;

						
						
						else if(i == 'l')
							alphabethCountLower[11]++;

						else if(i == 'L')
							alphabethCountUpper[11]++;

						
						
						else if(i == 'm')
							alphabethCountLower[12]++;

						else if(i == 'M')
							alphabethCountUpper[12]++;

						
						
						else if(i == 'n')
							alphabethCountLower[13]++;

						else if(i == 'N' )
							alphabethCountUpper[13]++;

						
						
						else if(i == 'o')
							alphabethCountLower[14]++;

						else if(i == 'O')
							alphabethCountUpper[14]++;

						
						
						else if(i == 'p')
							alphabethCountLower[15]++;

						else if(i == 'P')
							alphabethCountUpper[15]++;

						
						
						else if(i == 'q')
							alphabethCountLower[16]++;

						else if(i == 'Q')
							alphabethCountUpper[16]++;


						else if(i == 'r')
							alphabethCountLower[17]++;

						else if(i == 'R')
							alphabethCountUpper[17]++;

						
						
						else if(i == 's')
							alphabethCountLower[18]++;

						else if(i == 'S')
							alphabethCountUpper[18]++;

						
						
						else if(i == 't')
							alphabethCountLower[19]++;

						else if(i == 'T')
							alphabethCountUpper[19]++;

						
						
						else if(i == 'u')
							alphabethCountLower[20]++;

						else if(i == 'U')
							alphabethCountUpper[20]++;

						
						
						else if(i == 'v')
							alphabethCountLower[21]++;

						else if(i == 'V')
							alphabethCountUpper[21]++;

						
						
						else if(i == 'w')
							alphabethCountLower[22]++;

						else if(i == 'W')
							alphabethCountUpper[22]++;

						
						
						else if(i =='x')
							alphabethCountLower[23]++;

						else if(i == 'X')
							alphabethCountUpper[23]++;

						
						
						else if(i =='y')
							alphabethCountLower[24]++;

						else if(i == 'Y')
							alphabethCountUpper[24]++;

						
						
						else if(i == 'z')
							alphabethCountLower[25]++;

						else if(i == 'Z')
							alphabethCountUpper[25]++;
						}

					//Digits
					else if (isdigit(i))
					{
						totalDigits++;

						//Compare each number 
						/*
						for (int number = 0; number < 10; number++)
						{
							if (static_cast<char>(i) == number)
							{
								digitCount[number]++;
							}
						}
						*/

						
						if (i == '0')
						{
							digitCount[0]++;
						}
						else if (i == '1')
						{
							digitCount[1]++;
						}
						else if (i == '2')
						{
							digitCount[2]++;
						}
						else if (i == '3')
						{
							digitCount[3]++;
						}
						else if (i == '4')
						{
							digitCount[4]++;
						}
						else if (i == '5')
						{
							digitCount[5]++;
						}
						else if (i == '6')
						{
							digitCount[6]++;
						}
						else if (i == '7')
						{
							digitCount[7]++;
						}
						else if (i == '8')
						{
							digitCount[8]++;
						}
						else if (i == '9')
						{
							digitCount[9]++;
						}
						
					}

					//Punctuations
					else if (ispunct(i))
						punctuationCount++;

					//Spaces
					else if (i == ' ')
						spaceCount++;

					//Others
					else
						otherCharacters++;
				}

				break;
			}

			//Display lines count and all lines
			case 'B':
			{
				system("cls");

				//Validate input
				if (database.empty())
				{
					cout << "\tNo file has been read. Go back to step A.\n";
				}

				else
				{
					cout << "\n";

					//Dipslay all lines in the array
					for (string i : database)
					{
						cout << i << "\n";
					}

					//Line count display
					cout << "\n\nLine count(s): " << numberOfLines << "\n\n";

					/* Test char array
					for (char i : everyWord)
					{
						cout << i << "\n";
					}
					*/
				}

				system("pause");
				break;
			}

			case 'C':
			{
				//Validate input
				if (database.empty())
				{
					cout << "\tNo file has been read. Go back to step A.\n";

				}
				else
					switch (toupper(caseCMenu()))
					{
						case 'C':
						{
							//display to console
							displayData(everyWord, alphabethCountUpper, alphabethCountLower, totalDigits, digitCount, spaceCount, punctuationCount, otherCharacters, cout);
							system("pause");

							break;
						}

						//To file
						case 'F':
						{
							ofstream outputFile;
							//open the data file to read 
							string fileName = inputString("\tEnter your file name: ", true);
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
								//Write to file
								else
								{
									displayData(everyWord, alphabethCountUpper, alphabethCountLower, totalDigits, digitCount, spaceCount, punctuationCount, otherCharacters, outputFile);
								}

								outputFile.close();

								//prompt the user of completion

								system("cls");
								cout << "\n\tData from the file have been written into the vector array.\n\n";
								break;
							}
						}

						case 'R':
						{
							break;
						}
					}

				system("pause");
				break;
			}

			//Exit
			case 'X':
			{
				exit(0);
				break;
			}
		}

	}while (true);

	return 0;
}

//precondition: none
//postcondition: display the banner and menu, prompt and return user option
char menuOption()
{
	system("cls");
	cout << "\tLife of " << char(227) << "\n";
	cout << "\n\tPi (often represented by the lower-case Greek letter π one of the most well-known\n\tmathematical constants, is the ratio of a circle's circumference to its diameter.\n\tFor any circle, the distance around the edge is a little more than three times<< \n\tthe distance across.\n\n";
	cout << "\n\tCMPR120 - Exam #3 - Strings by Hung Anh Ho (March 25th, 2023)\n";
	cout << "\t" << string(60, char(205));
	cout << "\n\tA. Read string data file and store into a dynamic array";
	cout << "\n\tB. Display ALL lines of strings";
	cout << "\n\tC. Output the statistics of ALL line of strings\n";
	cout << "\t" << string(60, char(196));
	cout << "\n\tX. Exit the program\n";
	cout << "\t" << string(60, char(205));

	char option = inputChar("\n\n\tEnter your option: ", "ABCX");

	return option;
}


//precondition: valid modifiable array(vector) pass by reference) 
//postcondition: return the data read and store into program
void inputData(vector<string> &data, vector<char> &everyWord, int &numberOfLines, int &charactersCount)
{
	//Prompt file name
	ifstream inputFile;

	do
	{
		//Input file
		string fileName = inputString("\n\tEnter file name (LOP.TXT): ", true);

		//open file
		inputFile.open(fileName);


		string line;
		char ch;
		//Verify input file and save data
		if (inputFile)
		{
			//Get lines
			while (getline(inputFile, line))
			{
				data.push_back(line);
				numberOfLines++;
			}

			//Reset reading to the start
			inputFile.close();

			inputFile.open(fileName);
			//Get all characters
			while (inputFile.get(ch)) 
			{
				everyWord.push_back(ch);
				charactersCount++;
			}

			cout << "\n\tData has been read and stored into file.\n";

			//close
			inputFile.close();
		}

		else
		{
			cout << "\n\tError file " << fileName << " cannot be opened. Try again.";
		}

		system("pause");
		break;

	}while (true);
}


//precondition: none
//postcondition: display the menu, prompt and return user option
char caseCMenu()
{
	return inputChar("\tOutput to C-Console, F-file or R-return: ", "CFR");
}

//countVowels get characters and return count for vowels
int countVowels(vector<char> str)
{
	int count = 0;

	for (int i = 0; i < str.size(); i++)
		if (isalpha(str[i]))
		{
			switch (toupper(str[i]))
			{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				count++;
				break;

			default:
				break;
			}
		}

	return count;
}

//countConsonants get characters and return count for consonsonants
int countConsonants(vector<char> str)
{
	int count = 0;

	for (int i = 0; i < str.size(); i++)
		if (isalpha(str[i]))
		{
			switch (toupper(str[i]))
			{
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				break;
			default:
				count++;
				break;
			}
		}

	return count;
}

//displayData takes in all words, word, digits, punctuation, space and other characters count to display and write or write into file
void displayData(vector<char> everyWord, int alphabethCountUpper[], int alphabethCountLower[], int totalDigits, int *digitCount, int spaceCount, int punctuationCount, int otherCharacters, ostream &out)
{
	system("cls");
	out << "\tStatistics\n";
	out << "\t-------------------------------------------\n";
	out << "\t Total # character(s)" << setw(11) << ": " << everyWord.size() << "\n";
	//Vowels
	//Uppercase
	out << "\t\t# of vowel(s)" << setw(11) << ": " << countVowels(everyWord) << "\n";
	out << "\n\t\t    ----Upper cases----\n";
	out << "\t\t\t" << "A:" << setw(10) << alphabethCountUpper[0] << "\n";
	out << "\t\t\t" << "E:" << setw(10) << alphabethCountUpper[4] << "\n";
	out << "\t\t\t" << "I:" << setw(10) << alphabethCountUpper[8] << "\n";
	out << "\t\t\t" << "O:" << setw(10) << alphabethCountUpper[14] << "\n";
	out << "\t\t\t" << "U:" << setw(10) << alphabethCountUpper[20] << "\n";

	//Lower
	out << "\n\t\t    ----Lower cases----\n";
	out << "\t\t\t" << "a:" << setw(10) << alphabethCountLower[0] << "\n";
	out << "\t\t\t" << "e:" << setw(10) << alphabethCountLower[4] << "\n";
	out << "\t\t\t" << "i:" << setw(10) << alphabethCountLower[8] << "\n";
	out << "\t\t\t" << "o:" << setw(10) << alphabethCountLower[14] << "\n";
	out << "\t\t\t" << "u:" << setw(10) << alphabethCountLower[20] << "\n";

	//Consonants

	//Uppercase
	out << "\n\t\t# of consonant(s)" << setw(7) << ": " << countConsonants(everyWord) << "\n";
	out << "\n\t\t    ----Upper cases----\n";
	out << "\t\t\t" << "B:" << setw(10) << alphabethCountUpper[1] << "\n";
	out << "\t\t\t" << "C:" << setw(10) << alphabethCountUpper[2] << "\n";
	cout << "\t\t\t" << "D:" << setw(10) << alphabethCountUpper[3] << "\n";
	//cout << "\t\t\t" << "E" << setw(20) << alphabethCountUpper[4];
	out << "\t\t\t" << "F:" << setw(10) << alphabethCountUpper[5] << "\n";
	out << "\t\t\t" << "G:" << setw(10) << alphabethCountUpper[6] << "\n";
	out << "\t\t\t" << "H:" << setw(10) << alphabethCountUpper[7] << "\n";
	//cout << "\t\t\t" << "I" << setw(20) << alphabethCountUpper[8];
	out << "\t\t\t" << "J:" << setw(10) << alphabethCountUpper[9] << "\n";
	out << "\t\t\t" << "K:" << setw(10) << alphabethCountUpper[10] << "\n";
	out << "\t\t\t" << "L:" << setw(10) << alphabethCountUpper[11] << "\n";
	out << "\t\t\t" << "N:" << setw(10) << alphabethCountUpper[12] << "\n";
	out << "\t\t\t" << "N:" << setw(10) << alphabethCountUpper[13] << "\n";
	//cout << "\t\t\t" << "O" << setw(20) << alphabethCountUpper[14];
	out << "\t\t\t" << "P:" << setw(10) << alphabethCountUpper[15] << "\n";
	out << "\t\t\t" << "Q:" << setw(10) << alphabethCountUpper[16] << "\n";
	out << "\t\t\t" << "R:" << setw(10) << alphabethCountUpper[17] << "\n";
	out << "\t\t\t" << "S:" << setw(10) << alphabethCountUpper[18] << "\n";
	out << "\t\t\t" << "T:" << setw(10) << alphabethCountUpper[19] << "\n";
	//cout << "\t\t\t" << "U" << setw(20) << alphabethCountUpper[20];
	out << "\t\t\t" << "V:" << setw(10) << alphabethCountUpper[21] << "\n";
	out << "\t\t\t" << "W:" << setw(10) << alphabethCountUpper[23] << "\n";
	out << "\t\t\t" << "X:" << setw(10) << alphabethCountUpper[23] << "\n";
	out << "\t\t\t" << "Y:" << setw(10) << alphabethCountUpper[24] << "\n";
	out << "\t\t\t" << "Z:" << setw(10) << alphabethCountUpper[25] << "\n";

	//Lower
	out << "\n\t\t    ----Lower cases---- \n";
	out << "\t\t\t" << "b:" << setw(10) << alphabethCountLower[1] << "\n";
	out << "\t\t\t" << "b:" << setw(10) << alphabethCountLower[2] << "\n";
	out << "\t\t\t" << "d:" << setw(10) << alphabethCountLower[3] << "\n";
	//cout << "\t\t\t" << "E" << setw(20) << alphabethCountUpper[4];
	out << "\t\t\t" << "f:" << setw(10) << alphabethCountLower[5] << "\n";
	out << "\t\t\t" << "g:" << setw(10) << alphabethCountLower[6] << "\n";
	out << "\t\t\t" << "h:" << setw(10) << alphabethCountLower[7] << "\n";
	//cout << "\t\t\t" << "I" << setw(20) << alphabethCountUpper[8];
	out << "\t\t\t" << "j:" << setw(10) << alphabethCountLower[9] << "\n";
	out << "\t\t\t" << "k:" << setw(10) << alphabethCountLower[10] << "\n";
	out << "\t\t\t" << "l:" << setw(10) << alphabethCountLower[11] << "\n";
	out << "\t\t\t" << "m:" << setw(10) << alphabethCountLower[12] << "\n";
	out << "\t\t\t" << "n:" << setw(10) << alphabethCountLower[13] << "\n";
	//cout << "\t\t\t" << "O" << setw(20) << alphabethCountUpper[14];
	out << "\t\t\t" << "p:" << setw(10) << alphabethCountLower[15] << "\n";
	out << "\t\t\t" << "q:" << setw(10) << alphabethCountLower[16] << "\n";
	out << "\t\t\t" << "r:" << setw(10) << alphabethCountLower[17] << "\n";
	out << "\t\t\t" << "s:" << setw(10) << alphabethCountLower[18] << "\n";
	out << "\t\t\t" << "t:" << setw(10) << alphabethCountLower[19] << "\n";
	//cout << "\t\t\t" << "U" << setw(20) << alphabethCountUpper[20];
	out << "\t\t\t" << "v:" << setw(10) << alphabethCountLower[21] << "\n";
	out << "\t\t\t" << "w:" << setw(10) << alphabethCountLower[22] << "\n";
	out << "\t\t\t" << "x:" << setw(10) << alphabethCountLower[23] << "\n";
	out << "\t\t\t" << "y:" << setw(10) << alphabethCountLower[24] << "\n";
	out << "\t\t\t" << "z:" << setw(10) << alphabethCountLower[25] << "\n";


	//Digits
	out << "\n\t\t# of digit(s)" << setw(12) << ": " << totalDigits << "\n";

	//Display each number
	for (int number = 0; number < 10; number++)
	{
		out << "\t\t\t" << number << setw(11) << digitCount[number] << "\n";
	}

	//Spaces
	out << "\t\t# of space(s)" << setw(12) << ": " << spaceCount << "\n";

	//Punctuation
	out << "\t\t# of punctuation(s)" << setw(6) << ": " << punctuationCount << "\n";

	//Other
	out << "\t\t# of other character(s): " << otherCharacters << "\n";
}