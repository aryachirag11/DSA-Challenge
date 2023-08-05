#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkPalindrome(string s, int l, int r)
{
  while (l < r)
  {
    if (s[l++] != s[r--])
      return false;
  }
  return true;
}
bool validPalindrome(string s)
{
  int l = 0;
  int r = s.size() - 1;

  while (l < r)
  {
    if (s[l] != s[r])
    {
      return checkPalindrome(s, l + 1, r) || // removing left element
             checkPalindrome(s, l, r - 1);   // removing right element
    }
    l++;
    r--;
  }
  return true;
}

int main()
{
  return 0;
}