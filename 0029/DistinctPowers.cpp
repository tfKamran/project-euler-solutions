#include "../common.cpp"

using namespace std;

bool existsInStack(string number);
void addToStack(string number);

static string distinctTerms[1000000];
long long termPointer = 0;

int main()
{
	string currentTerm = "";
	
	for (int a = 2; a <= 100; a++)
		for (int b = 2; b <= 100; b++)
			addToStack(common.raiseToSpecial(common.CStr(a), b));
	
	cout << "The number of distinct terms is " << termPointer << endl;
	
	return 0;
}

bool existsInStack(string number)
{
	for (long long i = 0; i < termPointer; i++)
		if (distinctTerms[i] == number)
			return true;
		
	return false;
}

void addToStack(string number)
{
	if (! existsInStack(number))
	{
		distinctTerms[termPointer] = number;
		termPointer++;
	}
}