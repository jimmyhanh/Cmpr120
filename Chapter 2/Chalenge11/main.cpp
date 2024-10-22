//Hung Anh Ho
//2-21-2023
//Description: Chapter 2: Challenge 11 - Distance per Tank of Gas

#include<iostream>;
using namespace std;

int main()
{
	//Input
	int numberGallons = 20;
	float milesPerGallon_Town = 23.5;
	float milesPerGallon_Highway = 28.9;

	//Process
	float distanceTraveled_Town = numberGallons * milesPerGallon_Town;
	float distanceTraveled_Highway = numberGallons * milesPerGallon_Highway;

	//Output
	cout << "Distance traveled in town: " << distanceTraveled_Town << " (mpg)\n";
	cout << "Distance traveled in highway: " << distanceTraveled_Highway << " (mpg)\n";

	return 0;
}