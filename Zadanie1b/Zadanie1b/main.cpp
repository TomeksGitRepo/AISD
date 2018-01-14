#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

unsigned long long newton_symbol(unsigned int n, unsigned int k, unsigned int &OUT_licz)      
{
	if (k == 0 || k == n)
	{
		return 1;
	}
	
	double score = 1;       // score variable

	for (unsigned int i = 1; i <= k; i++)  
	{
		++OUT_licz;
		score = score * (n - i + 1) / i;      
	}

	return (unsigned long long) score;     
}

vector<int> pascalTriangle(unsigned int n) {
	vector<int> pascalNumbers;
	int i, j, x;
	for (i = 0; i<n; i++)
	{
		x = 1;
		for (j = 0; j <= i; j++)
		{
			pascalNumbers.push_back(x);
			x = x * (i - j) / (j + 1);
			
		}
	}
	return pascalNumbers; //returning passcal triangle as flat representation of triangle
}

unsigned int silniaNewtonaWynik(vector<int> &pascalTriangle, unsigned int n, unsigned int k )
{

	return pascalTriangle[pascalTriangle.size() - (n+1) + k]; // off by one

}

int main(void)
{
	unsigned int n, k;
	unsigned int OUT_licz = 0; // conter variable
	string tempString = "";


	fstream inFile;
	inFile.open("In0101.txt");
	if (inFile.is_open())
	{
		inFile >> n >> k;
		inFile.close();
	}
	else
	{
		cout << "Error opening file";
	}

	ofstream outFile;
	outFile.open("Out0101.txt");
	if (outFile.is_open())
	{
		outFile <<"n=" <<  n << " "  << "k="<< k << "\n";
		outFile << "Sn2=" << newton_symbol(n, k, OUT_licz) << "; licz=";
		outFile << OUT_licz << endl;
		outFile.close();
	}
	else
	{
		cout << "Error opening file to write";
	}

	vector<int> pascalNumber = pascalTriangle(n + 1);
	unsigned int wynikDwumian = silniaNewtonaWynik(pascalNumber, n, k);
	cout << wynikDwumian << endl;
	
	system("pause");

	return 0;
}