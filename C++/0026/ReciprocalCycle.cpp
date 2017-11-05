#include "../common.cpp"

using namespace std;

int numberOfRepitions[10000];

int main()
{
	string currentDecimalFraction = "";
	string listOfResults = "";
	for (int number = 1; number < 1000; number++)
	{
// 		cout << "Current number: " << number << endl;
		currentDecimalFraction = common.divideForDecimalFraction(1, number);
		listOfResults = listOfResults + currentDecimalFraction + "\n";
		numberOfRepitions[common.lookForRepititionLength(currentDecimalFraction)] = number;
	}
	
	common.writeToFile("./listOfResults", listOfResults);
	
	for (long long i = 9999; i >= 0; i--)
		if (numberOfRepitions[i] != 0)
		{
			common.writeToFile("./output.txt", "The number 1/" + common.CStr(numberOfRepitions[i]) + " has " + common.CStr(i) + " digits of recurring cycle in it's decimal fraction");
			cout << "The number 1/" << numberOfRepitions[i] << " has " << i << " digits of recurring cycle in it's decimal fraction" << endl;
			break;
		}
	
	return 0;
}