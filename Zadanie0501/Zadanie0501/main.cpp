#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Typy dla dynamicznej tablicy list s¹siedztwa i stosu

struct slistEl
{
	slistEl * next;
	int v;
};

class stack
{
private:
	slistEl * S;   // lista przechowuj¹ca stos

public:
	stack();       // konstruktor
	~stack();      // destruktor
	bool empty(void);
	int  top(void);
	void push(int v);
	void pop(void);
};

//---------------------
// Metody obiektu stack
//---------------------

// Konstruktor
//------------
stack::stack()
{
	S = NULL;
}

// Destruktor - zwalnia tablicê dynamiczn¹
//----------------------------------------
stack::~stack()
{
	while (S) pop();
}

// Sprawdza, czy stos jest pusty
//------------------------------
bool stack::empty(void)
{
	return !S;
}

// Zwraca szczyt stosu
//--------------------
int stack::top(void)
{
	return S->v;
}

// Zapisuje na stos
//-----------------
void stack::push(int v)
{
	slistEl * e = new slistEl;
	e->v = v;
	e->next = S;
	S = e;
}

// Usuwa ze stosu
//---------------
void stack::pop(void)
{
	if (S)
	{
		slistEl * e = S;
		S = S->next;
		delete e;
	}
}

// Zmienne globalne
//-----------------
int n;                   // Liczba wierzcho³ków
slistEl ** A;            // Macierz s¹siedztwa

						 // Procedura szukania œcie¿ki
						 // vs - numer wierzcho³ka startowego
						 // vk - numer wierzcho³ka koñcowego
						 //----------------------------------
bool DFS_Path(int vs, int vk)
{
	stack S;
	bool * visited, found;
	int  * P, v, u, i;
	slistEl * pv;

	visited = new bool[n];   // Tworzymy tablice odwiedzin
	for (i = 0; i < n; i++)   // Tablicê visited zerujemy
		visited[i] = false;

	P = new int[n];          // Tworzymy tablicê œcie¿ki

	P[vs] = -1;

	S.push(vs);              // Na stosie umieszczamy wierzcho³ek startowy

	visited[vs] = true;      // Wierzcho³ek startowy oznaczamy jako odwiedzony

	found = false;

	while (!S.empty())
	{
		v = S.top();           // Pobieramy ze stosu wierzcho³ek v
		S.pop();

		if (v == vk)            // Sprawdzamy, czy osi¹gnêliœmy wierzcho³ek koñcowy
		{
			found = true;  // Zaznaczamy sukces
			delete[] P;
			delete[] visited;
			return true;               // Przerywamy pêtlê
		}

		// Przegl¹damy s¹siadów wierzcho³ka v

		for (pv = A[v]; pv; pv = pv->next)
		{
			u = pv->v;
			if (!visited[u])
			{
				P[u] = v;        // W P zapisujemy fragment œcie¿ki
				S.push(u);       // S¹siad zostaje umieszczony na stosie
				visited[u] = true; // i oznaczony jako odwiedzony
			}
		}
	}

	delete[] P;
	delete[] visited;
	if (!found) return false; // Œcie¿ka nie zosta³a znaleziona


	
}

// **********************
// *** PROGRAM G£ÓWNY ***
// **********************

int main()
{

	/*
	int m, i, v1, v2;
	slistEl *p, *r;

	cin >> n >> m;               // Czytamy liczbê wierzcho³ków i krawêdzi

	A = new slistEl *[n];       // Tworzymy tablicê list s¹siedztwa

								// Tablicê wype³niamy pustymi listami

	for (i = 0; i < n; i++) A[i] = NULL;

	// Odczytujemy kolejne definicje krawêdzi

	for (i = 0; i < m; i++)
	{
		cin >> v1 >> v2;    // Wierzcho³ek startowy i koñcowy krawêdzi
		p = new slistEl;    // Tworzymy nowy element
		p->v = v2;          // Numerujemy go jako v2
		p->next = A[v1];    // Dodajemy go na pocz¹tek listy A[v1]
		A[v1] = p;
	}

	// Odczytujemy wierzcho³ek startowy i koñcowy œcie¿ki

	cin >> v1 >> v2;

	cout << endl;

	DFS_Path(v1, v2);      // Szukamy œcie¿ki

						   // Usuwamy tablicê list s¹siedztwa

	for (i = 0; i < n; i++)
	{
		p = A[i];
		while (p)
		{
			r = p;
			p = p->next;
			delete r;
		}
	}
	//delete[] A;

	cout << endl;
	system("pause");

	*/



	int m = 5; // wspolczynnik bezpieczenstwa
	double CHF = 0.0;
	double EUR = 0.0;
	int k = 0; //starting point
	int t = 0; // end point

	double** matrixOfValues = new double*[n]; // matrix with values
	bool** matrixOfPaths = new bool*[n]; // matrix with connecting path


	 // *********** Take data from file *************
	fstream inFile;
	inFile.open("In0501.txt");
	if (inFile.is_open())
	{
		inFile >> n >> m >> CHF >> EUR >> k >> t; // change m to starting point


		for (int i = 0; i < n; ++i)
		{
			matrixOfValues[i] = new double[n];
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; j++)
				inFile >> matrixOfValues[i][j];
		}

		inFile.close();
	}
	else
	{
		cout << "Error opening file";
	}

	//************* End of data input ****************


	//**********Print values matrix***********//

	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			double temp = matrixOfValues[i][j];
			cout << temp;
		}
		cout << endl;
	}
	*/

	//***************************************


	// values taken from file into matrixOfVAlues

	for (int i = 0; i < n; ++i)
	{
		matrixOfPaths[i] = new bool[n];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			matrixOfPaths[i][j] = false;
		}
	} //initializa matrixofPaths with false values

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			if (m*(1 - matrixOfValues[i][j]) > CHF - EUR)
			{
				matrixOfPaths[i][j] = true;
			}

		}
	}// add values with made graph



	//**************Count conntection in praph
	int connectionCount = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrixOfPaths[i][j])
			{
				connectionCount++;
			}
		}
	}






	//********************** Output to file for temp output ************
	ofstream outFileTemp;
	outFileTemp.open("Out0504VectorsTemp.txt");
	if (outFileTemp.is_open())
	{
		outFileTemp << n << " " << connectionCount << '\n';

		//**********Outputfor temporary file
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrixOfPaths[i][j])
				{
					outFileTemp << i + 1 << " " << j + 1 << " ";
				}
			}
			outFileTemp << '\n';
		}

		outFileTemp.close();
	}
	else
	{
		cout << "Error opening file to write";
	}
	//********************** Output to file ************



	//********************* Taking data from file and output score

	int i, v1, v2;
	slistEl *p, *r;

	inFile.open("Out0504VectorsTemp.txt");
	{
		inFile >> n >> m;               // Czytamy liczbê wierzcho³ków i krawêdzi

		A = new slistEl *[n];       // Tworzymy tablicê list s¹siedztwa

									// Tablicê wype³niamy pustymi listami

		for (i = 0; i < n; i++) A[i] = NULL;

		// Odczytujemy kolejne definicje krawêdzi

		for (i = 0; i < m; i++)
		{
			inFile >> v1 >> v2;    // Wierzcho³ek startowy i koñcowy krawêdzi
			p = new slistEl;    // Tworzymy nowy element
			p->v = v2;          // Numerujemy go jako v2
			p->next = A[v1];    // Dodajemy go na pocz¹tek listy A[v1]
			A[v1] = p;
		}
		inFile.close();
	}



	ofstream outFileFinal;
	outFileFinal.open("Out0504.txt");
	if (outFileFinal.is_open())
	{

		vector<int> pointWithInternalLoop = vector<int>();



		for (int c = 1; c < m; c++)
		{
			if (DFS_Path(k, c) && DFS_Path(c, k)) // sprawdzamy sciezki dla wszystkich punktow
			{
				pointWithInternalLoop.push_back(c);
			}
		}


		bool isInVector = false;

		for each (auto item in pointWithInternalLoop)
		{
			if (item == t)
			{
				isInVector = true;

			}
			outFileFinal << item << ' ' ;
		}

		outFileFinal << endl;

		if (!isInVector)
		{
			pointWithInternalLoop.clear();

			for (int d = 1; d < m; d++)
			{
				if (DFS_Path(t, d) && DFS_Path(d, t)) // sprawdzamy sciezki dla wszystkich punktow
				{
					pointWithInternalLoop.push_back(d);
				}
			}

			for each (auto item in pointWithInternalLoop)
			{
				outFileFinal << item << ' ';
			}

			outFileFinal.close();
		}


	}
					  

		for (i = 0; i < n; i++)  // Usuwamy tablicê list s¹siedztwa
		{
			p = A[i];
			while (p)
			{
				r = p;
				p = p->next;
				delete r;
			}
		}
		delete[] A;


		cout << endl;
		

		cin >> n;



	

	return 0;
}