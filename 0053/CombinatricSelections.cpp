#include "../common.cpp"

using namespace std;

int main()
{
	long long numberOfValuesAboveAMillion = 0;
	
	for (int n = 1; n <= 100; n++)
	{
		for (int r = 1; r < n; r++)
			if (common.factorial(common.CStr(n)).length() - common.multiply(common.factorial(common.CStr(r)), common.factorial(common.subtract(common.CStr(n), common.CStr(r)))).length() > 6)
				numberOfValuesAboveAMillion++;
		cout << "Reached " << n << ": " << endl;
	}
	
	cout << "The number of values greater than a million is " << numberOfValuesAboveAMillion << endl;
	
	common.finalize();
	return 0;
}