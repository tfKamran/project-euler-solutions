#include "../common.cpp"

using namespace std;

int getChampernownesConstant(long long digit);

int main()
{
// 	cout << "The 12th digit is " << getChampernownesConstant(12) << endl;
	
	cout << "The required number is obtained by multiplying ";
	int requiredNumber = 1;
	for (long long index = 1; index <= 1000000; index *= 10)
	{
		int champernownesConstant = getChampernownesConstant(index);
		cout << champernownesConstant << ", ";
		requiredNumber *= champernownesConstant;
	}
	
	 cout << " which yeilds " << requiredNumber << endl;
	
	common.finalize();
	return 0;
}

int getChampernownesConstant(long long digit)
{
	long long number = 1;
	long long digitsUptoNumber = 0;
	
	while (digitsUptoNumber < digit)
	{
		number *= 10;
		digitsUptoNumber += (common.CStr(number).length() - 1) * (number * 9) /10;
	}
	
	while (digitsUptoNumber >= digit)
	{
		number--;
		digitsUptoNumber -= common.CStr(number).length();
	}
	
	return common.CInt(common.CStr(number).substr(digit - digitsUptoNumber - 1, 1));
}