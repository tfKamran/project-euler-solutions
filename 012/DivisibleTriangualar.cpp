#include <iostream>

using namespace std;

int main()
{	
	long long currentTriangle = 0;
	int count = 0;
	
	for (int i = 1; count < 500; i++)
	{
		count = 0;
		
		currentTriangle += i;
		
// 		cout << "Triangle " << currentTriangle << endl;
		
		for (long long j = 1; j <= currentTriangle; j++)
		{
// 			cout << "j " << j << endl;
			if (currentTriangle % j == 0)
				count++;
		}
		
// 		cout << count << endl;
	}
	
	cout << "The first triangle to have over " << count << " divisors is " << currentTriangle << endl;
	
	return 0;
}