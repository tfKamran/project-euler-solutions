#include "../common.cpp"

using namespace std;

bool pandigitalPrimes[1000000000];

int main()
{
	for (string startingNumber = "123456789"; startingNumber.length() > 1; startingNumber = startingNumber.substr(0, startingNumber.length() - 1))
	{
		vector<string> pandigitals = common.listPermutations(startingNumber);
		for (string& pandigital : pandigitals)
			if (common.isPrime(common.CLong(pandigital)))
				pandigitalPrimes[common.CLong(pandigital)] = true;
	}
	
	long long largestPandigitalPrime;
	for (largestPandigitalPrime = 999999999; !pandigitalPrimes[largestPandigitalPrime] ; largestPandigitalPrime--);
	cout << "The largest prime pandigital number is " << largestPandigitalPrime << endl;
	
	common.finalize();
	return 0;
}