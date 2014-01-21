#include "../common.cpp"

using namespace std;

int main()
{
	long long sumOfSelfPowers = 0;
	long long currentCalculatedPower = 0;
	
	for (int number = 1; number <= 1000; number++)
	{
		currentCalculatedPower = common.raiseTo(number, number, 10);
		
		sumOfSelfPowers = sumOfSelfPowers + currentCalculatedPower;
		
		if (sumOfSelfPowers > common.raiseTo(10, 11) - 1)
		{
			string stringSumOfSelfPowers = common.CStr(sumOfSelfPowers);
			sumOfSelfPowers = common.CLong(stringSumOfSelfPowers.substr(stringSumOfSelfPowers.length() - 10, 10));
		}
	}
	
	cout << "The the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000 is " << sumOfSelfPowers << endl;
	
	common.finalize();
	return 0;
}