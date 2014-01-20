#include "../common.cpp"

using namespace std;

void decodeTheReadNumbers();
void encodeBackToEfficentRomanNumber();

vector<string> readNumbers;
vector<long long> decimalNumbers;
vector<string> compiledRomanNumbers;

int main()
{
	long long numberOfCharactersSaved = 0;
	
// 	readNumbers = common.readFromFile("./testInput.txt");
	readNumbers = common.readFromFile("./roman.txt");
	for (string& number : readNumbers)
		numberOfCharactersSaved += number.length();
	
	decodeTheReadNumbers();
	encodeBackToEfficentRomanNumber();
	
	for (string& number : compiledRomanNumbers)
		numberOfCharactersSaved -= number.length();
	
	cout << "The total number of characters used is " << numberOfCharactersSaved << endl;
	
	common.finalize();
	return 0;
}

void decodeTheReadNumbers()
{
	long long currentNumber;
	string currentCharacter;
	
	for (string& number : readNumbers)
	{
		currentNumber = 0;
		
		while (common.stringContains(number, "CM"))
		{
			currentNumber += 900;
			number = common.stringReplace(number, "CM", "");
		}
		while (common.stringContains(number, "M"))
		{
			currentNumber += 1000;
			number = common.stringReplace(number, "M", "");
		}
		while (common.stringContains(number, "CD"))
		{
			currentNumber += 400;
			number = common.stringReplace(number, "CD", "");
		}
		while (common.stringContains(number, "D"))
		{
			currentNumber += 500;
			number = common.stringReplace(number, "D", "");
		}
		while (common.stringContains(number, "XC"))
		{
			currentNumber += 90;
			number = common.stringReplace(number, "XC", "");
		}
		while (common.stringContains(number, "C"))
		{
			currentNumber += 100;
			number = common.stringReplace(number, "C", "");
		}
		while (common.stringContains(number, "XL"))
		{
			currentNumber += 40;
			number = common.stringReplace(number, "XL", "");
		}
		while (common.stringContains(number, "L"))
		{
			currentNumber += 50;
			number = common.stringReplace(number, "L", "");
		}
		while (common.stringContains(number, "IX"))
		{
			currentNumber += 9;
			number = common.stringReplace(number, "IX", "");
		}
		while (common.stringContains(number, "X"))
		{
			currentNumber += 10;
			number = common.stringReplace(number, "X", "");
		}
		while (common.stringContains(number, "IV"))
		{
			currentNumber += 4;
			number = common.stringReplace(number, "IV", "");
		}
		while (common.stringContains(number, "V"))
		{
			currentNumber += 5;
			number = common.stringReplace(number, "V", "");
		}
		while (common.stringContains(number, "I"))
		{
			currentNumber += 1;
			number = common.stringReplace(number, "I", "");
		}
		
// 		for (int index = 0; index < number.length(); index++)
// 		{
// 			currentCharacter = number.substr(index, 1);
// 			if (currentCharacter == "I")
// 				currentNumber += 1;
// 			else if (currentCharacter == "V")
// 				currentNumber += 5;
// 			else if (currentCharacter == "X")
// 				currentNumber += 10;
// 			else if (currentCharacter == "L")
// 				currentNumber += 50;
// 			else if (currentCharacter == "C")
// 				currentNumber += 100;
// 			else if (currentCharacter == "D")
// 				currentNumber += 500;
// 			else if (currentCharacter == "M")
// 				currentNumber += 1000;
// 		}
		
		decimalNumbers.push_back(currentNumber);
	}
}

void encodeBackToEfficentRomanNumber()
{
	string currentNumber;
	long long currentDecimalNumber;
	for (long long& number : decimalNumbers)
	{
		currentNumber = "";
		currentDecimalNumber = number;
		
		while (number >= 1000)
		{
			currentNumber = currentNumber + "M";
			number -= 1000;
		}
		while (number >= 900) // was if
		{
			currentNumber = currentNumber + "CM";
			number -= 900;
		}
		while (number >= 500)
		{
			currentNumber = currentNumber + "D";
			number -= 500;
		}
		while (number >= 400) // was if
		{
			currentNumber = currentNumber + "CD";
			number -= 400;
		}
		while (number >= 100)
		{
			currentNumber = currentNumber + "C";
			number -= 100;
		}
		while (number >= 90) // was if
		{
			currentNumber = currentNumber + "XC";
			number -= 90;
		}
		while (number >= 50)
		{
			currentNumber = currentNumber + "L";
			number -= 50;
		}
		while (number >= 40) // was if
		{
			currentNumber = currentNumber + "XL";
			number -= 40;
		}
		while (number >= 10)
		{
			currentNumber = currentNumber + "X";
			number -= 10;
		}
		while (number >= 9) // was if
		{
			currentNumber = currentNumber + "IX";
			number -= 9;
		}
		while (number >= 5)
		{
			currentNumber = currentNumber + "V";
			number -= 5;
		}
		while (number >= 4) // was if
		{
			currentNumber = currentNumber + "IV";
			number -= 4;
		}
		while (number >= 1)
		{
			currentNumber = currentNumber + "I";
			number -= 1;
		}
		
		compiledRomanNumbers.push_back(currentNumber);
		cout << currentDecimalNumber << ": " << currentNumber << endl;
	}
}