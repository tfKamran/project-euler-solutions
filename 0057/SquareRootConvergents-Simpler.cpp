#include "../common.cpp"

using namespace std;

int main()
{
	string convergent;
	int countOfRequiredConvergents = 0;
	
	convergent = common.addFractions("1/1", "1/2");
	cout << convergent << endl;
	for (int index = 0; index < 1000; index++)
	{
		convergent = common.addFractionsInString("1/1", convergent);
		convergent = common.divideFractionsInString("1/1", convergent);
		convergent = common.addFractionsInString("1/1", convergent);
		
		if (common.getNumeratorInString(convergent).length() > common.getDenominatorInString(convergent).length())
			countOfRequiredConvergents++;
	}
	
	cout << "The number of convergents of square root of two which have more number of digits in the numerator are " << countOfRequiredConvergents << endl;
	
	common.finalize();
	return 0;
}