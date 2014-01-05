#include "../common.cpp"

using namespace std;

bool isSumOfFactorialsOfDigitsEqual(long long inputNumber);

int main()
{
	long long sumOfRequiredNumbers = 0;
		
	for (long long number = 10; number < 1000000; number++)
		if (isSumOfFactorialsOfDigitsEqual(number))
			sumOfRequiredNumbers += number;
	
	cout << "The sum of all the numbers which are equal to the sum of the factorial of their digits is " << sumOfRequiredNumbers << endl;
	
	common.finalize();
	return 0;
}

bool isSumOfFactorialsOfDigitsEqual(long long inputNumber)
{
	string inputInString = common.CStr(inputNumber);
	
	long long sumOfFactorials = 0;
	
	for (int digit = 0; digit < inputInString.length(); digit++)
		sumOfFactorials += common.factorial(common.CInt(inputInString.substr(digit, 1)));
		
	if (sumOfFactorials == inputNumber)
		return true;
	
	return false;
}