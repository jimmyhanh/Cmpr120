//Hung Anh Ho
//3-18-2023
//Exam 1

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

int main()
{
	//Constant PI
	const double PI = 3.14159265359;

	//Header
	cout << "\n	CMPR120 Exam#1 - 3D Geometric Calcuations by Hung Anh Ho (March 25rd, 2023)";

	//Pre Menu
	int preNumber = 0; // prompt before start number
	cout << "\n	Specify a number (5...10) of significant digits for output format floating-point values: ";
	cin >> preNumber;
	

	// Validate the digits input
	if (preNumber < 5 || preNumber > 10)
	{
		cout << "\n	WARNING: Out-of-range input. It will be defaulted to 5.\n";
		preNumber = 5;
	}

	//Set precison point
	cout << fixed << setprecision(preNumber) << showpoint;

	// Display the menu
	cout << "\n	In geometry, a three dimensional (3D) shape can be defined as a solid figure or an object";
	cout << "\n	or shape that has three dimensions - length, width, and height. Unlike two dimensional";
	cout << "\n	shapes, three - dimensional shapes have height, which is the same as thickness or depth.";
	cout << "\n	All three dimensional figures occupy space, which is measured in terms of volume.\n";
	cout << "\n		Menu";
	cout << "\n	=========================================================================================";
	cout << "\n		1. Sphere - round ball";
	cout << "\n		2. Tetrahedron - triangular pyramid";
	cout << "\n		3. Pentahedron - square pyramid";
	cout << "\n		4. Polyhedron - rectangular prism";
	cout << "\n		5. Torus - doughnut";
	cout << "\n		6. Hemisphere - one half of a sphere";
	cout << "\n	----------------------------------------------------------------------------------------";
	cout << "\n		11. Interactive input ALL shapes";
	cout << "\n		12. Randomized input ALL shapes";
	cout << "\n	----------------------------------------------------------------------------------------";
	cout << "\n		0. Exit program";
	cout << "\n	=========================================================================================";

	//Input option
	int option = 0;
	cout << "\n		Option: ";
	cin >> option;

	// Validate the option input
	if(option < 0 && option > 6 && option != 11 && option != 12)
	{
		cout << "\n	ERROR: Invalid option.";
		return -1;
	}

	//Menu cases
	switch(option)
	{

		//Quit Case
		case 0:
		{
			cout << "\n	Terminating program.";
			return 0;
		}

		//Sphere
		case 1:
		{
			//Display a sphere shape
			cout << "\n                         . . .";
			cout << "\n                     .   1 1 1 111";
			cout << "\n                  .           1 1 111";
			cout << "\n                .               1 1 111";
			cout << "\n               .                 1 1 111";
			cout << "\n              .                   1 1 111";
			cout << "\n             ..                   1 1 1111    Sphere - a round object with the same distance";
			cout << "\n             ..                   1 1 1111    (radius) from its surface to its center";
			cout << "\n             ..                   1 1 1111";
			cout << "\n              ..                1 1 1 111";
			cout << "\n               ...           1 1 1 1 111";
			cout << "\n                ....  . 1 1 1 1 1 1 111";
			cout << "\n                  ..1 1 1 1 1 1 1 111";
			cout << "\n                     1 1 1 1 1 111";
			cout << "\n                         . . .";

			
			//Input 
			cout << "\n\n	1)Sphere input";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double radius = 0.0;
			cout << "\n		Enter a radius of the sphere: ";
			cin >> radius;

			//Validate the radius
			if (radius <= 0.0)
			{
				cout << "\n	ERROR: Invalid input. Radius cannot be negative. Program terminates.";
				return -1; //Exit the program
			}

		
			//Process
			double diameter = radius * 2; // Diameter = 2r
			double area = 4 * PI * pow(radius, 2); // Area = 4 * PI * r ^ 2
			double volume = 4.0 / 3 * PI * pow(radius, 3); // Volume = 4 / 3 * PI * r^3

		
			//Output
			cout << "\n	Sphere output";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Radius" << "(r)" << " = " << right << setw(10) << radius;
			cout << left << setw(16) << "\n		Diameter" << "(d)" << " = " << right << setw(10) << diameter;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << area;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volume;

			break;
		}

		//Tetrahedron 
		case 2:
		{ 

			//Display a tetrahedron shape
			cout << "\n\n                               |";
			cout << "\n                              /|2";
			cout << "\n                            /  |222";
			cout << "\n                           /   |2222";
			cout << "\n                         /     |222222";
			cout << "\n                        /      |2222222";
			cout << "\n                      /        |22222222       Tetrahedron - a triangular pyramid with";
			cout << "\n                     /         +2222222222     four faces, edges of equal length and angles";
			cout << "\n                   /         ..222222222222    of equal size";
			cout << "\n                  /      ...........222222222";
			cout << "\n                /    ...................2222222";
			cout << "\n               / ...........................2222";
			cout << "\n             /...................................2\n\n";

			
			//Input
			cout << "\n	2)Tetrahedron input:";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double edgeLength = 0.0;
			cout << "\n	Enter an edge length (l) of the triangular pyramid: ";
			cin >> edgeLength;

			//Validate the edgeLength
			if (edgeLength <= 0.0)
			{
				cout << "\n	ERROR: Invalid input. Side length cannot be negative. Program terminates.";
				return -1; //Exit the program
			}

		
			// process
			double height = sqrt(2.0) / sqrt(3.0) * edgeLength;
			double area = pow(edgeLength,2) * sqrt(3);
			double volume = pow(edgeLength, 3) / (6.0 * sqrt(2));

		
			// output
			cout << "\n	Output of Tetrahedron:";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Edge length" << "(l)" << " = " << right << setw(10) << edgeLength;
			cout << left << setw(16) << "\n		Height" << "(h)" << " = " << right << setw(10) << height;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << area;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volume;

			break;
		}

		//Pentahedron 
		case 3:
		{
			//Display a pentahedron shape
			cout << "\n";
			cout << "\n             ++++++++++++++++++++++++++3";
			cout << "\n             | \\+++++++++++++++++++++/33";
			cout << "\n             |   \\+++++++++++++++++/3333";
			cout << "\n             |     \\+++++++++++++/333333";
			cout << "\n             |       \\+++++++++/33333333";
			cout << "\n             |         \\+++++/3333333333";
			cout << "\n             |           \\+/333333333333    Pentahedron - a pyramid with square base";
			cout << "\n             |            +3333333333333   and four triangular faces that are joined";
			cout << "\n             |           /.\\333333333333    at a vertex";
			cout << "\n             |         /.....\\3333333333";
			cout << "\n             |       /.........\\33333333";
			cout << "\n             |     /.............\\333333";
			cout << "\n             |   /.................\\3333";
			cout << "\n             | /.....................\\33";
			cout << "\n             |.........................3\n";

		
			
			//Input
			cout << "\n	3) Input of Pentahedron";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double lengthEdge = 0.0;
			cout << "\n		Enter a length edge (l) of the square pyramid: ";
			cin >> lengthEdge;

			//Validate the length edge
			if (lengthEdge <= 0)
			{
				cout << "\n	ERROR: Invalid input. Length edge cannot be negative. Program terminates.";
				return -1;
			}

		
		
			double height = 0.0;
			cout << "		Enter a height (h) of the square pyramid: ";
			cin >> height;

			//Validate the height
			if (height <= 0)
			{
				cout << "\n	ERROR: Invalid input. Height cannot be negative. Program terminates.";
				return -1;
			}

		
			//Process
			double area = lengthEdge * (lengthEdge + sqrt(pow(lengthEdge,2) + 4.0 * pow(height,2)) ) ; // Area = length * (length + sqrt(l*l + 4* height * height ) )
			double volume = 1.0 /3.0 * pow(lengthEdge,2) * height; //Volume = 1/3 * l^2 * height 

			//Output
			cout << "\n	Output of Pentahedron:";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n\t\tEdge length" << "(l)" << " = " << right << setw(10) << lengthEdge;
			cout << left << setw(16) << "\n\t\tHeight" << "(h)" << " = " << right << setw(10) << height;
			cout << left << setw(16) << "\n\t\tSurface Area" << "(A)" << " = " << right << setw(10) << area;
			cout << left << setw(16) << "\n\t\tVolume" << "(V)" << " = " << right << setw(10) << volume;

			break;
		}

		//Polyhedron
		case 4:
		{
			//Display a polyhedron shape
			cout << "\n";
			cout << "\n                                ++++++++++++++++++4";
			cout << "\n                         +++++++++++++++++++++++++4";
			cout << "\n                   +++++++++++++++++++++++++4444444";
			cout << "\n             ++++++++++++++++++++++++++/44444444444";
			cout << "\n             .                         444444444444    Polyhedron  - rectangular prism which has";
			cout << "\n             .                         444444444444    six faces that are rectangles. It has the";
			cout << "\n             .                         444444444444    same cross-section along a length";
			cout << "\n             .                         444444444444";
			cout << "\n             .                         444444444444";
			cout << "\n             .                         4444444444";
			cout << "\n             .                         4444444";
			cout << "\n             .                         4444";
			cout << "\n             ._________________________4\n";

		
			//Input
			cout << "\n	4) Input of Polyhedron";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double length = 0.0;
			cout << "\n		Enter a length (l) of the rectangular prism: ";
			cin >> length;

			//Length validation
			if (length <= 0.0)
			{
				cout << "\n		ERROR: Invalid input. Length cannot be negative. Program terminates.";
				return -1;
			}

		
		
			double width = 0.0;
			cout << "\n		Enter a width (w) of the rectangular prism: ";
			cin >> width;

			//Width validation
			if (width <= 0)
			{
				cout << "\n		ERROR: Invalid input. Width cannot be negative. Program terminates.";
				return -1;
			}

		
		
			double height = 0.0;
			cout << "\n		Enter a height (h) of the rectangular prism: ";
			cin >> height;

			//Height validation
			if (height <= 0)
			{
				cout << "\n		ERROR: Invalid input. Height cannot be negative. Program terminates.";
				return -1; //Exit the program
			}

		
		
			//Process
			double area = 2 * (length * width + length * height + height * width) ; 
			double volume = width * height * length;

			//Output
			cout << "\n	Output of Polyhedron:";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n\t\tLength" << "(l)" << " = " << right << setw(10) << length;
			cout << left << setw(16) << "\n\t\tWidth" << "(w)" << " = " << right << setw(10) << width;
			cout << left << setw(16) << "\n\t\tHeight" << "(h)" << " = " << right << setw(10) << height;
			cout << left << setw(16) << "\n\t\tSurface Area" << "(A)" << " = " << right << setw(10) << area;
			cout << left << setw(16) << "\n\t\tVolume" << "(V)" << " = " << right << setw(10) << volume;

			break;
		}

		case 5: // Torus
		{
			// Display torus shape
			cout << "\n                         . . .";
			cout << "\n                     .   5 5 5 555";
			cout << "\n                  .           5 5 555";
			cout << "\n                .               5 5 55.";
			cout << "\n               .                   5 555";
			cout << "\n              .           55.       5 555";
			cout << "\n             .        55       .    5 5155    Torus - a doughnut-shape formed by revolving a circle.";
			cout << "\n             .        55       .    5 5555    in three-dimensional space about an axis that lies in";
			cout << "\n             .        55       .    5 5555    the same plane as the circle";
			cout << "\n              .           ...5      5 555";
			cout << "\n               ..                  5 555";
			cout << "\n                ... .           5 5 555";
			cout << "\n                  ..5 5 5 5 5 5 5 555";
			cout << "\n                     5 5 5 5 5 555";
			cout << "\n                         5 5 5\n";

			cout << "\n	5) Input of Torus";
			cout << "\n	-----------------------------------------------------------------------------------------";

		
			//Input
			double majorRadius = 0.0;
			cout << "\n		Enter a major radius (R) of a doughnut: ";
			cin >> majorRadius;

			//Validation for major radius
			if (majorRadius <= 0)
			{
				cout << "\n		ERROR: Invalid input. Major radius cannot be negative. Program terminates.";
				return -1; //Exit the program
			}

		
			//Minor input
			double minorRadius = 0.0;
			cout << "		Enter a minor radius (r) of a doughnut: ";
			cin >> minorRadius;

			//Validation for minor radius
			if (minorRadius <= 0)
			{
				cout << "\n		ERROR: Invalid input. Minor radius cannot be negative. Program terminates.";
				return -1; //Exit the program
			}

		
		
			// Validation for minorRadius and majorRadius
			if (minorRadius >= majorRadius)
			{
				cout << "\n		ERROR: Invalid input. Major radius cannot be less than or equal to Minor radius. Program terminates.";
				return -1;
			}

		
			//Process
			double area = 4 * pow(PI,2) * majorRadius * minorRadius; // Area = 4*PI*PI*R*r
			double volume = 2 * pow(PI,2) * majorRadius * pow(minorRadius,2); //Volume = 2 * PI * PI * R * r * r

		
			//Output
			cout << "\n	Output of Torus";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n\t\tMinor Radius" << "(r)" << " = " << right << setw(10) << minorRadius;
			cout << left << setw(16) << "\n\t\tMajor Radius" << "(R)" << " = " << right << setw(10) << majorRadius;
			cout << left << setw(16) << "\n\t\tSurface Area" << "(A)" << " = " << right << setw(10) << area;
			cout << left << setw(16) << "\n\t\tVolume" << "(V)" << " = " << right << setw(10) << volume;

			break;
		}

		//Hemisphere
		case 6:
		{
			//Display hemisphere shape
			cout << "\n                         *****";
			cout << "\n                 **********************";
			cout << "\n             * ***************************    Hemisphere - a perfect half of a sphere";
			cout << "\n             ..  **********************111";
			cout << "\n              ..         ***** 6 6 6 666";
			cout << "\n               ...           6 6 6 6 666";
			cout << "\n                ....  . 6 6 6 6 6 6 666";
			cout << "\n                  ..6 6 6 6 6 6 6 666";
			cout << "\n                     6 6 6 6 6 666";
			cout << "\n                         . . .\n";

		
			//Input
			cout << "\n		6)Hemisphere input:";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double radius = 0.0;
			cout << "\n		Enter a radius of the hemisphere: ";
			cin >> radius;

			//Validation for major radius
			if (radius <= 0)
			{
				cout << "\n		ERROR: Invalid input. Radius cannot be negative. Program terminates.";
				return -1;
			}

		
		
			//Process
			double diameter = radius * 2;
			double area = 3 * PI * pow(radius,2);
			double volume = 2.0 / 3 * PI * pow(radius, 3);

		
		
			//Output
			cout << "\n		Hemisphere output:";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Radius" << "(r)" << " = " << right << setw(10) << radius;
			cout << left << setw(16) << "\n		Diameter" << "(d)" << " = " << right << setw(10) << diameter;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << area;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volume;

			break;
		}

		//Interactive input ALL Shape
		case 11:
		{
			//Sphere
			//Input
			cout << "\n		1) Input of Sphere";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double radius1 = 0.0;
			cout << "\n		Enter a radius for the sphere: ";
			cin >> radius1;

			//Validate the radius
			if (radius1 <= 0.0)
			{
				cout << "\n		ERROR: Invalid input. Radius cannot be negative. Program terminates.";
				return -1; //Exit the program
			}

			//Process
			double diameter1 = radius1 * 2; // Diameter = 2 * radius
			double areaSphere = 4 * PI * pow(radius1, 2); // Area = 4*PI*radius^2
			double volumeSphere = 4.0 / 3 * PI * pow(radius1, 3); // Volume = 4/3 * PI * radius^3

			//Output
			cout << "\n	Output of Sphere";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Radius" << "(r)" << " = " << right << setw(10) << radius1;
			cout << left << setw(16) << "\n		Diameter" << "(d)" << " = " << right << setw(10) << diameter1;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << areaSphere;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volumeSphere << "\n";



			//Tetrahedron
			//Input
			cout << "\n	2) Input of Tetrahedron";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double edgeLength2 = 0.0;
			cout << "\n		Enter an edge length (l) for the triangular pyramid: ";
			cin >> edgeLength2;

			//Validate the edgeLength
			if (edgeLength2 <= 0)
			{
				cout << "\n		ERROR: Invalid input. Edge length cannot be negative. Program terminates.";
				return -1;
			}

			//Process
			double height2 = sqrt(2.0) / sqrt(3.0) * edgeLength2;
			double areaTetrahedron = pow(edgeLength2, 2) * sqrt(3);
			double volumeTetrahedron = pow(edgeLength2, 3) / (6.0 * sqrt(2));

			//Output
			cout << "\n	Output of Tetrahedron:";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Edge length" << "(l)" << " = " << right << setw(10) << edgeLength2;
			cout << left << setw(16) << "\n		Height" << "(h)" << " = " << right << setw(10) << height2;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << areaTetrahedron;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volumeTetrahedron << "\n";



			//Pentahedron
			//Input
			cout << "\n	3) Input of Pentahedron";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double lengthEdge3 = 0.0;
			cout << "\n		Enter a length edge (l) for the square pyramid: ";
			cin >> lengthEdge3;

			//Validate the length edge
			if (lengthEdge3 <= 0)
			{
				cout << "\n		ERROR: Invalid input. Length edge cannot be negative. Program terminates.";
				return -1;
			}

			double height3 = 0.0;
			cout << "\n		Enter a height (h) for the square pyramid: ";
			cin >> height3;

			//Validate the height
			if (height3 <= 0)
			{
				cout << "\n		ERROR: Invalid input. Height cannot be negative. Program terminates.";
				return -1;
			}


			//Process
			double areaPentahedron = lengthEdge3 * (lengthEdge3 + sqrt(pow(lengthEdge3, 2) + 4.0 * pow(height3, 2)));
			double volumePentahedron = 1.0 / 3.0 * pow(lengthEdge3, 2) * height3;

			//Output
			cout << "\n	Output of Pentahedron:";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Edge length" << "(l)" << " = " << right << setw(10) << lengthEdge3;
			cout << left << setw(16) << "\n		Height" << "(h)" << " = " << right << setw(10) << height3;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << areaPentahedron;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volumePentahedron << "\n";



			//Polyhedron
			//Input
			cout << "\n	4) Input of Polyhedron";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double length4 = 0.0;
			cout << "\n		Enter a length (l) for the rectangular prism: ";
			cin >> length4;

			
			//Validation for length
			if (length4 <= 0)
			{
				cout << "\n		ERROR: Invalid input. Length cannot be negative. Program terminates.";
				return -1; //Exit the program
			}


			double width4 = 0.0;
			cout << "\n		Enter a width (w) for the rectangular prism: ";
			cin >> width4;

			//Validation for width
			if (width4 <= 0)
			{
				cout << "\n		ERROR: Invalid input. Width cannot be negative. Program terminates.";
				return -1; //Exit the program
			}

			double height4 = 0.0;
			cout << "\n		Enter a height (h) for the rectangular prism: ";
			cin >> height4;

			//Validation for height
			if (height4 <= 0)
			{
				cout << "\n		ERROR: Invalid input. Height cannot be negative. Program terminates.";
				return -1;
			}

			//Process
			double areaPolyhedron = 2 * (length4 * width4 + length4 * height4 + height4 * width4); // Area = 2(wl + lh + hw) 
			double volumePolyhedron = width4 * height4 * length4; // Volume = whl

			//Output
			cout << "\n	Output of Polyhedron:";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Length" << "(l)" << " = " << right << setw(10) << length4;
			cout << left << setw(16) << "\n		tWidth" << "(w)" << " = " << right << setw(10) << width4;
			cout << left << setw(16) << "\n		Height" << "(h)" << " = " << right << setw(10) << height4;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << areaPolyhedron;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volumePolyhedron << "\n";



			//Torus
			//Input
			cout << "\n	5) Input of Torus";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double majorRadius5 = 0.0;
			cout << "\n		Enter a major radius (R) for a doughnut: ";
			cin >> majorRadius5;

			//Validation for major radius
			if (majorRadius5 <= 0)
			{
				cout << "\n		ERROR: Invalid input. Major radius cannot be negative. Program terminates.";
				return -1;
			}

			double minorRadius5 = 0.0;
			cout << "\n	   Enter a minor radius (r) for a doughnut: ";
			cin >> minorRadius5;

			//Validation for minor radius
			if (minorRadius5 <= 0)
			{
				cout << "\n	   ERROR: Invalid input. Minor radius cannot be negative. Program terminates.";
				return -1;
			}

			if (minorRadius5 > majorRadius5)
			{
				cout << "\n	   ERROR: Invalid input. Major radius cannot be less than or equal to Minor radius. Program terminates.";
				return -1;
			}

			//Process
			double areaTorus = 4 * pow(PI, 2) * majorRadius5 * minorRadius5;
			double volumeTorus = 2 * pow(PI, 2) * majorRadius5 * pow(minorRadius5, 2);

			//Output
			cout << "\n	Output of Torus";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Minor Radius" << "(r)" << " = " << right << setw(10) << minorRadius5;
			cout << left << setw(16) << "\n		Major Radius" << "(R)" << " = " << right << setw(10) << majorRadius5;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << areaTorus;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volumeTorus << "\n";



			//Hemisphere
			//Input
			cout << "\n	6) Input of Hemisphere";
			cout << "\n	-----------------------------------------------------------------------------------------";

			double radius6 = 0.0;
			cout << "\n		Enter a positive value of radius for the hemisphere: ";
			cin >> radius6;

			//Validation for major radius
			if (radius6 <= 0)
			{
				cout << "\n		ERROR: Invalid input. Radius cannot be negative. Program terminates.";
				return -1;
			}

			//Process
			double diameter6 = radius6 * 2;
			double areaHemisphere = 3 * PI * pow(radius6, 2);
			double volumeHemisphere = 2.0 / 3 * PI * pow(radius6, 3);

			//Output
			cout << "\n	Output of Hemisphere";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << left << setw(16) << "\n		Radius" << "(r)" << " = " << right << setw(10) << radius6;
			cout << left << setw(16) << "\n		Diameter" << "(d)" << " = " << right << setw(10) << diameter6;
			cout << left << setw(16) << "\n		Surface Area" << "(A)" << " = " << right << setw(10) << areaHemisphere;
			cout << left << setw(16) << "\n		Volume" << "(V)" << " = " << right << setw(10) << volumeHemisphere;

			//Display all shapes
			cout << "\n\n	Summary Report";
			cout << "\n	========================================================================================\n";

			cout << left << setw(20) << "\n	Shape" << right << setw(20) << "Surface Area (A)" << setw(20) << "Volume (V)";
			cout << left << setw(20) << "\n	-------------" << right << setw(20) << "----------------" << setw(20) << "-------------";
			cout << left << setw(20) << "\n	Sphere" << right << setw(20) << areaSphere << setw(20) << volumeSphere;
			cout << left << setw(20) << "\n	Tetrahedron" << right << setw(20) << areaTetrahedron << setw(20) << volumeTetrahedron;
			cout << left << setw(20) << "\n	Pentahedron" << right << setw(20) << areaPentahedron << setw(20) << volumePentahedron;
			cout << left << setw(20) << "\n	Polyheron" << right << setw(20) << areaPolyhedron << setw(20) << volumePolyhedron;
			cout << left << setw(20) << "\n	Torus" << right << setw(20) << areaTorus << setw(20) << volumeTorus;
			cout << left << setw(20) << "\n	Hemisphere" << right << setw(20) << areaHemisphere << setw(20) << volumeHemisphere;
			cout << "\n";



			//Compare which shape is smallest shape
			double minimumShape = volumeSphere;

			minimumShape = volumeTetrahedron < minimumShape ? volumeTetrahedron : minimumShape;
			minimumShape = volumePentahedron < minimumShape ? volumePentahedron : minimumShape;
			minimumShape = volumePolyhedron < minimumShape ? volumePolyhedron : minimumShape;
			minimumShape = volumeTorus < minimumShape ? volumeTorus : minimumShape;
			minimumShape = volumeHemisphere < minimumShape ? volumeHemisphere : minimumShape;


			// Display the result
			if (minimumShape == volumeSphere)
				{
					cout << "\n	*  Sphere is the smallest object.";
				}

			else if (minimumShape == volumeTetrahedron)
				{
					cout << "\n	*  Tetrahedron is the smallest object.";
				}

			else if (minimumShape == volumePentahedron)
				{
					cout << "\n	*  Pentahedron is the smallest object.";
				}

			else if (minimumShape == volumePolyhedron)
				{
					cout << "\n	*  Polyhedron is the smallest object.";
				}

			else if (minimumShape == volumeTorus)
				{
					cout << "\n	*  Torus is the smallest object.";
				}

			else if (minimumShape == volumeHemisphere)
				{
					cout << "\n	*  Hemisphere is the smallest object.";
				}



			//Compare which shape is largest
			double maximumShape = volumeSphere;

			maximumShape = volumeTetrahedron > maximumShape ? volumeTetrahedron : maximumShape;
			maximumShape = volumePentahedron > maximumShape ? volumePentahedron : maximumShape;
			maximumShape = volumePolyhedron > maximumShape ? volumePolyhedron : maximumShape;
			maximumShape = volumeTorus > maximumShape ? volumeTorus : maximumShape;
			maximumShape = volumeHemisphere > maximumShape ? volumeHemisphere : maximumShape;


			//Display the result largest shape
			if (maximumShape == volumeSphere)
				{
					cout << "\n	** Sphere is the largest object.";
				}
			else if (maximumShape == volumeTetrahedron)
				{
					cout << "\n	** Tetrahedron is the largest object.";
				}

			else if (maximumShape == volumePentahedron)
				{
					cout << "\n	** Pentahedron is the largest object.";
				}

			else if (maximumShape == volumePolyhedron)
				{
					cout << "\n	** Polyhedron is the largest object.";
				}

			else if (maximumShape == volumeTorus)
				{
					cout << "\n	** Torus is the largest object.";
				}

			else if (maximumShape == volumeHemisphere)
			{
				cout << "\n	** Hemisphere is the largest object.";
			}

				break;
		}


		//Randomized input ALL shape
		case 12:
		{
			srand((unsigned int)time(0));


			//Sphere
			//Input
			double radius1 = (rand() % 1000 + 1) * 0.01;

			//Validate the radius
			if (radius1 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Radius cannot be negative. Program terminates.";
				return -1;
			}

			//Process
			double diameter1 = radius1 * 2;
			double areaSphere = 4 * PI * pow(radius1, 2);
			double volumeSphere = 4.0 / 3 * PI * pow(radius1, 3);

			//Output
			cout << "\n\n	1) Random generated input of Sphere";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << "\n	Radius of the sphere: " << radius1 << "\n";



			//Tetrahedron
			//input
			double edgeLength2 = (rand() % 1000 + 1) * 0.01;

			//Validate the edgeLength
			if (edgeLength2 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Edge length cannot be negative. Program terminates.";
				return -1;
			}

			//Process
			double height2 = sqrt(2.0) / sqrt(3.0) * edgeLength2;
			double areaTetrahedron = pow(edgeLength2, 2) * sqrt(3);
			double volumeTetrahedron = pow(edgeLength2, 3) / (6.0 * sqrt(2));

			//Output
			cout << "\n	2) Random generated input of Tetrahedron";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << "\n	Edge length (l) of the triangular pyramid: " << edgeLength2 << "\n";



			//Pentahedron
			//Input
			double edgeLength3 = (rand() % 1000 + 1) * 0.01;

			//Validate the length edge
			if (edgeLength3 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Length edge cannot be negative. Program terminates.";
				return -1;
			}

			double height3 = (rand() % 1000 + 1) * 0.01;

			//Validate the height
			if (height3 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Height cannot be negative. Program terminates.";
				return -1;
			}

			//Process
			double areaPentahedron = edgeLength3 * (edgeLength3 + sqrt(pow(edgeLength3, 2) + 4.0 * pow(height3, 2))); // area = l * (l + sqrt(l*l + 4*h*h) )
			double volumePentahedron = 1.0 / 3.0 * pow(edgeLength3, 2) * height3; // volume = 1/3 * l * l * h

			//Output
			cout << "\n	3) Random generated input of Pentahedron";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << "\n	Edge length (l) of the square pyramid: " << edgeLength3;
			cout << "\n	Height (h) of the square pyramid     : " << height3 << "\n";



			//Polyhedron
			//Input
			double length4 = (rand() % 1000 + 1) * 0.01;

			//Validation for length
			if (length4 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Length cannot be negative. Program terminates.";
				return -1;
			}

			double width4 = (rand() % 1000 + 1) * 0.01;

			//Validation for width
			if (width4 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Width cannot be negative. Program terminates.";
				return -1;
			}

			double height4 = (rand() % 1000 + 1) * 0.01;

			//Validation for height
			if (height4 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Height cannot be negative. Program terminates.";
				return -1;
			}

			//Process
			double areaPolyhedron = 2 * (length4 * width4 + length4 * height4 + height4 * width4);
			double volumePolyhedron = width4 * height4 * length4;

			//Output
			cout << "\n	4) Random generated input of Polyhedron";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << "\n	Length (l) of the rectangular prism: " << length4;
			cout << "\n	Width (w) of the rectangular prism : " << width4;
			cout << "\n	Height (h) of the rectangular prism: " << height4 << "\n";



			//Torus
			//Input
			double Radius5_1 = (rand() % 1000 + 1) * 0.01;

			//Validation for major radius
			if (Radius5_1 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Major radius cannot be negative. Program terminates.";
				return -1;
			}

			double Radius5_2 = (rand() % 1000 + 1) * 0.01;

			//Validation for minor radius
			if (Radius5_2 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Minor radius cannot be negative. Program terminates.";
				return -1;
			}

			double majorRadius = 0.0;
			double minorRadius = 0.0;
			
			//Validation to keep minorRadius smaller than majorRadius
			if (Radius5_2 > Radius5_1)
			{
					majorRadius = Radius5_2;
					minorRadius = Radius5_1;
			}
			
			else if (Radius5_2 = Radius5_1)
			{
					majorRadius = Radius5_2 + Radius5_1;
					minorRadius = Radius5_1;
			}
			
			else
			{
					majorRadius = Radius5_1;
					minorRadius = Radius5_2;
			}

			//Process
			double areaTorus = 4 * pow(PI, 2) * majorRadius * minorRadius;
			double volumeTorus = 2 * pow(PI, 2) * majorRadius * pow(minorRadius, 2);

			//Output
			cout << "\n	5) Random generated input of Torus";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << "\n	Major radius (R) of a doughnut: " << majorRadius;
			cout << "\n	Minor radius (r) of a doughnut: " << minorRadius << "\n";



			//Hemisphere
			//Input
			double radius6 = (rand() % 1000 + 1) * 0.01;

			//Validation for major radius
			if (radius6 <= 0)
			{
				cout << "\n	ERROR: Invalid input. Radius cannot be negative. Program terminates.";
				return -1;
			}

			//Process
			double diameter6 = radius6 * 2;
			double areaHemisphere = 3 * PI * pow(radius6, 2);
			double volumeHemisphere = 2.0 / 3 * PI * pow(radius6, 3);

			//Output
			cout << "\n	6)Random generated input of Hemisphere";
			cout << "\n	-----------------------------------------------------------------------------------------";
			cout << "\n	Radius of the hemisphere: " << radius6 << "\n";


			//Display all
			cout << "\n	Summary Report";
			cout << "\n	========================================================================================\n";
			cout << left << setw(20) << "\n	Shape" << right << setw(20) << "Surface Area (A)" << setw(20) << "Volume (V)";
			cout << left << setw(20) << "\n	-------------" << right << setw(20) << "----------------" << setw(20) << "-------------";
			cout << left << setw(20) << "\n	Sphere" << right << setw(20) << areaSphere << setw(20) << volumeSphere;
			cout << left << setw(20) << "\n	Tetrahedron" << right << setw(20) << areaSphere << setw(20) << volumeTetrahedron;
			cout << left << setw(20) << "\n	Pentahedron" << right << setw(20) << areaPentahedron << setw(20) << volumePentahedron;
			cout << left << setw(20) << "\n	Polyheron" << right << setw(20) << areaPolyhedron << setw(20) << volumePolyhedron;
			cout << left << setw(20) << "\n	Torus" << right << setw(20) << areaTorus << setw(20) << volumeTorus;
			cout << left << setw(20) << "\n	Hemisphere" << right << setw(20) << areaHemisphere << setw(20) << volumeHemisphere << "\n";


			//Compare which shape is smallest
			double minimumShape = volumeSphere;

			minimumShape = volumeTetrahedron < minimumShape ? volumeTetrahedron : minimumShape;
			minimumShape = volumePentahedron < minimumShape ? volumePentahedron : minimumShape;
			minimumShape = volumePolyhedron < minimumShape ? volumePolyhedron : minimumShape;
			minimumShape = volumeTorus < minimumShape ? volumeTorus : minimumShape;
			minimumShape = volumeHemisphere < minimumShape ? volumeHemisphere : minimumShape;



			//Display the result smallest spae
			if (minimumShape == volumeSphere)
			{
				cout << "\n	*  Sphere is the smallest object.";
			}

			else if (minimumShape == volumeTetrahedron)
			{
				cout << "\n	*  Tetrahedron is the smallest object.";
			}

			else if (minimumShape == volumePentahedron)
			{
				cout << "\n	*  Pentahedron is the smallest object.";
			}

			else if (minimumShape == volumePolyhedron)
			{
				cout << "\n	*  Polyhedron is the smallest object.";
			}

			else if (minimumShape == volumeTorus)
			{
				cout << "\n	*  Torus is the smallest object.";
			}

			else if (minimumShape == volumeHemisphere)
			{
				cout << "\n	*  Hemisphere is the smallest object.";
			}



			//Compare which shape is the largest
			double maximumShape = volumeSphere;

			maximumShape = volumeTetrahedron > maximumShape ? volumeTetrahedron : maximumShape;
			maximumShape = volumePentahedron > maximumShape ? volumePentahedron : maximumShape;
			maximumShape = volumePolyhedron > maximumShape ? volumePolyhedron : maximumShape;
			maximumShape = volumeTorus > maximumShape ? volumeTorus : maximumShape;
			maximumShape = volumeHemisphere > maximumShape ? volumeHemisphere : maximumShape;


			//Display the result largest shape
			if (maximumShape == volumeSphere)
			{
				cout << "\n	** Sphere is the largest object.";
			}

			else if (maximumShape == volumeTetrahedron)
			{
				cout << "\n	** Tetrahedron is the largest object.";
			}

			else if (maximumShape == volumePentahedron)
			{
				cout << "\n	** Pentahedron is the largest object.";
			}

			else if (maximumShape == volumePolyhedron)
			{
				cout << "\n	** Polyhedron is the largest object.";
			}

			else if (maximumShape == volumeTorus)
			{
				cout << "\n	** Torus is the largest object.";
			}

			else if (maximumShape == volumeHemisphere)
			{
				cout << "\n	** Hemisphere is the largest object.";
			}

			break;
		}

		return 0;
	}
}