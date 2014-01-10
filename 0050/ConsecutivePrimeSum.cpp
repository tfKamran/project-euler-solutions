#include "../common.cpp"
#define LIMIT 1000000

using namespace std;

int main()
{
	vector<long long> primeNumbers;
	long long sumOfPrimes = 0;
	long long countOfAddedPrimes = 0;
	long long maxCount = 0;
	long long sumAtTheMaxCount = 0;
	
	for (long long number = 2; number < LIMIT; number++)
		if (common.isPrime(number))
		{
// 			cout << number << endl;
			primeNumbers.push_back(number);
		}
	
	cout << "Calculated all the prime numbers under " << LIMIT << ", now looking for the consecutive sums..." << endl;
	
	for (long long index1 = 0; index1 < primeNumbers.size(); index1++)
	{
		for (long long index2 = index1; index2 < primeNumbers.size(); index2++)
		{
			sumOfPrimes += primeNumbers.at(index2);
			countOfAddedPrimes++;
			if (countOfAddedPrimes > 1 && sumOfPrimes < LIMIT && common.isPrime(sumOfPrimes) && countOfAddedPrimes > maxCount)
			{
				maxCount = countOfAddedPrimes;
				sumAtTheMaxCount = sumOfPrimes;
			}
			else if (sumOfPrimes > LIMIT)
			{
				countOfAddedPrimes = 0;
				sumOfPrimes = 0;
				break;
			}
		}
		sumOfPrimes = 0;
		countOfAddedPrimes = 0;
	}
	
	cout << maxCount << " prime numbers added up together forms " << sumAtTheMaxCount << endl;
	
	common.finalize();
	return 0;
}