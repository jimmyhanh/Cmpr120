//Hung Anh Ho
//2-21-2023
//Description: Chapter 2: Challenge 20 - How Much Paint

#include<iostream>;
using namespace std;

int main()
{
	//Input
	int paintCover = 340;
	int numberOfCoats = 2;
	double fenceHeight = 6.0;
	double fenceLength = 100.0;
	
	//Process
	double fenceArea = fenceHeight * fenceLength;
	double gallonNeed = fenceArea / paintCover * numberOfCoats;

	//Output
	cout << "Paint approxiamately needed to paint 2 coats on a wooden fence of " << fenceArea << " (square feet): " << gallonNeed << " (gallon)\n";

	return 0;
}