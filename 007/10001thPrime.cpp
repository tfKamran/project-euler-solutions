#include <iostream>

using namespace std;

int main()
{
  int count = 0;
  long long PrimeNumber = 1;
  
  for (int i = 2; count < 10001; i++)
  {
//     cout << "Loop 1 with i=" << i << " and count=" << count << endl;
    for (int j = 2; j <= i; j++)
    {
//       cout << "Loop 2 with j=" << j << endl;
      if (j == i)
      {
// 	cout << "Found a prime " << i << endl;
	PrimeNumber = i;
	count++;	
      }  
      
      if (i % j == 0)
      {
// 	cout << "Breaking out" << endl;
	break;
      }
    }
  }
  
  cout << "The 10001th prime number is " << PrimeNumber << endl;
  
  return 0;
}