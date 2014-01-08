#include "../common.cpp"

using namespace std;

bool isSubStringDivisible(string number);

int main()
{
	long long sumOfSubStringDivisible = 0;
	
	vector<string> pandigitals = common.listPermutations("0123456789");
	
	for (string& pandigital : pandigitals)
		if (isSubStringDivisible(pandigital))
			sumOfSubStringDivisible += common.CLong(pandigital);
	
	cout << "The sum of all 0 to 9 pandigital numbers with the given property is " << sumOfSubStringDivisible << endl;
	
	common.finalize();
	return 0;
}

bool isSubStringDivisible(string number)
{
	if (common.CInt(number.substr(1, 3)) % 2 != 0)
		return false;
	
	if (common.CInt(number.substr(2, 3)) % 3 != 0)
		return false;
	
	if (common.CInt(number.substr(3, 3)) % 5 != 0)
		return false;
	
	if (common.CInt(number.substr(4, 3)) % 7 != 0)
		return false;
	
	if (common.CInt(number.substr(5, 3)) % 11 != 0)
		return false;
	
	if (common.CInt(number.substr(6, 3)) % 13 != 0)
		return false;
	
	if (common.CInt(number.substr(7, 3)) % 17 != 0)
		return false;
	
	return true;
}