#include "../common.cpp"
#define LIMIT 100

using namespace std;

void generateECoEfficientsTill(int limit);

vector<long long> eCoEfficients;

int main()
{
	generateECoEfficientsTill(LIMIT);
	
	string e = common.getConvergentsOf("1/1", eCoEfficients, "2/1", LIMIT);
	
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