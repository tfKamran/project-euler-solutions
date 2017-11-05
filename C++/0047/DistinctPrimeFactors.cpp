#include "../common.cpp"

using namespace std;

bool hasFourDistinctPrimeFactors(long long number);

int main()
{
	long long number;
	for (number = 3; ; number++)
		if (hasFourDistinctPrimeFactors(number) && hasFourDistinctPrimeFactors(number + 1) && hasFourDistinctPrimeFactors(number + 2) && hasFourDistinctPrimeFactors(number + 3))
			break;
	
	cout << "The first four consecutive integers to have four distinct prime factors starts from " << number << endl;
	
	common.finalize();
	return 0;
}

bool hasFourDistinctPrimeFactors(long long number)
{
	vector<long long> primeFactors;
	
	long long numberOne = number;
	while (numberOne > 1)
	{
		for (long long divisor = 2; divisor <= numberOne; divisor++)
			if (numberOne % divisor == 0)
			{
				numberOne /= divisor;
				primeFactors.push_back(divisor);
				break;
			}
	}
	
	if (primeFactors.size() < 4)
		return false;
	
	int count = primeFactors.size();
	bool repeats;
	for (int index1 = 0; index1 < primeFactors.size(); index1++)
	{
		repeats = false;
		for (int index2 = index1 + 1; index2 < primeFactors.size(); index2++)
			if (primeFactors.at(index1) == primeFactors.at(index2))
				repeats = true;
		if (repeats)
			count--;
	}
	if (count < 4)
		return false;
	
	return true;
}