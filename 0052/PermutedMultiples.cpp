#include "../common.cpp"

using namespace std;

int main()
{
	long long number;
	string numberInString;
	vector<string> permutations;
	
	for (number = 1; number < 1000000; number++)
	{
		numberInString = common.CStr(number);
		permutations.clear();
		permutations = common.listPermutations(numberInString);
		permutations.push_back("-");
		
		if (find(permutations.begin(), permutations.end(), numberInString) != permutations.end()
			&& find(permutations.begin(), permutations.end(), common.CStr(2 * number)) != permutations.end()
			&& find(permutations.begin(), permutations.end(), common.CStr(3 * number)) != permutations.end()
			&& find(permutations.begin(), permutations.end(), common.CStr(4 * number)) != permutations.end()
			&& find(permutations.begin(), permutations.end(), common.CStr(5 * number)) != permutations.end()
			&& find(permutations.begin(), permutations.end(), common.CStr(6 * number)) != permutations.end())
			break;
	}
	
	cout << "The number with 6 permuted multiples is " << number << endl;
	
	common.finalize();
	return 0;
}