#include<iostream>
#include<cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int NWD(int a, int b)
{
	if (a != b)
		return NWD(a>b ? a - b : a, b>a ? b - a : b);
	return a;
}

int main()
{
	int a, b;

	// *********** Take data from file *************
	fstream inFile;
	inFile.open("In0203.txt");
	if (inFile.is_open())
	{
		inFile >> a >> b;

		inFile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	//************* End of data input ****************

	
	//********************** Output to file ************
	ofstream outFile;
	outFile.open("Out0201.txt");
	if (outFile.is_open())
	{

		outFile << "NWD("<< a << "," << b << ")="<< NWD(a,b);
		
		outFile.close();
	}
	else
	{
		cout << "Error opening file to write";
	}
	//********************** Output to file ************


	cin >> a;
	return 0;
}


