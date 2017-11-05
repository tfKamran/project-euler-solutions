#include "../common.cpp"

using namespace std;

void generatePentagonalNumbers();
long long getTheRequiredPentagonalNumber();

bool pentagonalNumbers[1000000000];

int main()
{
	generatePentagonalNumbers();
	
	cout << "The required pantagonal number is " << getTheRequiredPentagonalNumber() << endl;
	
	common.finalize();
	return 0;
}

void generatePentagonalNumbers()
{
	long long pentagonalNumber = 1;
	
	for (long long index = 0; pentagonalNumber < 1000000000; index++)
	{
		pentagonalNumbers[pentagonalNumber] = true;
		pentagonalNumber = (index * ((3 * index) - 1))/2;
	}
}

long long getTheRequiredPentagonalNumber()
{
	for (long long number = 1; number < 1000000000; number++)
		if (pentagonalNumbers[number])
			for (long long index = 2; index < number; index++)
				if (pentagonalNumbers[index] && pentagonalNumbers[number + index] && pentagonalNumbers[number - index])
				{
					cout << endl << number << " and " << index << endl;
					return number - index;
				}
}