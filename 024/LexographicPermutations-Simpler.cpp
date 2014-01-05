#include "../common.cpp"

using namespace std;

string CStr(long long inputNumber);

string startingNumber = "0123456789";

int main()
{
	vector<string> permutations = common.listPermutations("0123456789");
	
	cout << "The millionth permutation of 0123456789 is " << permutations.at(999999) << endl;
	
	common.finalize();
	return 0;
}