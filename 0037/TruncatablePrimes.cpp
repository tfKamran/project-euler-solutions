#include "../common.cpp"

using namespace std;

bool isTruncatablePrime(long long number);
vector<string> listTruncationsFromBothSides(string inputString);

int main()
{
	long long sumOfTruncatablePrimes = 0;
	int count = 0;
	
	for (long long number = 10; count < 11; number++)
		if (isTruncatablePrime(number))
		{
			count++;
			cout << count << ": " << number << endl;
			sumOfTruncatablePrimes += number;
		}
		
	cout << "The sum of all  are truncatable primes is " << sumOfTruncatablePrimes << endl;
	
	common.finalize();
	return 0;
}

bool isTruncatablePrime(long long number)
{
	if (!common.isPrime(number))
		return false;
	
	vector<string> truncated = listTruncationsFromBothSides(common.CStr(number));
	
	for (int i = 0; i < truncated.size(); i++)
		if (! common.isPrime(common.CLong(truncated.at(i))))
			return false;

	return true;
}

vector<string> listTruncationsFromBothSides(string inputString)
{
	vector<string> list;
	
	for (long long index = 0; index < inputString.length(); index++)
		list.push_back(inputString.substr(index, inputString.length() - index));
	
	for (long long index = inputString.length(); index > 0; index--)
		list.push_back(inputString.substr(0, index));
	
	return list;
}