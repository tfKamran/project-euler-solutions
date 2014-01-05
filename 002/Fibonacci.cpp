#include <iostream>

using namespace std;

static long fibonacciSeries[1000];

int main()
{
  fibonacciSeries[0] = 1;
  fibonacciSeries[1] = 2;
  
  long nextNumber = 0;
  for (int i = 1; nextNumber < 4000000; i++)
  {
    nextNumber = fibonacciSeries[i] + fibonacciSeries[i - 1];
    if (nextNumber < 4000000)
      fibonacciSeries[i + 1] = nextNumber;
  }
  
  long sum = 0;
  for (int i = 0; i < 1000; i++)
    if (fibonacciSeries[i] % 2 == 0)
      sum += fibonacciSeries[i];
  
  cout << sum;
  
  return 0;
}