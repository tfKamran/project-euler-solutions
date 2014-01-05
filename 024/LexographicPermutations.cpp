#include "../common.cpp"

using namespace std;

string CStr(long long inputNumber);

string startingNumber = "0123456789";

int main()
{
	long long permutationNumber = 0;
	
	long long currentNumber;
	for (currentNumber = common.CLong(startingNumber); currentNumber < 9876543210; currentNumber++)
		if (common.stringIndexOf(CStr(currentNumber), "0") > -1
			&& common.stringIndexOf(CStr(currentNumber), "1") > -1
			&& common.stringIndexOf(CStr(currentNumber), "2") > -1
			&& common.stringIndexOf(CStr(currentNumber), "3") > -1
			&& common.stringIndexOf(CStr(currentNumber), "4") > -1
			&& common.stringIndexOf(CStr(currentNumber), "5") > -1
			&& common.stringIndexOf(CStr(currentNumber), "6") > -1
			&& common.stringIndexOf(CStr(currentNumber), "7") > -1
			&& common.stringIndexOf(CStr(currentNumber), "8") > -1
			&& common.stringIndexOf(CStr(currentNumber), "9") > -1)
		{
			permutationNumber++;
			
			if (permutationNumber % 1000 == 0)
				cout << permutationNumber << ": " << currentNumber << endl;
				
			if (permutationNumber == 1000000)
				break;
		}
	
	common.writeToFile("./output.txt", "The millionth permutation of 0123456789 is " + CStr(currentNumber));
	cout << "The millionth permutation of 0123456789 is " << currentNumber << endl;
	
	return 0;
}

string CStr(long long inputNumber)
{
	string returnValue = common.CStr(inputNumber);
	
	while (returnValue.length() < startingNumber.length())
		returnValue = "0" + returnValue;
	
	return returnValue;
}