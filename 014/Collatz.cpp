#include <iostream>

using namespace std;

long long findNextCollatz(long long inputNumber);

static int startingNumbers[100000000];

int main()
{
	int count = 0;
	
	for (int startingNumber = 2; startingNumber <= 1000000; startingNumber++)
	{
		long long currentNumber = startingNumber;
		
		for (count = 0; ; count++)
			if (currentNumber != 1)
				currentNumber = findNextCollatz(currentNumber);
			else
				break;
		
		startingNumbers[count] = startingNumber;
	}
	
	for (int i = 99999999; i > 0; i--)
	{
		if (startingNumbers[i] > 0)
		{
			cout << "The number that forms the largest Collatz sequence of " << i << " numbers under a million is " << startingNumbers[i] << endl;
			break;
		}
	}
	
	return 0;
}

long long findNextCollatz(long long inputNumber)
{
	if (inputNumber % 2 == 0)
		return inputNumber/2;
	else
		return ((3 * inputNumber) + 1);
}