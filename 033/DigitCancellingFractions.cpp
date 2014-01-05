#include "../common.cpp"

using namespace std;

float divide(int number1, int number2);
bool isTheRequiredType(string fraction);

int main()
{
	int count  = 0;
	int productOfNumerators = 1;
	int productOfDenominators = 1;
	
	for (int numerator = 11; numerator < 100; numerator++)
		for (int denominator = 11; denominator < 100; denominator++)
		{
			string fraction = common.CStr(numerator) + "/" + common.CStr(denominator);
			
			if (isTheRequiredType(fraction))
			{
				count++;
				cout << count << ": " << common.reduceFraction(fraction) << endl;
				productOfNumerators *= common.getNumerator(common.reduceFraction(fraction));
				productOfDenominators *= common.getDenominator(common.reduceFraction(fraction));
			}
		}
	
	cout << "The product of the denominators is " << common.reduceFraction(common.CStr(productOfNumerators) + "/" + common.CStr(productOfDenominators)) << endl;
	
	common.finalize();
	return 0;
}

bool isTheRequiredType(string fraction)
{
	string numerator = common.CStr(common.getNumerator(fraction));
	string denominator = common.CStr(common.getDenominator(fraction));
	
	if (common.getNumerator(fraction) >= common.getDenominator(fraction))
		return false;
	
	if ((common.getNumerator(fraction) % 10 == 0) && (common.getDenominator(fraction) % 10 == 0))
		return false;
	
	for (int i = 0; i < numerator.length(); i++)
		if (common.stringContains(denominator, numerator.substr(i, 1)))
		{
			denominator = common.stringReplace(denominator, numerator.substr(i, 1), "");
			numerator = common.stringReplace(numerator, numerator.substr(i, 1), "");
			
			if (divide(common.CInt(numerator), common.CInt(denominator)) == divide(common.getNumerator(common.reduceFraction(fraction)), common.getDenominator(common.reduceFraction(fraction))))
				return true;
		}
	
	return false;
}

float divide(int number1, int number2)
{
	return (number1 * 1.0)/number2;
}