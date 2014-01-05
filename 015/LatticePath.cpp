#include <iostream>
#include <string>
#include <sstream>
#define GRID 3

using namespace std;

long long raiseTo(long long base, int power);
void countPathsThroughBinary(long long decimalNumber);
int countOfOnes;
long long countOfPaths;
long long numberOfCombinations;
long long highestDegree;

int main()
{	
	numberOfCombinations = raiseTo(2, GRID * 2);
	countOfPaths = 0;
	
	for (long long i = numberOfCombinations; i > 0; i--)
		countPathsThroughBinary(i);
	
	cout << "Combinations: " << numberOfCombinations << endl;
	
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

void countPathsThroughBinary(long long decimalNumber)
{
	highestDegree = numberOfCombinations / 2;
	countOfOnes = 0;
	string binary;
	
	for (; highestDegree >= 1; highestDegree /= 2)
	{
		if (decimalNumber >= highestDegree)
		{
			decimalNumber -= highestDegree;
			countOfOnes++;
			binary += "1";
		}
		else
		{
			binary += "0";
		}
	}
	
	if (countOfOnes == GRID)
	{
		countOfPaths++;
		cout << binary << endl;
	}
}