#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define GRID 20

using namespace std;

long long raiseTo(long long base, int power);
string toBinary(long long decimalNumber);
void writeTheOutput(string inputLine);

long long numberOfCombinations;
string currentBinary;

int main()
{	
	numberOfCombinations = raiseTo(2, GRID);
	
	currentBinary = "";
	for (long long i = 1; i < numberOfCombinations; i++)
	{
		currentBinary += toBinary(i) + "\n";
	}	
	writeTheOutput(currentBinary);
	cout << "Process 0" << endl;
	
	for (int j = 1; j <= GRID; j++)
	{
		numberOfCombinations = raiseTo(2, GRID + j);
		currentBinary = "";
		for (long long i = raiseTo(2, GRID + j - 1); i < numberOfCombinations; i++)
		{
			currentBinary += toBinary(i) + "\n";
		}	
		writeTheOutput(currentBinary);
		cout << "Process " << j << endl;
	}
	
	cout << "Process completed." << endl;
	
	return 0;
}

long long raiseTo(long long base, int power)
{
	long long returnValue = base;
	
	for (; power > 1; power--)
		returnValue *= base;
	
	return returnValue;
}

string toBinary(long long decimalNumber)
{
	long long highestDegree = numberOfCombinations / 2;
	string binaryString = "";
	
	for (; highestDegree >= 1; highestDegree /= 2)
	{
		if (decimalNumber >= highestDegree)
		{
			decimalNumber -= highestDegree;
			binaryString += "1";
		}
		else
			binaryString += "0";
	}
	
	return binaryString;
}

void writeTheOutput(string inputLine)
{
	string fileContent = "";
	ifstream inputReader ("./output.txt");
  
  string line = "";
  while (getline(inputReader, line))
    fileContent += line + "\n";
  inputReader.close();
	
	fileContent += inputLine;
	
	ofstream outputWriter ("./output.txt");
	outputWriter << fileContent << endl;
	outputWriter.close();
}