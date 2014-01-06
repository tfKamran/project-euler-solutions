#include "../common.cpp"

using namespace std;

int main()
{
	long long sumOfDoubleBasePalindromes = 0;
	
	for (long long number = 0; number < 1000000; number++)
		if (common.isPalindromic(number) && common.isPalindromic(common.toBinary(number)) && cout << number << ": " << common.toBinary(number) << endl)
			sumOfDoubleBasePalindromes += number;
		
	cout << "The sum of double base palindromes is " << sumOfDoubleBasePalindromes << endl;
	
	common.finalize();
	return 0;
}