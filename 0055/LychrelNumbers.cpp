#include "../common.cpp"

using namespace std;

class functions
{
	string reverseAndAdd(string inputNumber)
	{
		return common.add(inputNumber, common.stringReverse(inputNumber));
	}
	
public:
	bool isLychrel(long long number)
	{
		string iterationOfTheGivenNumber = common.CStr(number);
		
		for (int limit = 0; limit < 50; limit++)
		{
			iterationOfTheGivenNumber = reverseAndAdd(iterationOfTheGivenNumber);
			if (common.isPalindromic(iterationOfTheGivenNumber))
				return false;
		}
		
		return true;
	}
} functions;

int main()
{
	long long numberOfLychrelNumbers = 0;
	
	for (long long number = 10; number < 10000; number++)
		if (functions.isLychrel(number))
			numberOfLychrelNumbers++;
	
	cout << "The number of Lychrel numbers under 10000 are " << numberOfLychrelNumbers << endl;
	
	common.finalize();
	return 0;
}