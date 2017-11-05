#include "../common.cpp"
#define INPUTFILE "./sample.txt"

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
	
	int currentPositionX = numberOfLines - 1;//0;
	int currentPositionY = 0;
	int largestNumberToStartFrom[9999];
	for (int index = 9999; index >= 0; index--)
		largestNumberToStartFrom[index] = -1;
	for (int index = 0; index < numberOfLines; index++)
		largestNumberToStartFrom[theTriangle[currentPositionX][index]] = index + 1;
	for (int index = 9999; index > 0; index--)
		if (largestNumberToStartFrom[index] > 0)
		{
			currentPositionY = largestNumberToStartFrom[index] - 1;
			break;
		}
	long long maxSum = theTriangle[currentPositionX][currentPositionY];
	
	while (currentPositionX > 0)
	{
		currentPositionX--;
		
		if (theTriangle[currentPositionX][currentPositionY - 1] > theTriangle[currentPositionX][currentPositionY])
			currentPositionY--;
		
		cout << "Adding " << theTriangle[currentPositionX][currentPositionY] << " to " << maxSum << endl;
		maxSum += theTriangle[currentPositionX][currentPositionY];
	}
	
// 	long long forwardSums[8];
// 	long long largestForwardSum = 0;
// 	while (currentPositionX != numberOfLines - 1)
// 	{
// 		currentPositionX++;
// 		
// 		if (currentPositionX < numberOfLines - 1)
// 		{
// 			forwardSums[0] = theTriangle[currentPositionX][currentPositionY]
// 				+ theTriangle[currentPositionX + 1][currentPositionY]
// 				+ theTriangle[currentPositionX + 2][currentPositionY];
// 			forwardSums[1] = theTriangle[currentPositionX][currentPositionY]
// 				+ theTriangle[currentPositionX + 1][currentPositionY]
// 				+ theTriangle[currentPositionX + 2][currentPositionY + 1];
// 			forwardSums[2] = theTriangle[currentPositionX][currentPositionY]
// 				+ theTriangle[currentPositionX + 1][currentPositionY + 1]
// 				+ theTriangle[currentPositionX + 2][currentPositionY];
// 			forwardSums[3] = theTriangle[currentPositionX][currentPositionY]
// 				+ theTriangle[currentPositionX + 1][currentPositionY + 1]
// 				+ theTriangle[currentPositionX + 2][currentPositionY + 1];
// 			forwardSums[4] = theTriangle[currentPositionX][currentPositionY + 1]
// 				+ theTriangle[currentPositionX + 1][currentPositionY + 1]
// 				+ theTriangle[currentPositionX + 2][currentPositionY + 1];
// 			forwardSums[5] = theTriangle[currentPositionX][currentPositionY + 1]
// 				+ theTriangle[currentPositionX + 1][currentPositionY + 1]
// 				+ theTriangle[currentPositionX + 2][currentPositionY + 2];
// 			forwardSums[6] = theTriangle[currentPositionX][currentPositionY + 1]
// 				+ theTriangle[currentPositionX + 1][currentPositionY + 2]
// 				+ theTriangle[currentPositionX + 2][currentPositionY];
// 			forwardSums[7] = theTriangle[currentPositionX][currentPositionY + 1]
// 				+ theTriangle[currentPositionX + 1][currentPositionY + 2]
// 				+ theTriangle[currentPositionX + 2][currentPositionY + 3];
// 			
// 			largestForwardSum = 0;
// 			for (int index = 0; index < 8; index++)
// 				if (largestForwardSum < forwardSums[index])
// 					largestForwardSum = forwardSums[index];
// 				
// 			for (int index = 0; index < 8; index++)
// 				if (largestForwardSum == forwardSums[index] && index > 3)
// 				{
// 					currentPositionY++;
// 					cout << "Found the largestForwardSum as " << largestForwardSum << " and thus moving right" << endl;
// 					break;
// 				}
// 				else if (largestForwardSum == forwardSums[index])
// 				{
// 					cout << "Found the largestForwardSum as " << largestForwardSum << endl;
// 					break;
// 				}
// 		}
// 		else
// 			if (theTriangle[currentPositionX][currentPositionY + 1] > theTriangle[currentPositionX][currentPositionY])
// 				currentPositionY++;
// 			
// // 		if (currentPositionX < numberOfLines && theTriangle[currentPositionX][currentPositionY + 1] > theTriangle[currentPositionX][currentPositionY])
// // 			currentPositionY++;
// 		
// 		maxSum += theTriangle[currentPositionX][currentPositionY];
// 		cout << "Adding " << theTriangle[currentPositionX][currentPositionY] << endl;
// 	}
	
	cout << "The maximum sum path evaluated is " << maxSum << endl;
	
	return 0;
}