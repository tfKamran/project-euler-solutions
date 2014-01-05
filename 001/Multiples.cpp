#include <iostream>
#define NUMBER1 3
#define NUMBER2 5

using namespace std;

static int Multiples[1000];

int main()
{
  int multiple = 0;
  
  int i = 1;
  while (multiple < 1000)
  {
    multiple = NUMBER1 * i;
    
    if (multiple < 1000)
      Multiples[multiple] = multiple;
  
    i++;
  }
   
  i = 1;
  multiple = 0;
  while (multiple < 1000)
  {
    multiple = NUMBER2 * i;
    
    if (multiple < 1000)
      Multiples[multiple] = multiple;
  
    i++;
  }
  
  int sum = 0;
  for (i = 0; i < 1000; i++)
  {
    sum +=Multiples[i];
  }
  
  cout << sum;
  
  return 0;
}