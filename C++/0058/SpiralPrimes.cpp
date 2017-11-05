#include "../common.cpp"

using namespace std;

class functions
{
public:
	long long checkForRatio(double requiredRatio)
	{
		vector<bool> isPrime = common.getPrimesUpto(688590082);
		
		long long currentElement = 1;
		long long distaceBetweenElements = 0;
		long long countOfPrimes = 0;
		long long countOfNumbersOnTheDiagonal = 1;
		long long numberOfSpirals;
		
		for (numberOfSpirals = 2; ; numberOfSpirals++)
		{
			distaceBetweenElements += 2;
			
			for (int j = 0; j < 4; j++)
			{
				currentElement += distaceBetweenElements;
				
				if (isPrime.at(currentElement))
					countOfPrimes++;
				
				countOfNumbersOnTheDiagonal++;
			}
			if (countOfPrimes * 1.0 / countOfNumbersOnTheDiagonal <= requiredRatio)
				break;
		}
		
		return distaceBetweenElements + 1;
	}
} functions;

int main()
{
	cout << "The required ratio of primes on the diagonal reaches below 10% at the " << functions.checkForRatio(0.1) << "th spiral" << endl;
	
	common.finalize();
	return 0;
}