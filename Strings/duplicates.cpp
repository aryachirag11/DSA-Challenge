#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// using hashing
void print_duplicate_characters1(string s)
{
  map<char, int> mp;
  int n = s.size();

  for (int i = 0; i < n; i++)
  {
    mp[s[i]]++;
  }
  for (auto it : mp)
  {
    if (it.second > 1)
    {
      cout << it.first << " -> " << it.second << endl;
    }
  }
}

// using sorting
void print_duplicate_characters2(string s)
{
  int n = s.size();
  sort(s.begin(), s.end());

  for (int i = 0; i < n; i++)
  {
    int count = 1;
    while (i < n && s[i] == s[i + 1])
    {
      count++;
      i++;
    }
    if (count > 1)
      cout << s[i] << " -> " << count << endl;
  }
}
int main()
{
  string str = "geeksforgeeks";
  print_duplicate_characters2(str);
  return 0;
}