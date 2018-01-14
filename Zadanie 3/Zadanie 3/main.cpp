#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(void) {
	int workedMonths = 0;
	vector<int> monthlyGains = { };

	int firstMonth = 1;
	
	int lastMonth = 1;
	int maxScore = 0;
	int maxMonthStart = 0;
	int maxMonthFinish = 0;

	// *********** Take data from file *************
	fstream inFile;
	inFile.open("In0103.txt");
	if (inFile.is_open())
	{
		int tempVariable = 0;
		inFile >> workedMonths;
		while (inFile >> tempVariable)
		{
			monthlyGains.push_back(tempVariable);
		}

		inFile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	//************* End of data input ****************

	

	
	for (int timeLenght = 1; timeLenght < monthlyGains.size(); timeLenght++)
	{
		
		
		int score = 0;
		for (int counter = 0; counter < monthlyGains.size(); counter++)
		{ 
			for (int firstMonthtoCalculate = 0; firstMonthtoCalculate < monthlyGains.size(); firstMonthtoCalculate++)
			{
				
				int score = 0;
				for (int i = 0; i < counter; i++)
				{
					if (firstMonthtoCalculate + i >= monthlyGains.size())
					{
						break;
					}
					score += monthlyGains[firstMonthtoCalculate + i];
				}
				

				if (score > maxScore)
				{
					maxScore = score;
					maxMonthStart = firstMonthtoCalculate + 1; //off by one
					maxMonthFinish = counter; 
				}
			
			}
		
		}
		
	}

	//********************** Output to file ************
	ofstream outFile;
	outFile.open("Out0103.txt");
	if (outFile.is_open())
	{
		outFile << maxScore << " " << maxMonthStart << " " << maxMonthStart + maxMonthFinish - 1 ;
		outFile.close();
	}
	else
	{
		cout << "Error opening file to write";
	}
	//********************** Output to file ************


	cout << "MaxScore:" << maxScore << endl;
	cout << "MaxMonthStart: " <<  maxMonthStart << endl;
	cout << "MaxLastMonth: " <<maxMonthStart + maxMonthFinish -1  << endl; // -1 so we dont get first month included last position exluded < x, y )

	system("pause");

	return 0;
}