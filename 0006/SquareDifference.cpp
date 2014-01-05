#include <iostream>
using namespace std;

int main()
{
  int sum = 0;
  int squareOfSums = 0;
  int sumOfSquares = 0;
  
  for (int i = 1; i <= 100; i++)
  {
    sum += i;
    sumOfSquares += i * i;
  }
  
  squareOfSums = sum * sum;
  
  cout << "The difference of " << squareOfSums << " - " << sumOfSquares << " = " << squareOfSums - sumOfSquares << endl;
  
  return 0;
}