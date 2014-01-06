#include "../common.cpp"

using namespace std;

int main()
{
	long long numberOfWays = 1;
	
	for (int onePound = 0; onePound <= 2; onePound++)
		for (int fiftyPence = 0; fiftyPence <= 4; fiftyPence++)
			for (int twentyPence = 0; twentyPence <= 10; twentyPence++)
				for (int tenPence = 0; tenPence <= 20; tenPence++)
					for (int fivePence = 0; fivePence <= 40; fivePence++)
						for (int twoPence = 0; twoPence <= 100; twoPence++)
							for (int onePence = 0; onePence <= 200; onePence++)
								if (onePence * 1 + twoPence * 2 + fivePence * 5 + tenPence * 10 + twentyPence * 20 + fiftyPence * 50 + onePound * 100 == 200)
									numberOfWays++;
	
		cout << "There are " << numberOfWays << " to make up two Pounds using the available coins" << endl;
		
	return 0;
}