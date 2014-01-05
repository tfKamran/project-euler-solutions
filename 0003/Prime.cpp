#include <iostream>

using namespace std;

class FactorCalculator
{
  public: long long findFactors(long long inputNumber);
} factorCalculator;

long long FactorCalculator::findFactors(long long inputNumber)
{
  for (long long factor = 2; factor < inputNumber; factor++)
  {
    if (inputNumber % factor == 0)
    {
      cout << "factor: " << factor << "\t\t quotient: " << inputNumber/factor << endl;
      return findFactors(inputNumber/factor);
    }
  }
  
  return inputNumber;
}

int main()
{
  FactorCalculator factorCalculator;
  long long largestPrimeNumber = factorCalculator.findFactors(600851475143);
  
  cout << "The largest prime factor is: " << largestPrimeNumber << endl;
  
  return 0;
}