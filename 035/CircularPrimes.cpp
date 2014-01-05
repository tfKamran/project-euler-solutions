#include "../common.cpp"

using namespace std;

int main()
{
	vector<string> permutation = common.listPermutations("012");
	
	for (int i = 0; i < permutation.size(); ++i)
		cout << permutation.at(i) << endl;
	
	common.finalize();
	return 0;
}

