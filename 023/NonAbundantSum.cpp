#include "../common.cpp"
#define MAXLIMIT 30000

using namespace std;

bool isAbundantNumber(long long number);

static int expressableAsSumOfAbundant[(MAXLIMIT * 2) + 1];
static int abundantNumbers[(MAXLIMIT * 2) + 1];

int main()
{
	long long sumOfNonAbundants = 0;
	
	for (int i = 1; i < MAXLIMIT; i++)
		if (isAbundantNumber(i))
			abundantNumbers[i] = i;
	
	for (int i = 1; i < MAXLIMIT; i++)
		for (int j = 1; j < MAXLIMIT; j++)
			if (abundantNumbers[i] > 0 && abundantNumbers[j] > 0)
				expressableAsSumOfAbundant[abundantNumbers[i] + abundantNumbers[j]] = abundantNumbers[i] + abundantNumbers[j];
	
	long long lastNumber = 0;
	for (int i = MAXLIMIT; i >= 0; i--)
		if (expressableAsSumOfAbundant[i] == 0)
		{
			sumOfNonAbundants += i;
			lastNumber = i;
			
			cout << i << endl;
		}
	
	cout << "The sum of all non anbundant numbers till " << lastNumber << " is " << sumOfNonAbundants << endl;
	
	return 0;
}

bool isAbundantNumber(long long number)
{
	long long sumOfFactors = 0;
	
	for (long long i = 1; i < number; i++)
		if (number % i == 0)
			sumOfFactors += i;
	
	if (sumOfFactors > number)
		return true;
	
	return false;
}