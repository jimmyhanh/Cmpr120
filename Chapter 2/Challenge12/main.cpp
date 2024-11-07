//Hung Anh Ho
//2-22-2023
//Description: Chapter 2: Challenge 12 - Land Calculation

#include<iostream>;
using namespace std;

int main()
{
	//Input
	float oneAcre = 43560;
	float tractOfLand = 391876;
	float landAcres;

	//Process
	landAcres = tractOfLand / oneAcre;

	//Output	
	cout << "the number of acres in a tract of land of "<< tractOfLand << "(square feet): " << landAcres << "(acres)\n";

	return 0;
}