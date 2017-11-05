#include "../common.cpp"
#define INPUTFILE "./matrix.txt"
using namespace std;

static string* inputMatrix;
int theMatrix[80][80];

int main()
{
	int numberOfLines = common.countLinesInFile(INPUTFILE);
	cout << numberOfLines << " rows found. Calculating..." << endl;
	
	// Get the matrix from file
	inputMatrix = common.fetchFromFile(INPUTFILE);
	for (int i = 0; i < numberOfLines; i++)
		for (int j = 0; j < numberOfLines; j++)
		{
			if (common.stringContains(inputMatrix[i], ", "))
			{
				theMatrix[i][j] = common.CInt(inputMatrix[i].substr(0, common.stringIndexOf(inputMatrix[i], ", ")));
				inputMatrix[i] = inputMatrix[i].substr(common.stringIndexOf(inputMatrix[i], ", ") + 2, inputMatrix[i].length() - common.stringIndexOf(inputMatrix[i], ", ") + 2);
			}
			else
				theMatrix[i][j] = common.CInt(inputMatrix[i]);
		}
	
	int currentPositionX = numberOfLines - 1;//0;
	int currentPositionY = numberOfLines - 1;//0;
	long long minSum = theMatrix[currentPositionX][currentPositionY];
	while (! (currentPositionX == 0 && currentPositionY == 0))
	{
		if (currentPositionX > 0 && currentPositionY > 0)
			if (theMatrix[currentPositionX - 1][currentPositionY] < theMatrix[currentPositionX][currentPositionY - 1])
				currentPositionX--;
			else
				currentPositionY--;
		else if (currentPositionX > 0)
			currentPositionX--;
		else
			currentPositionY--;
		
		minSum += theMatrix[currentPositionX][currentPositionY];
	}
		
	
// 	long long forwardSums[4];
// 	long long smallestForwardSum = 0;
// 	while (! (currentPositionX >= numberOfLines - 1 && currentPositionY >= numberOfLines - 1))
// 	{
// 		if (currentPositionX < numberOfLines - 2 && currentPositionY < numberOfLines - 2)
// 		{
// 			forwardSums[0] = theMatrix[currentPositionX + 1][currentPositionY]
// 				+ theMatrix[currentPositionX + 2][currentPositionY];
// 			forwardSums[1] = theMatrix[currentPositionX + 1][currentPositionY]
// 				+ theMatrix[currentPositionX + 1][currentPositionY + 1];
// 			forwardSums[2] = theMatrix[currentPositionX][currentPositionY + 1]
// 				+ theMatrix[currentPositionX + 1][currentPositionY + 1];
// 			forwardSums[3] = theMatrix[currentPositionX][currentPositionY + 1]
// 				+ theMatrix[currentPositionX][currentPositionY + 2];
// 			
// 			smallestForwardSum = forwardSums[0];
// 			for (int index = 0; index < 4; index++)
// 				if (smallestForwardSum > forwardSums[index])
// 				{
// 					smallestForwardSum = forwardSums[index];
// 					cout << "smallestForwardSum " << smallestForwardSum << " at " << index << endl;
// 				}
// 			
// 				
// 			for (int index = 0; index < 4; index++)
// 				if (smallestForwardSum == forwardSums[index] && index > 1)
// 				{
// 					currentPositionY++;
// 					cout << "Found the smallestForwardSum as " << smallestForwardSum << " and thus moving right" << endl;
// 					break;
// 				}
// 				else if (smallestForwardSum == forwardSums[index])
// 				{
// 					currentPositionX++;
// 					cout << "Found the smallestForwardSum as " << smallestForwardSum << " and thus moving down" << endl;;
// 					break;
// 				}
// 		}
// 		else
// 		{
// 			cout << "last parts of the grid X:" << currentPositionX << " Y:" << currentPositionY << endl;
// 			
// 			if (currentPositionX < numberOfLines - 1 && currentPositionY < numberOfLines - 1 && theMatrix[currentPositionX + 1][currentPositionY] < theMatrix[currentPositionX][currentPositionY + 1])
// 				currentPositionX++;
// 			else if (currentPositionX < numberOfLines - 1 && currentPositionY < numberOfLines - 1 && theMatrix[currentPositionX + 1][currentPositionY] > theMatrix[currentPositionX][currentPositionY + 1])
// 				currentPositionY++;
// 			else if (currentPositionX < numberOfLines)
// 				currentPositionX++;
// 			else
// 				currentPositionY++;
// 		}
// 			
// 		minSum += theMatrix[currentPositionX][currentPositionY];
// 		cout << "Adding " << theMatrix[currentPositionX][currentPositionY] << endl;
// 	}
	
	cout << "The minimum sum path evaluated is " << minSum << endl;
	
	return 0;
}