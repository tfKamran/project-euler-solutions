#include <iostream>

using namespace std;

static int primeNumbers[2000000];

int main()
{
  primeNumbers[0] = 2;
  primeNumbers[1] = 3;
  int count = 2;
  long long SumOfPrimeNumbers = 0;
  
  
  for (int i = 2; i < 2000000; i++)
  {
//     cout << "Loop 1 with i=" << i << " and count=" << count << endl;
    for (int j = 0; j < i; j++)
    {
//       cout << "Loop 2 with j=" << j << endl;
      if (j == count || i == primeNumbers[j])
      {
// 	cout << "Found a prime " << i << endl;
	primeNumbers[count] = i;
	SumOfPrimeNumbers += i;
	count++;	
      }  
      
      if (i % primeNumbers[j] == 0)
      {
// 	cout << "Breaking out" << endl;
	break;
      }
    }
  }
  
  cout << "The sum of 2 million prime number is " << SumOfPrimeNumbers << endl;
  
  return 0;
}