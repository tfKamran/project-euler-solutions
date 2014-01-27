#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

static class Common
{
public:
	clock_t startingTime;
	vector<string> memoiozedStringDivisionsFractions;
	vector<string> memoiozedStringDivisionsQuotients;
	vector<string> memoiozedStringFactorials;
	string inputFromFile[10000];
	
public:
	Common()
	{
		startingTime = clock()/1000;
		
		memoiozedStringDivisionsFractions.push_back("null");
		memoiozedStringDivisionsQuotients.push_back("null");
	}

	void finalize()
	{
		cout << endl << "Time taken: " << (clock()/1000) - startingTime << " ms" << endl;
	}

	string CStr(long long inputNumber)
	{
		ostringstream stringStream;
		stringStream << inputNumber;
		return stringStream.str();
	}

	string CDoubleStr(long double inputNumber)
	{
		ostringstream stringStream;
		stringStream << inputNumber;
		return stringStream.str();
	}

	int CInt(string inputString)
	{
		return atoi(inputString.c_str());
	}

	long long CLong(string inputString)
	{
		return atoll(inputString.c_str());
	}

	int countLinesInFile(string inputFile)
	{
		ifstream inputReader (inputFile.c_str());
		
		int numberOfLines = 0;
		string line;
		for (; getline(inputReader, line); numberOfLines++);
	
		inputReader.close();
		return numberOfLines;
	}

	string* fetchFromFile(string inputFile)
	{
		vector<string> linesFromFile = readFromFile(inputFile);
		
		for (long long lineNumber = 0; lineNumber < linesFromFile.size(); lineNumber++)
			inputFromFile[lineNumber] = linesFromFile.at(lineNumber);
		
		inputFromFile[linesFromFile.size()] = "\0";
		
		return inputFromFile;
	}

	vector<string> readFromFile(string inputFile)
	{
		ifstream inputReader (inputFile.c_str());
		
		long long i = 0;
		vector<string> linesFromFile;
		
		if (countLinesInFile(inputFile) > 1)
		{
			string line;
			for (; getline(inputReader, line); i++)
				linesFromFile.push_back(line);
			inputReader.close();
		}
		else
		{
			string line;
			getline(inputReader, line);
			
			long long indexOfComma = stringIndexOf(line, ",");
			for (; indexOfComma > -1; i++)
			{
				linesFromFile.push_back(line.substr(0, indexOfComma));
				line = line.substr(indexOfComma + 1, line.length() - indexOfComma);
				indexOfComma = stringIndexOf(line, ",");
			}
			linesFromFile.push_back(line);
		}
		
		return linesFromFile;
	}

		long long stringIndexOf(string inputString, string partString)
		{
			if (inputString.length() < partString.length())
				return -1;
				
			for (long long index = 0; index <= inputString.length() - partString.length(); index++)
				if (inputString.substr(index, partString.length()) == partString)
					return index;
			
			return -1;
		}

		long long stringLastIndexOf(string inputString, string partString)
		{
			if (inputString.length() < partString.length())
				return -1;
			
			for (long long index = inputString.length() - partString.length(); index >= 0; index--)
				if (inputString.substr(index, partString.length()) == partString)
					return index;
			
			return -1;
		}

		bool stringContains(string inputString, string partString)
		{
			if (inputString.length() < partString.length())
				return false;
			
			for (long long index = 0; index <= inputString.length() - partString.length(); index++)
				if (inputString.substr(index, partString.length()) == partString)
					return true;
			
			return false;
		}
		
		string stringReplace(string inputString, string partString, string newPartString)
		{
			long long locationOfPartString = stringIndexOf(inputString, partString);
			inputString = inputString.substr(0, locationOfPartString) + newPartString + inputString.substr(locationOfPartString + partString.length(), inputString.length() - locationOfPartString - partString.length());
			
			return inputString;
		}
		
		string stringReplaceAll(string inputString, string partString, string newPartString)
		{
			long long locationOfPartString = 0;
			while (stringContains(inputString, partString))
			{
				locationOfPartString = stringIndexOf(inputString, partString);
				inputString = inputString.substr(0, locationOfPartString) + newPartString + inputString.substr(locationOfPartString + partString.length(), inputString.length() - locationOfPartString - partString.length());
			}
			
			return inputString;
		}
		
		string stringReplaceAt(string inputString, long long position, string newContent)
		{
			inputString = inputString.substr(0, position) + newContent + inputString.substr(position + newContent.length(), inputString.length() - position - newContent.length());
			
			return inputString;
		}

	void writeToFile(string inputFile, string fileContent)
	{
		ofstream outputWriter (inputFile.c_str());
		outputWriter << fileContent;
		outputWriter.close();
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

	string subtract(string number1, string number2)
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

	string divide(string number1, string number2)
	{
		vector<string>::iterator indexOfMemory = find(memoiozedStringDivisionsFractions.begin(), memoiozedStringDivisionsFractions.end(), number1 + "/" + number2);
		if (indexOfMemory != memoiozedStringDivisionsFractions.end())
			return memoiozedStringDivisionsQuotients.at(distance(memoiozedStringDivisionsFractions.begin(), indexOfMemory));
		
		if (number1.length() < 19)
			return CStr(CLong(number1) / CLong(number2));
		
		long long partDivisor;
		string approxQuotient;
		if (number2.length() < 19)
			partDivisor = CLong(number2);
		else
			partDivisor = CLong(number2.substr(0, 18));
		
		approxQuotient = CStr(CLong(number1.substr(0, 18)) / partDivisor);
		while (number1.length() > approxQuotient.length() + number2.length() - 1)
			approxQuotient = approxQuotient + "0";
		
		while (compareNumbersInString(number1, approxQuotient) < 0)
			approxQuotient = approxQuotient.substr(0, approxQuotient.length() - 1);
		
		string returnValue = divide(number1, number2, approxQuotient);
		
		memoiozedStringDivisionsFractions.insert(memoiozedStringDivisionsFractions.begin(), number1 + "/" + number2);
		memoiozedStringDivisionsQuotients.insert(memoiozedStringDivisionsQuotients.begin(), returnValue);
		
		return returnValue;
	}

	string divide(string number1, string number2, string approxQuotient)
	{
		string returnValue;
		returnValue = approxQuotient;
		int comparisonResult;
		
		while (true)
		{
			comparisonResult = compareNumbersInString(multiply(number2, returnValue), number1);
			
			if (comparisonResult == 0)
					return returnValue;
			else if (comparisonResult < 0)
					returnValue = add(returnValue, "1");
			else if (comparisonResult > 0)
					returnValue = subtract(returnValue, "1");
		}
		
		return returnValue;
	}

		int compareNumbersInString(string number1, string number2)
		{
			int returnValue = 0;
			
			if (number1.length() > number2.length())
				returnValue = 1;
			else if (number1.length() < number2.length())
				returnValue = -1;
			else
			{
				for (int index = 0; index < number1.length(); index++)
					if (CLong(number1.substr(index, 1)) > CLong(number2.substr(index, 1)))
					{
						returnValue = 1;
						break;
					}
					else if (CLong(number1.substr(index, 1)) < CLong(number2.substr(index, 1)))
					{
						returnValue = -1;
						break;
					}
			}
			
			return returnValue;
		}

	string divideForDecimalFraction(int number1, int number2)
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

	long long raiseTo(long long base, int power)
	{
		long long returnValue = base;
		
		for (; power > 1; power--)
			returnValue *= base;
		
		return returnValue;
	}

	long long raiseTo(int base, int power, int numberOfLastDigits)
	{
		long long returnValue = base;
		
		for (;power > 1; power--)
		{
			returnValue = returnValue * base;
			
			if (returnValue > raiseTo(10, numberOfLastDigits + 1) - 1)
			{
				string stringReturnValue = CStr(returnValue);
				returnValue = CLong(stringReturnValue.substr(stringReturnValue.length() - numberOfLastDigits, numberOfLastDigits));
			}
		}
		
		return returnValue;
	}

	string raiseToSpecial(string base, int power)
	{
		string returnValue = base;
		
		for (;power > 1; power--)
			returnValue = multiply(returnValue, base);
		
		return returnValue;
	}

	string toBinary(long long decimalNumber, int digits)
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

	string toBinary(long long decimalNumber)
	{
		long long digits = 0;
		for (; raiseTo(2, digits) <= decimalNumber; digits++);
		return toBinary(decimalNumber, digits);
	}

	long long sumOfDigits(string inputNumber)
	{
		ostringstream stringStream;
		stringStream << inputNumber;
		string digits = stringStream.str();
		
		long long returnValue = 0;
		
		for (int i = 0; i < digits.length(); i++)
			returnValue += atoi(digits.substr(i, 1).c_str());
		
		return returnValue;
	}

	long long sumOfDigits(int inputNumber)
	{
		return sumOfDigits(CStr(inputNumber));
	}

	string factorial(string inputNumber)
	{
		if (inputNumber == "0")
			return "1";
		
		if (inputNumber.length() < 19 && memoiozedStringFactorials.size() > CLong(inputNumber))
			return memoiozedStringFactorials.at(CLong(inputNumber) - 1);
		else
		{
			if (inputNumber != "1")
				return multiply(factorial(subtract(inputNumber, "1")), inputNumber);
			else
				return "1";
		}
	}

	vector<string> memoizeFactorialsUpto(long long limit)
	{
		string currentFactorial = "1";
		
		for (long long index = 1; index <= limit; index++)
		{
			currentFactorial = multiply(currentFactorial, CStr(index));
			memoiozedStringFactorials.push_back(currentFactorial);
		}
		
		return memoiozedStringFactorials;
	}

	long long factorial(long long inputNumber)
	{
		if (inputNumber > 1)
			return factorial(inputNumber - 1) * inputNumber;
		else
			return 1;
	}

	int lookForRepititionLength(string inputString)
	{
		for (long long startingIndex = 2; startingIndex < inputString.length() - 1; startingIndex++)
			for (long long returnValue = 1; returnValue <= (inputString.length() - startingIndex); returnValue++)
			{
				if (hasRepeatitivePattern(inputString.substr(startingIndex, inputString.length() - startingIndex), returnValue) && ! isAllSame(inputString.substr(startingIndex, returnValue)))
					return returnValue;
			}
			
		return 0;
	}

	bool isAllSame(string inputString)
	{
		string firstCharacter = inputString.substr(0, 1);
		bool returnValue = true;
		
		for (long long i = 0; i < inputString.length(); i++)
			returnValue = returnValue && (inputString.substr(i, 1) == firstCharacter);
		
		return returnValue;
	}

	bool hasRepeatitivePattern(string inputString, int repeatationLength)
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

	long long getNumerator(string fraction)
	{
		return CLong(fraction.substr(0, stringIndexOf(fraction, "/")));
	}

	long long getDenominator(string fraction)
	{
		return CLong(fraction.substr(stringIndexOf(fraction, "/") + 1, fraction.length() - stringIndexOf(fraction, "/")));
	}

	string getNumeratorInString(string fraction)
	{
		return (fraction.substr(0, stringIndexOf(fraction, "/")));
	}

	string getDenominatorInString(string fraction)
	{
		return (fraction.substr(stringIndexOf(fraction, "/") + 1, fraction.length() - stringIndexOf(fraction, "/")));
	}

	string reduceFraction(string fraction)
	{
		long long numerator = getNumerator(fraction);
		long long denominator = getDenominator(fraction);
		
		if (numerator == 0)
			return "0/1";
		
		if (denominator == numerator)
			return "1/1";
		else if (denominator < numerator && isPrime(denominator))
			if (numerator % denominator == 0)
				return CStr(numerator / denominator) + "/1";
		else if (denominator > numerator && isPrime(numerator))
			if (denominator % numerator == 0)
				return "1/" + CStr(denominator / numerator);
		else
			for (long long i = denominator; i > 1; i--)
				if (numerator % i == 0 && denominator % i == 0)
					return CStr(numerator / i)
					+ "/"
					+ CStr(denominator / i);
			
		return fraction;
	}

	string addFractions(string fraction1, string fraction2)
	{
		return CStr((getNumerator(fraction1) * getDenominator(fraction2)) + (getNumerator(fraction2) * getDenominator(fraction1)))
		+ "/"
		+ CStr(getDenominator(fraction1) * getDenominator(fraction2));
	}

	string subtractFractions(string fraction1, string fraction2)
	{
		return CStr((getNumerator(fraction1) * getDenominator(fraction2)) - (getNumerator(fraction2) * getDenominator(fraction1)))
		+ "/"
		+ CStr(getDenominator(fraction1) * getDenominator(fraction2));
	}

	string multiplyFractions(string fraction1, string fraction2)
	{
		return CStr(getNumerator(fraction1) * getNumerator(fraction2))
		+ "/"
		+ CStr(getDenominator(fraction1) * getDenominator(fraction2));
	}

	string divideFractions(string fraction1, string fraction2)
	{
		return multiplyFractions(fraction1, CStr(getDenominator(fraction2)) + "/" + CStr(getNumerator(fraction2)));
	}

	string addFractionsInString(string fraction1, string fraction2)
	{ 
		return add(multiply(getNumeratorInString(fraction1), getDenominatorInString(fraction2)), multiply(getNumeratorInString(fraction2), getDenominatorInString(fraction1)))
		+ "/"
		+ multiply(getDenominatorInString(fraction1), getDenominatorInString(fraction2));
	}

	string subtractFractionsInString(string fraction1, string fraction2)
	{
		return subtract(multiply(getNumeratorInString(fraction1), getDenominatorInString(fraction2)), multiply(getNumeratorInString(fraction2), getDenominatorInString(fraction1)))
		+ "/"
		+ multiply(getDenominatorInString(fraction1), getDenominatorInString(fraction2));
	}

	string multiplyFractionsInString(string fraction1, string fraction2)
	{
		return multiply(getNumeratorInString(fraction1), getNumeratorInString(fraction2))
		+ "/"
		+ multiply(getDenominatorInString(fraction1), getDenominatorInString(fraction2));
	}

	string divideFractionsInString(string fraction1, string fraction2)
	{
		return multiplyFractionsInString(fraction1, getDenominatorInString(fraction2) + "/" + getNumeratorInString(fraction2));
	}

	vector<string> listPermutations(string startingString)
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

	vector<string> listRotations(string startingString)
	{
		vector<string> list;
		string rotatedString = startingString;
		
		if (startingString.length() == 1)
			list.push_back(startingString);
		else
		{
			rotatedString = rotatedString.substr(1, rotatedString.length() - 1) + rotatedString.substr(0, 1);
			list.push_back(rotatedString);
			while (rotatedString != startingString)
			{
				rotatedString = rotatedString.substr(1, rotatedString.length() - 1) + rotatedString.substr(0, 1);
				list.push_back(rotatedString);
			}
		}
		
		return list;
	}

	bool isPrime(long long inputNumber)
	{
		if (inputNumber < 2)
			return false;
		
		for (long long i = 2; i <= inputNumber/2; i++)
			if (inputNumber % i == 0)
				return false;
		
		return true;
	}

	bool isPalindromic(string inputNumber)
	{
		long long firstDigit = 0;
		long long lastDigit = inputNumber.length() - 1;
		
		for (; lastDigit > firstDigit; firstDigit++, lastDigit--)
			if (inputNumber.substr(firstDigit, 1) != inputNumber.substr(lastDigit, 1))
				return false;
				
		return true;
	}

	bool isPalindromic(long long inputNumber)
	{
		return isPalindromic(CStr(inputNumber));
	}

	bool isPandigital(string inputString, string requiredCharacters)
	{
		if (inputString.length() != requiredCharacters.length())
			return false;
		
		for (long long character = 0; character < requiredCharacters.length(); character++)
			inputString =  stringReplace(inputString, requiredCharacters.substr(character, 1), "");
		
		if (inputString.length() == 0)
			return true;
		
		return false;
	}

	long long combination(long long n, long long r)
	{
		return factorial(n) /
			(factorial(r) * factorial(n - r));
	}

	string combination(string n, string r)
	{
		return divide(factorial(n),
			(multiply(factorial(r), factorial(subtract(n, r)))));
	}
} common;