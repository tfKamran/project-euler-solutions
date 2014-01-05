#include <iostream>

using namespace std;

bool isPalindrome(int product);
static int Palindromes[1000000];

int main()
{
  int firstMultiple = 0;
  int secondMultiple = 0;
  
//   cout << "started" << endl;
  
  for (firstMultiple = 1; firstMultiple < 1000; firstMultiple++)
  {
//     cout << "first loop" << endl;
    for (secondMultiple = 1; secondMultiple < 1000; secondMultiple++)
    {
//       cout << "second loop" << endl;
//       cout << firstMultiple << " & " << secondMultiple << endl;
      if (isPalindrome(firstMultiple * secondMultiple))
      {
	Palindromes[firstMultiple * secondMultiple] = firstMultiple * secondMultiple;
      }
//       cout << "not palindrome" << endl;
    }
  }

  for (int i = 1000000; i > 1; i--)
  {
    if (Palindromes[i] != 0)
    {
      cout << "The largest palindrome is " << i << endl;//", a product of " << firstMultiple << " and " << secondMultiple << endl;
      break;
    }
  }
  
//   cout << firstMultiple << " & " << secondMultiple;
  
  return 0;
}

bool isPalindrome(int product)
{
//   cout << "checking " << product << endl;
  
  int units = 0;
  int tens = 0;
  int hundreds = 0;
  int thousands = 0;
  int tenthousands = 0;
  int hundredthousands = 0;
  
  hundredthousands = product/100000;
  tenthousands = (product - hundredthousands*100000)/10000;
  thousands = (product - tenthousands*10000 - hundredthousands*100000)/1000;
  hundreds = (product - thousands*1000 - tenthousands*10000 - hundredthousands*100000)/100;
  tens = (product - hundreds*100 - thousands*1000 - tenthousands*10000 - hundredthousands*100000)/10;
  units = product - tens*10 - hundreds*100 - thousands*1000 - tenthousands*10000 - hundredthousands*100000;

//   cout << "separated" << endl;
  
  int mirrorProduct = units * 100000 +
    tens * 10000 +
    hundreds * 1000 +
    thousands * 100 +
    tenthousands * 10 +
    hundredthousands;
    
//   cout << "joined" << endl;
    
  while (mirrorProduct % 10 == 0)
    mirrorProduct /= 10;
  
//   cout << "removed padding" << endl;
  
  if (product == mirrorProduct)
    return true;
  else
    return false;
}