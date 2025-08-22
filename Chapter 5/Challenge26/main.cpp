//Hung Anh Ho
//3-28-2023
//Personal Web Page Generator

#include <iostream>;
#include <fstream>;
#include <string>;
using namespace std;

int main()
{
	string name;
	{
		cout << "Enter your name: ";
		getline(cin,name);

	} while (name.length() <= 0);

	string description;
	do
	{
		cout << "Describe yourself: ";
		getline(cin,description);

	} while (description.length() <= 0);
	
	ofstream outputFile;
	outputFile.open("webpage.html");

	//Write to file
	outputFile << "<html>\n";
	outputFile << "<head>\n";
	outputFile << "</head>\n";
	outputFile << "<body>\n";
	outputFile << "\t<center>\n";
	outputFile << "\t\t<h1>" << name << "<h1>\n";
	outputFile << "\t<center>\n";
	outputFile << "\t<h1 />\n";
	outputFile << "\t\t" << description;
	outputFile << "\n\t<h1 />\n";
	outputFile << "<body>\n";
	outputFile << "<html>\n";

	cout << "File has been written.";
	outputFile.close();

	return 0;
}