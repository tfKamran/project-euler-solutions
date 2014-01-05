#include "../common.cpp"

using namespace std;

string nextFibonacciNumber();

static string swapVariable;
static string nMinusOne = "1";
static string currentFibonacci;
static long long termNumber;

int main()
{
	while (nextFibonacciNumber().length() < 1000);
	
	cout << "The first term in Fibonacci sequence with a thousand digits is " << termNumber << endl;
	
	common.finalize();
	return 0;
}

string nextFibonacciNumber()
{
	swapVariable = currentFibonacci;
	currentFibonacci = common.add(nMinusOne, currentFibonacci);
	nMinusOne = swapVariable;
	termNumber++;
	
	return currentFibonacci;
}