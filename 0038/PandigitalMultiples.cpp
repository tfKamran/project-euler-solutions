#include "../common.cpp"

using namespace std;

bool pandigitals[1000000000];

int main()
{
	string concatanatedMultiples = "";
	
	for (long long number = 1; number < 99999; number++)
	{
		concatanatedMultiples = "";
		for (long long multiples = 1; concatanatedMultiples.length() < 10; multiples++)
		{
			concatanatedMultiples = concatanatedMultiples + common.CStr(number * multiples);
			
			if (concatanatedMultiples.length() == 9 && common.isPandigital(concatanatedMultiples, "123456789"))
				pandigitals[common.CLong(concatanatedMultiples)] = true;
		}
	}
	
	long long largestPandigital;
	for (largestPandigital = 999999999; !pandigitals[largestPandigital]; largestPandigital--);
	
	cout << "The largest 1 to 9 pandigital that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1 is " << largestPandigital << endl; 
	
	common.finalize();
	return 0;
}