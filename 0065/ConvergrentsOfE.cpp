#include "../common.cpp"
#define LIMIT 100 - 2

using namespace std;

void generateECoEfficientsTill(int limit);

vector<long long> eCoEfficients;

int main()
{
	generateECoEfficientsTill(LIMIT);
	
	string e = "1/1";
	
	for (int convergence = LIMIT - 1; convergence >= 0; convergence--)
		e = common.addFractionsInString(common.CStr(eCoEfficients.at(convergence)) + "/1",
			common.divideFractionsInString("1/1", e)
		);
	
	e = common.addFractionsInString("2/1", common.divideFractionsInString("1/1", e));
	
	cout << "The required numerator is " << common.getNumeratorInString(e) << " and the sum of its digits is " << common.sumOfDigits(common.getNumeratorInString(e)) << endl;
	
	common.finalize();
	return 0;
}

void generateECoEfficientsTill(int limit)
{
	eCoEfficients.push_back(1);
	
	long long currentCoEfficient = 2;
	
	for (; eCoEfficients.size() < limit; currentCoEfficient += 2)
	{
		eCoEfficients.push_back(currentCoEfficient);
		eCoEfficients.push_back(1);
		eCoEfficients.push_back(1);
	}
}