#include "../common.cpp"
#define LIMIT 1000000

using namespace std;

bool addToTheListIfCircularPrime(long long number);

long long circularPrimes[LIMIT];
long long count = 0;

int main()
{
	for (long long number = 2; number < LIMIT; number++)
		if (addToTheListIfCircularPrime(number));
		
	for (long long i = 0; i < LIMIT; i++)
		if (circularPrimes[i] > 0 && count++ && cout << count << ": " << i << endl);
		
	cout << "There are " << count << " circular primes under 1000000" << endl;
	
	common.finalize();
	return 0;
}

bool addToTheListIfCircularPrime(long long number)
{
	if (!common.isPrime(number))
		return false;
	
	vector<string> rotations = common.listRotations(common.CStr(number));
	
	for (int i = 0; i < rotations.size(); i++)
		if (! common.isPrime(common.CLong(rotations.at(i))))
			return false;
	
	for (int i = 0; i < rotations.size(); i++)
		circularPrimes[common.CLong(rotations.at(i))] = common.CLong(rotations.at(i));
		
	return true;
}