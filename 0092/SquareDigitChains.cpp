#include "../common.cpp"

using namespace std;

long long addSquareOfDigits(long long number);
long long squareOf(int number);

int main()
{
	long long currentNumber;
	long long numberOfNumbersEndingAtEightyNine = 0;
	for (long long number = 2; number < 10000000; number++)
	{
		currentNumber = addSquareOfDigits(number);
		
		while (true)
		{
			if (currentNumber == 89 || currentNumber == 1)
				break;
			currentNumber = addSquareOfDigits(currentNumber);
		}
		
		if (currentNumber == 89)
			numberOfNumbersEndingAtEightyNine++;
	}
	
	cout << "The number of numbers ending at 89 below ten million are " << numberOfNumbersEndingAtEightyNine << endl;
	
	common.finalize();
	return 0;
}

long long addSquareOfDigits(long long number)
{
	long long squareOfDigits = 0;
	string numberInString = common.CStr(number);
	
	for (int index = 0; index < numberInString.length(); index++)
		squareOfDigits += squareOf(common.CInt(numberInString.substr(index, 1)));
	
	return squareOfDigits;
}

long long squareOf(int number)
{
	return number * number;
}