#include <iostream>
#include <string>
using namespace std;

// Brute force
int strStr1(string haystack, string needle)
{
  int m = haystack.size();
  int n = needle.size();

  for (int i = 0; i < m - n + 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (haystack[i + j] != needle[j])
        break;

      if (j == n - 1)
        return i;
    }
  }
  return -1;
}

// STL function
int strStr2(string haystack, string needle)
{
  return haystack.find(needle);
}

int main()
{
  cout << strStr2("hello", "ll");
  return 0;
}