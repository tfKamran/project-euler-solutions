#include "../common.cpp"
#define POWER 5

using namespace std;

int main()
{
	long long sumOfNumbers = 0;
	long long sumOfDigits = 0;
	
	for (long long number = 11; number < 200000; number++)
	{
		sumOfDigits = 0;
		for (int digit = 0; digit < common.CStr(number).length(); digit++)
			sumOfDigits += common.raiseTo(common.CInt(common.CStr(number).substr(digit, 1)), POWER);
		
		if (sumOfDigits == number)
		{
			cout << "Adding " << number << endl;
			sumOfNumbers += number;
		}
	}
	
	cout << "The sum of numbers that can be written as the sum of " << POWER << "th powers of their digits is " << sumOfNumbers << endl;
	
	common.finalize();
	return 0;
}