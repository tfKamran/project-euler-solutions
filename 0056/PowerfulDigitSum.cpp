#include "../common.cpp"

using namespace std;

bool sumOfDigits[1000];

int main()
{
	for (int a = 11; a < 100; a++)
	{
		if (a % 10 == 0)
			a++;
		for (int b = 2; b < 100; b++)
			sumOfDigits[common.sumOfDigits(common.raiseToString(a, b))] = true;
	}
	
	long long index = 999;
	for (; ! sumOfDigits[index]; index--);
	
	cout << "The maximum sum of digits is " << index << endl;
	
	common.finalize();
	return 0;
}