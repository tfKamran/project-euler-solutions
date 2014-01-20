#include "../common.cpp"

using namespace std;

long long getTheNumberOfPossiblePrimeFromEquation(long long a, long long b);
bool isPrime(long long number);

static long long coefficientA[100000];
static long long coefficientB[100000];

int main()
{
	long long numberOfPrimes = 0;
	for (int a = -999; a < 1000; a++)
		for (int b = -999; b < 1000; b++)
		{
			numberOfPrimes = getTheNumberOfPossiblePrimeFromEquation(a, b);
			coefficientA[numberOfPrimes] = a;
			coefficientB[numberOfPrimes] = b;
		}
	
	long long i;
	for (i = 99999; i > 0; i--)
		if (coefficientA[i] != 0)
			break;
	
	cout << "With a = " << coefficientA[i] << " and b = " << coefficientB[i] << " the Eulers equation yeids " << i << " prime numbers. The product of these coeefficients is " << coefficientA[i] * coefficientB[i] << endl;
	
	common.finalize();
	return 0;
}

long long getTheNumberOfPossiblePrimeFromEquation(long long a, long long b)
{
	long long n;
	
	for (n = 0; isPrime((n*n) + (a*n) + b); n++);
	
	return n;
}

bool isPrime(long long number)
{
	if (number < 0)
		return false;
	
	for (long long i = 2; i <= (number/2) + 1; i++)
		if (number % i == 0) 
			return false;
	
	return true;
}