#include "../common.cpp"

using namespace std;

long long pandigitalsProducts[10000000];

int main()
{
	long long sumOfPandigitals = 0;
	string currentPandigital = "";
	long long currentProduct = 0;
	long long multiplicand;
	long long multiplier;
	
	for (multiplicand = 1; multiplicand < 9999; multiplicand++)
		for (multiplier = 1; multiplier < 999; multiplier++)
		{
			currentProduct = multiplicand * multiplier;
			
			currentPandigital = common.CStr(multiplicand) + common.CStr(multiplier) + common.CStr(currentProduct);
			
			if (common.CInt(currentPandigital) > 987654321)
				break;
			
			if (currentPandigital.length() == 9)
				if (common.stringContains(currentPandigital, "1")
				&& common.stringContains(currentPandigital, "2")
				&& common.stringContains(currentPandigital, "3")
				&& common.stringContains(currentPandigital, "4")
				&& common.stringContains(currentPandigital, "5")
				&& common.stringContains(currentPandigital, "6")
				&& common.stringContains(currentPandigital, "7")
				&& common.stringContains(currentPandigital, "8")
				&& common.stringContains(currentPandigital, "9"))
					pandigitalsProducts[currentProduct] = currentProduct;
		}
	
	for (long long i = 0; i <= 9999999; i++)
		sumOfPandigitals += pandigitalsProducts[i];
	
	cout << "The sum of 1 through 9 pandigital products is " << sumOfPandigitals << endl;
	
	common.finalize();
	
	return 0;
}