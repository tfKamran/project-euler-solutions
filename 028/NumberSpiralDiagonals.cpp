#include "../common.cpp"

using namespace std;

long long addCornersUpto(int numberOfSpirals);

int main()
{
	cout << "The sum of the numbers on the diagonals in a 1001 by 1001 spiral is " << addCornersUpto(1001) << endl;
	
	return 0;
}

long long addCornersUpto(int numberOfSpirals)
{
	int currentElement = 1;
	int distaceBetweenElements = 0;
	long long sumOfCorners = 1;
	
	for (int i = 2; i <= numberOfSpirals/2 + 1; i++)
	{
		distaceBetweenElements += 2;
		
		for (int j = 0; j < 4; j++)
		{
			currentElement += distaceBetweenElements;
			sumOfCorners += currentElement;
			
			cout << "Adding " << currentElement << endl;
		}
	}
	
	return sumOfCorners;
}