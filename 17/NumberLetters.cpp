#include "../common.cpp"

using namespace std;

string convertToWords(int number);
string convertUnitsToWords(int number);
string convertTensToWords(int number);
int countTheLetters(string inputString);

int main()
{
	int countOfWords = 0;
	
	for (int i = 1; i <= 999; i++)
	{
		cout << convertToWords(i) << endl;
		countOfWords += countTheLetters(convertToWords(i));
	}
	
	countOfWords += countTheLetters("OneThousand");
	
	cout << "The number of letters used to write numbers 0 to 1000 in words is " << countOfWords << endl;
	
	return 0;
}

string convertUnitsToWords(int number)
{
	switch(number)
	{
		case 1:
			return "One";
			break;
		case 2:
			return "Two";
			break;
		case 3:
			return "Three";
			break;
		case 4:
			return "Four";
			break;
		case 5:
			return "Five";
			break;
		case 6:
			return "Six";
			break;
		case 7:
			return "Seven";
			break;
		case 8:
			return "Eight";
			break;
		case 9:
			return "Nine";
			break;
	}
	
	return "";
}

string convertTensToWords(int number)
{
	string numberInString = CStr(number);
	while (numberInString.length() < 2)
		numberInString = "0" + numberInString;
	
	int unitsPlace = CInt(numberInString.substr(1, 1));
	
	switch(number)
	{
		case 10:
			return "Ten";
			break;
		case 11:
			return "Eleven";
			break;
		case 12:
			return "Twelve";
			break;
		case 13:
			return "Thirteen";
			break;
		case 14:
			return "Fourteen";
			break;
		case 15:
			return "Fifteen";
			break;
		case 16:
			return "Sixteen";
			break;
		case 17:
			return "Seventeen";
			break;
		case 18:
			return "Eighteen";
			break;
		case 19:
			return "Nineteen";
			break;
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
			return "Twenty" + convertUnitsToWords(unitsPlace);
			break;
		case 30:
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37:
		case 38:
		case 39:
			return "Thirty" + convertUnitsToWords(unitsPlace);
			break;
		case 40:
		case 41:
		case 42:
		case 43:
		case 44:
		case 45:
		case 46:
		case 47:
		case 48:
		case 49:
			return "Forty" + convertUnitsToWords(unitsPlace);
			break;
		case 50:
		case 51:
		case 52:
		case 53:
		case 54:
		case 55:
		case 56:
		case 57:
		case 58:
		case 59:
			return "Fifty" + convertUnitsToWords(unitsPlace);
			break;
		case 60:
		case 61:
		case 62:
		case 63:
		case 64:
		case 65:
		case 66:
		case 67:
		case 68:
		case 69:
			return "Sixty" + convertUnitsToWords(unitsPlace);
			break;
		case 70:
		case 71:
		case 72:
		case 73:
		case 74:
		case 75:
		case 76:
		case 77:
		case 78:
		case 79:
			return "Seventy" + convertUnitsToWords(unitsPlace);
			break;
		case 80:
		case 81:
		case 82:
		case 83:
		case 84:
		case 85:
		case 86:
		case 87:
		case 88:
		case 89:
			return "Eighty" + convertUnitsToWords(unitsPlace);
			break;
		case 90:
		case 91:
		case 92:
		case 93:
		case 94:
		case 95:
		case 96:
		case 97:
		case 98:
		case 99:
			return "Ninety" + convertUnitsToWords(unitsPlace);
			break;
		default:
			return convertUnitsToWords(unitsPlace);
	}
	
	return "";
}

string convertToWords(int number)
{
	string numberInString = CStr(number);
	string returnValue = "";
	
	while (numberInString.length() < 3)
		numberInString = "0" + numberInString;
	
	if (CInt(numberInString.substr(0, 1)) > 0)
		returnValue = convertUnitsToWords(CInt(numberInString.substr(0, 1))) + "Hundred";
	
	if (CInt(numberInString.substr(1, 2)) > 0)
	{
		if (returnValue != "")
			returnValue = returnValue + "And";
		returnValue = returnValue + convertTensToWords(CInt(numberInString.substr(1, 2)));
	}
	
	return returnValue;
}

int countTheLetters(string inputString)
{
	return inputString.length();
}