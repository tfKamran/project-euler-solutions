#include <iostream>
using namespace std;

bool isDivisibleByAll(int inputNumber);

int main()
{
  int smallestMultiple = 1;

  for (; !isDivisibleByAll(smallestMultiple); smallestMultiple++);

  cout << "The smallest multiple of 1 to 10 is " << smallestMultiple << endl;
    
  return 0;
}

bool isDivisibleByAll(int inputNumber)
{
  bool returnValue = true;
  
  for (int i = 2; i <= 20; i++)
    returnValue = returnValue && (inputNumber % i == 0);
  
  return returnValue;
}