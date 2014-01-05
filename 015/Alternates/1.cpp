#include <iostream>
#include <string>
#include <sstream>
#define GRID 1

using namespace std;

long long raiseTo(long long base, int power);
string toBinary(long long decimalNumber);

long long numberOfCombinations;

int main()
{	
	numberOfCombinations = raiseTo(2, GRID * 2);
	string currentBinary = "";
	int countOfOnes = 0;
	long long countOfPaths = 0;
	
	for (long long i = 1; i < numberOfCombinations; i++)
	{
		currentBinary = toBinary(i);
// 		cout << i << ": " << currentBinary << endl;
		
		countOfOnes = 0;
		for (int j = 0; j < GRID * 2; j++)
			if (currentBinary.substr(j, 1) == "1")
				countOfOnes++;
		
		if (countOfOnes == GRID)
			countOfPaths++;
	}
	
	cout << "The number of possible paths is " << countOfPaths << endl;
	
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
/*
 * 0011
 * 0101
 * 0110
 * 1001
 * 0101
 * 1100
 * 
 * 2x2 grid has two 0s and two 1s in all binary combinations
 */