#include <iostream>
#include <string>
#include <vector>
using namespace std;

string minWindow(string s, string t)
{
  int m = s.length();
  int n = t.length();

  if (m == 0 || n == 0 || m < n)
    return "";

  vector<int> v(256, 0);
  for (int i = 0; i < n; i++)
  {
    v[t[i]]++;
  }
  int start = 0, end = 0, ans_start = 0, count = 0;
  int min_window = INT_MAX;

  while (end < m)
  {
    if (v[s[end]] > 0)
      count++;

    v[s[end]]--;
    while (count == (int)n)
    {
      if (min_window > end - start + 1)
      {
        min_window = end - start + 1;
        ans_start = start;
      }
      v[s[start]]++;
      if (v[s[start]] > 0)
        count--;

      start++;
    }
    end++;
  }
  if (min_window == INT_MAX)
    return "";

  return s.substr(ans_start, min_window);
}
int main()
{
  cout << minWindow("ADOBECODEBANC", "ABC");
  return 0;
}