#include <iostream>
#include <string>
#include <sstream>
#define GRID 3

using namespace std;

long long raiseTo(long long base, int power);

long long countOfPaths;

int main()
{	
	countOfPaths = 0;
	int columnCount;
	
	for (int i = 0; i < GRID * 2; i++)
		/*if (i == 0)
			countOfPaths += 2;
		else*/ if (i < GRID)
			for (int j = 0; j < i; j++)
				countOfPaths += 2;
		else if (i == GRID)
		{
			for (int j = 1; j < i - 1; j++)
				countOfPaths += 2;
			countOfPaths += 2;
		}
		else
		{
			for (int j = 1; j < GRID + 2 - i; j++)
				countOfPaths += 2;
			countOfPaths += 2;
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