#include "../common.cpp"

using namespace std;

int main()
{
	long long compositeNumber;
	bool represented = false;
	
	for (compositeNumber = 4; ; compositeNumber++)
	{
		represented = false;
		if (compositeNumber % 2 != 0 && !common.isPrime(compositeNumber))
		{
			for (long long prime = 3; prime < compositeNumber - 1; prime++)
			{
				if (common.isPrime(prime))
				{
					for (long long number = 1; number < prime; number++)
						if (compositeNumber == prime + (2 * number * number))
						{
							represented = true;
							break;
						}
					if (represented) break;
				}
			}
			if (! represented) break;
		}
	}
	
	cout << "The smallest odd composite that cannot be written as the sum of a prime and twice a square is " << compositeNumber << endl;
	
	common.finalize();
	return 0;
}