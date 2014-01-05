#include "../common.cpp"

#define INPUTNUMBER "100"

using namespace std;

int main()
{
	string factorialValue = common.factorial(INPUTNUMBER);

	cout << "The sum of the digits if factorial of " << INPUTNUMBER << ", which is " << factorialValue << " is " << common.sumOfDigits(factorialValue) << endl;
	
	return 0;
}