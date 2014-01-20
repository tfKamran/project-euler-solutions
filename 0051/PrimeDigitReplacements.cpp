#include "../common.cpp"
#include "algorithm"

using namespace std;

long long checkIfContainsSpecifiedNumberOfPrimeNumbers(string number, int numberOfPrimes);

vector<string> binaryCombinations;

int main()
{
	string currentNumber = "0";
	int numberOfDigits = 1;
	long long result;
	
	for (long long number = 121310; number < 10000000; number++)
	{
		currentNumber = common.CStr(number);
		if (currentNumber.length() != numberOfDigits)
		{
			binaryCombinations.clear();
			numberOfDigits = currentNumber.length();
			long long limit = common.raiseTo(2, numberOfDigits);
			for (long long index = 1; index < limit; index++)
				binaryCombinations.push_back(common.toBinary(index, numberOfDigits));
		}
		
		result = checkIfContainsSpecifiedNumberOfPrimeNumbers(currentNumber, 8);
		if (result > 0)
			break;
	}
	
	cout << "The first of the sequence is " << result << endl;
	
	common.finalize();
	return 0;
}

long long checkIfContainsSpecifiedNumberOfPrimeNumbers(string number, int numberOfPrimes)
{
	vector<long long> primeNumbers;
	int countOfPrimes = 0;
	string currentNumber;
	string currentBinary;
	int numberOfDigits = number.length();
	
	for (string& binaryCombination : binaryCombinations)
	{
		primeNumbers.clear();
		primeNumbers.push_back(0);
		
		for (int replacementNumber = 0; replacementNumber < 10; replacementNumber++)
		{
			currentNumber = number;
			currentBinary = binaryCombination;
			while (common.stringContains(currentBinary, "1"))
			{
				int index = common.stringIndexOf(currentBinary, "1");
				currentBinary = common.stringReplaceAt(currentBinary, index, "-");
				currentNumber = common.stringReplaceAt(currentNumber, index, common.CStr(replacementNumber));
			}
			
			long long numberInLong = common.CLong(currentNumber);
			if (common.isPrime(numberInLong) && numberInLong != primeNumbers.at(primeNumbers.size() - 1) && find(primeNumbers.begin(), primeNumbers.end(), numberInLong) == primeNumbers.end() && common.CStr(numberInLong).length() == numberOfDigits)
			{
				primeNumbers.push_back(common.CLong(currentNumber));
				countOfPrimes++;
			}
		}
		
		if (primeNumbers.size() - 1 == numberOfPrimes)
		{
			for (long long& primeNumber : primeNumbers)
				cout << primeNumber << ", ";
			cout << endl;
			break;
		}
		else
		{
			primeNumbers.clear();
			primeNumbers.push_back(0);
		}
	}
	
	if (primeNumbers.size() > 1)
		return primeNumbers.at(1);
	
	return 0;
}