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
		cout << limit << endl;
		if (common.getNumeratorInString(convergent).length() > common.getDenominatorInString(convergent).length())
		{
			cout << "Found at: " << limit << endl;
			countOfRequiredConvergents++;
		}
	}
	
	cout << "The number of convergents of square root of two which have more number of digits in the numerator are " << countOfRequiredConvergents << endl;
	
	common.finalize();
	return 0;
}