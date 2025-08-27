//Hung Anh Ho
//5-24-2023
//Chapter 10

#include <iostream>
#include "input.h"
#include <cctype>
#include <fstream>
using namespace std;


void Challenge1();

void Challenge6();
int countConsonants(const char* str);
int countConsonants(const char* str);

void Challenge10();
void replaceSubstring(string&, string, string);

void Challenge12();
bool isValidPassword(string&);

void Challenge15();

void Challenge17();

int main()
{
    do
    {
        system("cls");
        cout << "\n\t\tChapter 10: Characters, C-strings and Strings by your name";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t\t  1. String Length";
        cout << "\n\t\t  6. Vowels and Consonants";
        cout << "\n\t\t 10. replace SubString Function     ";
        cout << "\n\t\t 12. Password Verifier";
        cout << "\n\t\t 15. Character Analysis ";
        cout << "\n\t\t 17. Morse Code Converter";
        cout << "\n\t" + string(60, char(196));
        cout << "\n\t\t  0. Quit";
        cout << "\n\t" + string(60, char(205));
        cout << "\n";

        switch (inputInteger("\t\t  Option: ", 0, 17))
        {
        case 0: exit(1); break;
        case 1: Challenge1(); break;
        case 6: Challenge6(); break;
        case 10: Challenge10(); break;
        case 12: Challenge12(); break;
        case 15: Challenge15(); break;
        case 17: Challenge17(); break;
        default: cout << "\t\tERROR - Invalid option."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

void Challenge1()
{
    //c-string implementation
    char input[100];
    cout << "\nEnter a C-string: ";
    cin.getline(input, 100);

    cout << "\nLength of the c-string: " << strlen(input) << '\n';

    //string object implementation
    string input2;
    cout << "\nEnter a string object: ";
    getline(cin, input2, '\n');

    cout << "\nLength of the string object: " << input2.length() << '\n';

}

//countVowels get characters and return count for vowels
int countVowels(const char* str)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
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
int countConsonants(const char* str)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
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


void Challenge6()
{
    char input[1000] = "";
    cout << "\nEnter a c-string: ";
    cin.getline(input, 1000);

    string input2;
    cout << "\nEnter a string: ";
    getline(cin,input2, '\n');


    do
    {
        cout << "\nA. Count the vowel(s)";
        cout << "\nB. Count the consonant(s)";
        cout << "\nC. Count both the vowel(s) and the consonant(s)";
        cout << "\nD. Enter a new c-string";
        cout << "\nE. Return";

        switch (toupper(inputChar("\nOption: ", static_cast<string>("ABCDE"))))
        {
        case 'A':
        {
            cout << "# of vowel(s) of c-string: " << countVowels(input) << "\n";
            cout << "# of vowel(s) of string: " << countVowels(input2.c_str()) << "\n";

        }
        break;
        case 'B':
        {
            cout << "# of consonant(s) of c-string: " << countConsonants(input) << "\n";
            cout << "# of consonant(s) of string: " << countConsonants(input2.c_str()) << "\n";
        }
        break;
        case 'C':
        {
            cout << "# of vowel(s) and consonant(s) of c-string: " << countVowels(input) + countConsonants(input) << "\n";
            cout << "# of vowel(s) and consonant(s) of string: " << countVowels(input2.c_str()) + countConsonants(input2.c_str()) << "\n";
        }
        break;
        case 'D':
            cout << "\nEnter a new c-string: ";
            cin.getline(input, 1000);
            break;

        case 'E':
            return;
        }
    } while (true);


}


void Challenge10()
{
   system("cls");
   cout << "\nExample: \n";
   string  string1 = "the dog jump over the fence";
   string  string2 = "the";
   string  string3 = "that";
   
   //Example
   cout << "\nString before change:\n";
   cout << string1;

   replaceSubstring(string1, string2, string3);

   cout << "\n\nString after change:\n";
   cout << string1;

   //Execute
   string1 = inputString("\n\nInput your own string: ", true);
   string2 = inputString("\nInput your word to replace: ", true);
   string3 = inputString("\nInput your replacing word: ", true);

   replaceSubstring(string1, string2, string3);
   cout << "\n\nString after change:\n";
   cout << string1;
}

//replaceSubstring takes in string input, word to find and word to replace and return the string
void replaceSubstring(string &string1, string string2, string string3)
{
    for (int i = 0; i < string1.length() - string2.length(); i++)
    {
        if (string1.substr(i, string2.length()) == string2)
        {
            string1.replace(string1.find(string2), string2.length(), string3);
        }
    }
}

void Challenge12()
{
    system("cls");

    string password = inputString("Enter your password: ", true);

    if (isValidPassword(password)) 
    {
        cout << "Password is valid.\n";
    }

    else 
    {
        cout << "Password is not valid.\n";
    }
}

//isValidPassword check for password is valid to return true or false
bool isValidPassword(string& password) 
{
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasPunct = false;

    if (password.size() < 6) 
    {
        cout << "Password must be atleast 6 characters long.\n";
        return false;
    }

    for (char ch : password) 
    {
        if (isdigit(ch)) hasDigit = true;
        else if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (ispunct(ch)) hasPunct = true;
    }

    if (!hasDigit) 
    {
        cout << "Password must contain at least one digit.\n";
        return false;
    }

    if (!hasUpper) 
    {
        cout << "Password must contain at least one uppercase letter.\n";
        return false;
    }

    if (!hasLower) 
    {
        cout << "Password must contain at least one lowercase letter.\n";
        return false;
    }

    if (!hasPunct) 
    {
        cout << "Password must contain at least one special letter.\n";
        return false;
    }

    return true;
}

void Challenge15()
{
    system("cls");
    
    ifstream inputFile;
    string fileName = inputString("\n\tEnter a data file name (text.txt): ", true);

    //open file to read
    inputFile.open(fileName);

    while (!inputFile)
    {
        cout << "\n\t " << fileName << ", was found. Enter the correct file name.\n";
        fileName = inputString("\n\tEnter a data file name (text.txt): ", true);

        inputFile.open(fileName);
    }

    int uppercaseCount = 0, lowercaseCount = 0, digitCount = 0;
    char ch;


    while (inputFile.get(ch)) 
    {
        if (isupper(ch)) uppercaseCount++;
        else if (islower(ch)) lowercaseCount++;
        else if (isdigit(ch)) digitCount++;
    }

    cout << "\n\tNumber of uppercase letters: " << uppercaseCount << '\n';
    cout << "\n\tNumber of lowercase letters: " << lowercaseCount << '\n';
    cout << "\n\tNumber of digits: " << digitCount << '\n';

    inputFile.close();
}


void Challenge17()
{
    string digits[10] = { "-----", // 0
        ".----", // 1
        "..---", // 2
        "...--", // 3
        "....-", // 4
        ".....", // 5
        "-....", // 6
        "--...", // 7
        "---..", // 8
        "----.", // 9
    };

    string alphabets[26] = { ".-",   // A
        "-...", //B
        "-.-.", //C
        "-..", //D
        ".", //E
        "..-.", //F
        "--.", //G
        "--...", //H
        "..", //I
        ".---", //J
        "-.-", //K
        ".-..", //L
        "--", //M
        "-.", //N
        "---", //O
        ".--.", //P
        "--.-", //Q
        ".-.", //R
        "...", //S
        "-", //T
        "..-", //U
        "...-", //V
        ".--", //W
        "-..-", //X
        "-.--", //Y
        "--..", //Z
    };

    string comma = "--..--";
    string period = ".-.-.-";
    string questionMark = "..--..";

    //Input string
    int size = inputInteger("\nEnter size of the c-string: ", true);

    char* input = new char[size];

    //Output
    cout << "\nEnter a c-string to convert to morse code: ";
    cin.getline(input, size);


    cout << "Morsecode: \n";
    for (int i = 0; i < strlen(input); i++)
    {
        if (isdigit(input[i]))
            cout << digits[input[i] - '0'] << "|";

        if (isalpha(input[i]))
            cout << alphabets[toupper(input[i]) - 'A'] << "|";

        if (isspace(input[i]))
            cout << "space|";
        if (ispunct(input[i]))
        {
            if (input[i] == ',')
                cout << comma << "|";
            else if (input[i] == '.')
                cout << period << "|";
            else if (input[i] == '?')
                cout << questionMark << "|";
            else
                cout << "unknown";
        }
    }

    delete[] input;
} 