#include "../common.cpp"
#define INPUTFILE "./input.txt"

using namespace std;

static string* inputTriangle;
int theTriangle[100][100];

static int sums[100000000];
	
int main()
{
	int numberOfLines = common.countLinesInFile(INPUTFILE);
	cout << numberOfLines << " rows found. Calculating..." << endl;
	
	// Get the traingle from file
	inputTriangle = common.fetchFromFile(INPUTFILE);
	for (int i = 0; i < numberOfLines; i++)
		for (int j = 0; j <= i; j++)
			theTriangle[i][j] = common.CInt(inputTriangle[i].substr(j * 3, 2));
	
	// Calculate all the possible paths
	long long numberOfPossiblePaths = common.raiseTo(2, numberOfLines);
	string paths[numberOfPossiblePaths];
	for (long long i = 0; i < numberOfPossiblePaths; i++)
		paths[i] = common.toBinary(i, numberOfLines);
	
	// Get all the sums
	for (long long i = 0; i < numberOfPossiblePaths; i++)
	{
		string currentPath = paths[i];
		
		int currentSum = 0;
		int positionLocator = 0;
		
		for (int move = 0; move < numberOfLines; move++)
		{
			if (currentPath.substr(move, 1) == "1")
				positionLocator++;
			
			currentSum += theTriangle[move][positionLocator];
		}
		sums[currentSum] = currentSum;
	}
	
	for (int i = 99999999; i > 0; i--)
		if (sums[i] > 0)
		{
			cout << "The largest sum is " << sums[i] << endl;
			break;
		}
	
	return 0;
}