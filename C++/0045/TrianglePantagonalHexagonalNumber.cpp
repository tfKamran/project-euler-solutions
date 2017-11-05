#include "../common.cpp"
#include "algorithm"
#define LIMIT 1600000000

using namespace std;

void generateTrianlePentagonalHexagonalNumbers();

vector<long long> triangleNumbers;
vector<long long> pentagonalNumbers;
vector<long long> hexagonalNumbers;

int main()
{
	generateTrianlePentagonalHexagonalNumbers();
	long long trianglePentagonalHexagonalNumber = 0;
	
	for (long long index = 2; index < triangleNumbers.size(); index++)
		if (find(pentagonalNumbers.begin(), pentagonalNumbers.end(), triangleNumbers.at(index)) != pentagonalNumbers.end()
			&& find(hexagonalNumbers.begin(), hexagonalNumbers.end(), triangleNumbers.at(index)) != hexagonalNumbers.end())
			trianglePentagonalHexagonalNumber = triangleNumbers.at(index);
	
	cout << "The next triangle number that is also pentagonal and hexagonal after 40755 is " << trianglePentagonalHexagonalNumber << endl;
	
	common.finalize();
	return 0;
}

void generateTrianlePentagonalHexagonalNumbers()
{
	long long triangleNumber = 1;
	long long pentagonalNumber = 1;
	long long hexagonalNumber = 1;
	
	for (long long index = 0; triangleNumber < LIMIT; index++)
	{
		triangleNumbers.push_back(triangleNumber);
		triangleNumber = (index * (index + 1))/2;
// 		cout << triangleNumber << ", ";
	}
	
	for (long long index = 0; pentagonalNumber < LIMIT; index++)
	{
		pentagonalNumbers.push_back(pentagonalNumber);
		pentagonalNumber = (index * ((3 * index) - 1))/2;
// 		cout << pentagonalNumber << ", ";
	}
	
	for (long long index = 0; hexagonalNumber < LIMIT; index++)
	{
		hexagonalNumbers.push_back(hexagonalNumber);
		hexagonalNumber = (index * ((2 * index) - 1));
// 		cout << hexagonalNumber << ", ";
	}
}