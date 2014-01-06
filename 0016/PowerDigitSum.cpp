#include "../common.cpp"

// #define theNumber 15;

using namespace std;

string add(string number1, string number2);
string multiply(string number1, string number2);
string raiseTo(string base, int power);
long long sumOfDigits(string inputNumber);

int main()
{
	int theNumber = 1000;
	
	cout << "The sum of the digits of 2 to the power of " << theNumber << " is " << sumOfDigits(raiseTo("2", theNumber)) << endl;
	
	return 0;
}

string add(string number1, string number2)
{
	if (number1 == "")
		number1 = "0";
	if (number2 == "")
		number2 = "0";
	
	if (number1 == "0")
		return number2;
	if (number2 == "0")
		return number1;
	
	string returnValue = "";
	int lengthOfFirst = number1.length();
	int lengthOfSecond = number2.length();
	
	while (lengthOfFirst > lengthOfSecond)
	{
		number2 = "0" + number2;
		lengthOfSecond = number2.length();
	}
	while (lengthOfFirst < lengthOfSecond)
	{
		number1 = "0" + number1;
		lengthOfFirst = number1.length();
	}
	
	int carry = 0;
	int sum;
	for (int i = lengthOfFirst - 1; i >= 0; i--)
	{
		sum = CInt(number1.substr(i, 1)) + CInt(number2.substr(i, 1)) + carry;
		returnValue = CStr(sum).substr(CStr(sum).length() - 1, 1) + returnValue;
		sum -= CInt(CStr(sum).substr(CStr(sum).length() - 1, 1));
		carry = sum/10;
	}
	returnValue = CStr(carry) + returnValue;
	
	while (returnValue.substr(0, 1) == "0")
		returnValue = returnValue.substr(1, returnValue.length() - 1);
	
	return returnValue;
}

string multiply(string number1, string number2)
{
	string returnValue = "";
	int lengthOfFirst = number1.length();
	int lengthOfSecond = number2.length();
	
	int carry = 0;
	int product;
	string productString = "";
	for (int j = lengthOfSecond - 1; j > -1; j--)
	{
		for (int i = lengthOfFirst - 1; i > -1; i--)
		{
			product = (CInt(number1.substr(i, 1)) * CInt(number2.substr(j, 1))) + carry;
			productString = CStr(product).substr(CStr(product).length() - 1, 1) + productString;
			product -= CInt(CStr(product).substr(CStr(product).length() - 1, 1));
			carry = product/10;
		}
		productString = CStr(carry) + productString;
		
		for (int i = 0; i < lengthOfSecond - 1 - j; i++)
			productString = productString + "0";
		
		returnValue = add(productString, returnValue);
	}
	
	while (returnValue.substr(0, 1) == "0")
		returnValue = returnValue.substr(1, returnValue.length() - 1);
	
	return returnValue;
}

string raiseTo(string base, int power)
{
	string returnValue = base;
	
	for (;power > 1; power--)
		returnValue = multiply(returnValue, base);
	
	cout << returnValue << endl;
	
	return returnValue;
}

long long sumOfDigits(string inputNumber)
{
	ostringstream stringStream;
	stringStream << inputNumber;
	string digits = stringStream.str();
	
	long long returnValue = 0;
	
	for (int i = 0; i < digits.length(); i++)
	{
		cout << "+" << atoi(digits.substr(i, 1).c_str()) << endl;
		returnValue += atoi(digits.substr(i, 1).c_str());
	}
	
	return returnValue;
}