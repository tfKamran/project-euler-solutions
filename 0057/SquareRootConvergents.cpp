#include "../common.cpp"

using namespace std;

int main()
{
	vector<long long> coEfficients(1000, 2);
	string convergent;
	int countOfRequiredConvergents = 0;
	
	for (int limit = 9; limit < 1000; limit++)
	{
		convergent = common.getConvergentsOf("2/1", coEfficients, "1/1", limit);
		
		if (common.CStr(common.getNumerator(convergent)).length() > common.CStr(common.getDenominator(convergent)).length())
			countOfRequiredConvergents++;
	}
	
	cout << "The number of convergents of square root of two which have more number of digits in the numerator are " << countOfRequiredConvergents << endl;
	
	common.finalize();
	return 0;
}