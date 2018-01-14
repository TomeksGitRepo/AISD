#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#define w 6 //ilosc wierzcholkow
#define niesk 32123

using namespace std;

int *D, *N, np;
int najmniejszy();
void Dijkstra(int);
int m, n;
struct S_kraw
{
	int gdzie;
	int waga;
};
struct S_wierz
{
	int ile_kraw;
	struct S_kraw *kraw;
	void dodaj_kraw(int, int);
	void zwolnij_pamiec();
};
struct S_wierz *wierz;
void S_wierz::dodaj_kraw(int dest, int length)
{
	this->ile_kraw++;
	this->kraw = (struct S_kraw *) realloc(this->kraw, ((sizeof(struct S_kraw))*(this->ile_kraw)));
	this->kraw[this->ile_kraw - 1].gdzie = dest;
	this->kraw[this->ile_kraw - 1].waga = length;
}
void S_wierz::zwolnij_pamiec()
{
	free(this->kraw);
	this->kraw = NULL;
}

int main()
{
	

	// *********** Take data from file *************
	fstream inFile;
	inFile.open("In0304.txt");
	if (inFile.is_open())
	{
		inFile >> n >> m; // change m to starting point




	

	wierz = new struct S_wierz[n];

	

	for (int i = 0; i<n; i++)
	{
		wierz[i].ile_kraw = 0;
		wierz[i].kraw = NULL;
	}
	int a, b, c;
	
		for (a = 0; a < n ; a++)
		{
			for (b = 0; b < n; b++)
			{
				inFile >> c;
				wierz[(a )].dodaj_kraw((b ), c);
			}
	};
		inFile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	
	//************* End of data input ****************
	vector<int> distResultsVector(1, 0); //initalize distresultVector

	Dijkstra(m - 1);

	for (int i = 1; i < n; i++) // fill vector with results
	{
		distResultsVector.push_back(D[i]);
	}
			
	//********************** Output to file ************
	ofstream outFile;
	outFile.open("Out0304.txt");
	if (outFile.is_open())
	{
		outFile << "dist[";
		
		for each (auto item in distResultsVector)
		{
			outFile << item << ",";
		}
		outFile << "]";

		outFile.close();
	}
	else
	{
		cout << "Error opening file to write";
	}
	//********************** Output to file ************

	system("pause");

	delete[] D, N;
	return 0;
}

void Dijkstra(int s)
{
	np = 0; //ilosc wierzcholkow niepewnych
	D = new int[n];
	N = new int[n];

	for (int i = 0; i<n; i++) D[i] = niesk;
	for (int i = 0; i<wierz[s].ile_kraw; i++) D[wierz[s].kraw[i].gdzie] = wierz[s].kraw[i].waga;
	D[s] = 0;
	for (int i = 0; i<n; i++)
	{
		if (i == s) continue;
		N[np++] = i;
	};

	while (np>0)
	{
		int i = najmniejszy();
		for (int k = 0; k<wierz[i].ile_kraw; k++)
			if (D[wierz[i].kraw[k].gdzie] > D[i] + wierz[i].kraw[k].waga)
				D[wierz[i].kraw[k].gdzie] = D[i] + wierz[i].kraw[k].waga;

	}
}

int najmniejszy()
{
	int val, num, result;
	val = niesk;
	for (int i = 0; i<np; i++)
	{
		if (D[N[i]] < val)
		{
			val = D[N[i]];
			num = i;
		}
	}
	result = N[num];
	np--;
	N[num] = N[np];
	return result;
}