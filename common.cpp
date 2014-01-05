#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

static class Common
{
	public:
		string inputFromFile[10000];
		clock_t startingTime;
	
	public:
		Common();
		void finalize();
		string CStr(long long inputNumber);
		string CDoubleStr(long double inputNumber);
		int CInt(string inputString);
		long long CLong(string inputString);
		int countLinesInFile(string inputFile);
		string* fetchFromFile(string inputFile);
			long long stringIndexOf(string inputString, string partString);
			long long stringLastIndexOf(string inputString, string partString);
			bool stringContains(string inputString, string partString);
			string stringReplace(string inputString, string partString, string newPartString);
			string stringReplaceAll(string inputString, string partString, string newPartString);
		void writeToFile(string inputFile, string fileContent);
		string add(string number1, string number2);
		string subtract(string number1, string number2);
		string multiply(string number1, string number2);
		string divide(string number1, string number2);
		string divide(string number1, string number2, string approxQuotient);
		string divideForDecimalFraction(int number1, int number2);
		long long raiseTo(long long base, int power);
		string raiseToSpecial(string base, int power);
		string toBinary(long long decimalNumber, int digits);
		long long sumOfDigits(string inputNumber);
		long long sumOfDigits(int inputNumber);
		string factorial(string inputNumber);
		long long factorial(long long inputNumber);
		int lookForRepititionLength(string number);
		bool isAllSame(string inputString);
		bool hasRepeatitivePattern(string inputString, int repeatationLength);
		int getNumerator(string fraction);
		int getDenominator(string fraction);
		string reduceFraction(string fraction);
		vector<string> listPermutations(string startingString);
} common;

Common::Common()
{
	startingTime = clock();
}

void Common::finalize()
{
	cout << endl << "Time taken: " << (clock() - startingTime)/1000 << " ms" << endl;
}

string Common::CStr(long long inputNumber)
{
	ostringstream stringStream;
	stringStream << inputNumber;
	return stringStream.str();
}

string Common::CDoubleStr(long double inputNumber)
{
	ostringstream stringStream;
	stringStream << inputNumber;
	return stringStream.str();
}

int Common::CInt(string inputString)
{
	return atoi(inputString.c_str());
}

long long Common::CLong(string inputString)
{
	return atoll(inputString.c_str());
}

int Common::countLinesInFile(string inputFile)
{
	ifstream inputReader (inputFile.c_str());
  
  int numberOfLines = 0;
  string line;
  for (; getline(inputReader, line); numberOfLines++);
 
  inputReader.close();
  return numberOfLines;
}

string* Common::fetchFromFile(string inputFile)
{
  ifstream inputReader (inputFile.c_str());
  
	long long i = 0;
	
	if (countLinesInFile(inputFile) > 1)
	{
		string line;
		for (; getline(inputReader, line); i++)
			inputFromFile[i] = line;
		inputReader.close();
		inputFromFile[i] = '\0';
	}
	else
	{
		string line;
		getline(inputReader, line);
		
		long long indexOfComma = stringIndexOf(line, ",");
		for (; indexOfComma > -1; i++)
		{
			inputFromFile[i] = line.substr(0, indexOfComma);
			line = line.substr(indexOfComma + 1, line.length() - indexOfComma);
			indexOfComma = stringIndexOf(line, ",");
		}
		inputFromFile[i] = line;
		inputFromFile[i + 1] = '\0';
	}
	
	return inputFromFile;
}

	long long Common::stringIndexOf(string inputString, string partString)
	{
		for (long long index = 0; index <= inputString.length() - partString.length(); index++)
			if (inputString.substr(index, partString.length()) == partString)
				return index;
		
		return -1;
	}

	long long Common::stringLastIndexOf(string inputString, string partString)
	{
		for (long long index = inputString.length() - partString.length(); index >= 0; index--)
			if (inputString.substr(index, partString.length()) == partString)
				return index;
		
		return -1;
	}

	bool Common::stringContains(string inputString, string partString)
	{
		for (long long index = 0; index <= inputString.length() - partString.length(); index++)
			if (inputString.substr(index, partString.length()) == partString)
				return true;
		
		return false;
	}
	
	string Common::stringReplace(string inputString, string partString, string newPartString)
	{
		long long locationOfPartString = stringIndexOf(inputString, partString);
		inputString = inputString.substr(0, locationOfPartString) + newPartString + inputString.substr(locationOfPartString + partString.length(), inputString.length() - locationOfPartString - partString.length());
		
		return inputString;
	}
	
	string Common::stringReplaceAll(string inputString, string partString, string newPartString)
	{
		long long locationOfPartString = 0;
		while (stringContains(inputString, partString))
		{
			locationOfPartString = stringIndexOf(inputString, partString);
			inputString = inputString.substr(0, locationOfPartString) + newPartString + inputString.substr(locationOfPartString + partString.length(), inputString.length() - locationOfPartString - partString.length());
		}
		
		return inputString;
	}

void Common::writeToFile(string inputFile, string fileContent)
{
	ofstream outputWriter (inputFile.c_str());
	outputWriter << fileContent;
	outputWriter.close();
}

string Common::add(string number1, string number2)
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

string Common::subtract(string number1, string number2)
{
	if (number1 == "")
		number1 = "0";
	if (number2 == "")
		number2 = "0";
	
	if (number1 == "0")
		return "-" + number2;
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
	
	int borrow = 0;
	int difference;
	for (int i = lengthOfFirst - 1; i >= 0; i--)
	{
		difference = CInt(number1.substr(i, 1)) - CInt(number2.substr(i, 1)) - borrow;
		if (difference < 0)
		{
			difference = 10 + CInt(number1.substr(i, 1)) - CInt(number2.substr(i, 1)) - borrow;
			borrow = 1;
		}
		returnValue = CStr(difference).substr(CStr(difference).length() - 1, 1) + returnValue;
	}
	
	while (returnValue.substr(0, 1) == "0")
		returnValue = returnValue.substr(1, returnValue.length() - 1);
	
	return returnValue;
}

string Common::multiply(string number1, string number2)
{
	string returnValue = "";
	int lengthOfFirst = number1.length();
	int lengthOfSecond = number2.length();
	
// 	if (lengthOfFirst < lengthOfSecond)
// 	{
// 		string swapString = number1;
// 		number1 = number2;
// 		number2 = swapString;
// 		
// 		int swapInt = lengthOfFirst;
// 		lengthOfFirst = lengthOfSecond;
// 		lengthOfSecond = swapInt;
// 	}
	
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
		carry = 0;
		
		for (int i = 0; i < lengthOfSecond - 1 - j; i++)
			productString = productString + "0";
		
		returnValue = add(productString, returnValue);
		productString = "";
	}
	
	while (returnValue.substr(0, 1) == "0")
		returnValue = returnValue.substr(1, returnValue.length() - 1);
	
	return returnValue;
}

string Common::divide(string number1, string number2)
{
	return divide(number1, number2, "1");
}

string Common::divide(string number1, string number2, string approxQuotient)
{
	string returnValue;
	
	for (returnValue = approxQuotient; multiply(number2, returnValue) != number1; returnValue = add(returnValue, "1"));
	
	return returnValue;
}

string Common::divideForDecimalFraction(int number1, int number2)
{
	string decimalFraction = "0.";
	
	for (long long i = 0; i < 10000; i++)
	{
		decimalFraction = decimalFraction + CStr((number1 * 10) / number2);
		number1 = (number1 * 10) % number2;
		
		if (i > 10 && isAllSame(decimalFraction.substr(decimalFraction.length() - 10, 10)))
			break;
	}
	
	return decimalFraction;
}

long long Common::raiseTo(long long base, int power)
{
	long long returnValue = base;
	
	for (; power > 1; power--)
		returnValue *= base;
	
	return returnValue;
}

string Common::raiseToSpecial(string base, int power)
{
	string returnValue = base;
	
	for (;power > 1; power--)
		returnValue = multiply(returnValue, base);
	
	return returnValue;
}

string Common::toBinary(long long decimalNumber, int digits)
{	
	long long highestDegree = raiseTo(2, digits) / 2;
	string binary = "";
	
	for (; highestDegree >= 1; highestDegree /= 2)
	{
		if (decimalNumber >= highestDegree)
		{
			decimalNumber -= highestDegree;
			binary += "1";
		}
		else
		{
			binary += "0";
		}
	}
	
	return binary;
}

long long Common::sumOfDigits(string inputNumber)
{
	ostringstream stringStream;
	stringStream << inputNumber;
	string digits = stringStream.str();
	
	long long returnValue = 0;
	
	for (int i = 0; i < digits.length(); i++)
		returnValue += atoi(digits.substr(i, 1).c_str());
	
	return returnValue;
}

long long Common::sumOfDigits(int inputNumber)
{
	return sumOfDigits(CStr(inputNumber));
}

string Common::factorial(string inputNumber)
{
	if (inputNumber != "1")
		return common.multiply(factorial(common.subtract(inputNumber, "1")), inputNumber);
	else
		return "1";
}

long long Common::factorial(long long inputNumber)
{
	if (inputNumber > 1)
		return factorial(inputNumber - 1) * inputNumber;
	else
		return 1;
}

int Common::lookForRepititionLength(string inputString)
{
	for (long long startingIndex = 2; startingIndex < inputString.length() - 1; startingIndex++)
		for (long long returnValue = 1; returnValue <= (inputString.length() - startingIndex); returnValue++)
		{
			if (hasRepeatitivePattern(inputString.substr(startingIndex, inputString.length() - startingIndex), returnValue) && ! isAllSame(inputString.substr(startingIndex, returnValue)))
				return returnValue;
		}
		
	return 0;
}

bool Common::isAllSame(string inputString)
{
	string firstCharacter = inputString.substr(0, 1);
	bool returnValue = true;
	
	for (long long i = 0; i < inputString.length(); i++)
		returnValue = returnValue && (inputString.substr(i, 1) == firstCharacter);
	
	return returnValue;
}

bool Common::hasRepeatitivePattern(string inputString, int repeatationLength)
{
	inputString = inputString.substr(0, (inputString.length() / repeatationLength) * repeatationLength);
	string pattern = inputString.substr(0, repeatationLength);
	bool returnValue = true;
	long long i;
	
	for (i = repeatationLength; i < inputString.length() - repeatationLength; i += repeatationLength)
	{
		returnValue = returnValue && (inputString.substr(i, repeatationLength) == pattern);
		
		if (!returnValue)
			break;
	}
	
	if (i > repeatationLength)
		return returnValue;
	else
		return false;
}

int Common::getNumerator(string fraction)
{
	return common.CInt(fraction.substr(0, common.stringIndexOf(fraction, "/")));
}

int Common::getDenominator(string fraction)
{
	return common.CInt(fraction.substr(common.stringIndexOf(fraction, "/") + 1, fraction.length() - common.stringIndexOf(fraction, "/")));
}

string Common::reduceFraction(string fraction)
{
	for (int i = getNumerator(fraction); i > 1; i--)
		if (getNumerator(fraction) % i == 0 && getDenominator(fraction) % i == 0)
			return common.CStr(getNumerator(fraction) / i)
			+ "/"
			+ common.CStr(getDenominator(fraction) / i);
		
	return fraction;
}

vector<string> Common::listPermutations(string startingString)
{
	vector<string> list;
	
	if (startingString.length() == 1)
		list.push_back(startingString);
	else
		for (int currentCharacterIndex = 0; currentCharacterIndex < startingString.length(); currentCharacterIndex++)
		{
			string firstCharacter = startingString.substr(currentCharacterIndex, 1);
			string remaingCharacters = stringReplace(startingString, firstCharacter, "");
			vector<string> subList = listPermutations(remaingCharacters);
			
			for (int i = 0; i < subList.size(); ++i)
				list.push_back(firstCharacter + subList.at(i));
		}
	
	return list;
}