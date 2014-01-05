#include "../common.cpp"

using namespace std;

long long addDivisors(int inputNumber);

static long long setOfDivisors[10000];

int main()
{
	long long sumOfAmicables = 0;
	
	for (int i = 1; i < 10000; i++)
		setOfDivisors[i] = addDivisors(i);
	
	for (int i = 1; i < 10000; i++)
		if (addDivisors(setOfDivisors[i]) == i && setOfDivisors[i] != i)
		{
			sumOfAmicables += i;// + setOfDivisors[i];
			cout << i << "\t\t : \t\t" << setOfDivisors[i] << endl;
		}
		
	cout << "The sum of all amicable numbers are " << sumOfAmicables << endl;
	
	return 0;
}

long long addDivisors(int inputNumber)
{
	long long sumOfDivisors = 1;
	
	for (int i = 2; i < inputNumber; i++)
		if (inputNumber % i == 0)
			sumOfDivisors += i;
	
	return sumOfDivisors;
}