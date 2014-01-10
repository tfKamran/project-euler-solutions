#include "../common.cpp"
#include "algorithm"

using namespace std;

string padWithZeros(int number);

int main()
{
	vector<string> fourDigitPermutations;
	vector<int> primePermutations;
	vector<int> foundRequiredPrimes;
	
	for (int index = 1000; index < 9999; index++)
	{
		fourDigitPermutations.clear();
		fourDigitPermutations = common.listPermutations(common.CStr(index));
		
		primePermutations.clear();
		for (string& permutation : fourDigitPermutations)
			if (common.isPrime(common.CInt(permutation)))
				primePermutations.push_back(common.CInt(permutation));
		
		for (int& prime : primePermutations)
			if (prime < 1000)
				break;
		primePermutations.push_back(9999);
		
		if (primePermutations.size() > 3)
			for (int& prime1 : primePermutations)
				for (int& prime2 : primePermutations)
					if (prime1 != prime2 && find(primePermutations.begin(), primePermutations.end(), prime2 + prime2 - prime1) != primePermutations.end())
					{
						foundRequiredPrimes.clear();
						foundRequiredPrimes.push_back(prime1);
						foundRequiredPrimes.push_back(prime2);
						foundRequiredPrimes.push_back(prime2 + prime2 - prime1);
					}
	}
	
	cout << "The numbers concatenated makes up a 12 digit number which is " << padWithZeros(foundRequiredPrimes.at(0)) << padWithZeros(foundRequiredPrimes.at(1)) << padWithZeros(foundRequiredPrimes.at(2)) << endl;
	
	common.finalize();
	return 0;
}

string padWithZeros(int number)
{
	string paddedNumber = common.CStr(number);
	while (paddedNumber.length() < 4)
		paddedNumber = "0" + paddedNumber;
	return paddedNumber;
}