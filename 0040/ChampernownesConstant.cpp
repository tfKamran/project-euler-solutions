#include "../common.cpp"

using namespace std;

int main()
{
	string concatenatedNumbers = "";
	
	for (long long positiveInteger = 1; concatenatedNumbers.length() < 1000001; positiveInteger++)
		concatenatedNumbers = concatenatedNumbers + common.CStr(positiveInteger);
	
	cout << "The required number is obtained by multiplying ";
	int requiredNumber = 1;
	for (long long index = 1; index <= 1000000; index *= 10)
	{
		cout << common.CInt(concatenatedNumbers.substr(index - 1, 1)) << ", ";
		requiredNumber *= common.CInt(concatenatedNumbers.substr(index - 1, 1));
	}
	
	 cout << " which yeilds " << requiredNumber << endl;
	
	common.finalize();
	return 0;
}