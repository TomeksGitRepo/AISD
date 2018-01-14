#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

string s1, s2, sLCS; // zmienne globalne

					 // Funkcja oblicza d³ugoœæ LCS dla s1 i s2
					 // i - indeks startu w s1
					 // j - indeks startu w s2
					 //----------------------------------------
int LCS(int i, int j)
{
	if (!s1[i] || !s2[j]) return 0;
	else if (s1[i] == s2[j]) return 1 + LCS(i + 1, j + 1);
	else return max(LCS(i + 1, j), LCS(i, j + 1));
}

int main()
{
	int i, j;

	// *********** Take data from file *************
	fstream inFile;
	inFile.open("In0301.txt");
	if (inFile.is_open())
	{
		inFile >> s1 >> s2; // change m to starting point

		inFile.close();
	}
	else
	{
		cout << "Error opening file";
	}

	//************* End of data input ****************

	sLCS = ""; i = j = 0;
	while (s1[i] && s2[j])
		if (s1[i] == s2[j])
		{
			sLCS += s1[i]; i++; j++;
		}
		else if (LCS(i + 1, j) <= LCS(i, j + 1)) j++; else i++;
		
		//********************** Output to file ************
		ofstream outFile;
		outFile.open("Out0301.txt");
		if (outFile.is_open())
		{
			outFile << sLCS;

			

			outFile.close();
		}
		else
		{
			cout << "Error opening file to write";
		}
		//********************** Output to file ************
		
		system("pause");
		return 0;
}