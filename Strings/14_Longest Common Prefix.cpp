#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
  string common_prefix = "";
  // int n = strs[0].size();
  // int m = strs.size();

  for (int i = 0; i < strs[0].length(); i++)
  {
    for (int j = 0; j < strs.size(); j++)
    {
      if (i == strs[j].size() || strs[j][i] != strs[0][i])
        return strs[0].substr(0, i);
      // common_prefix += strs[0][i];
    }
  }
  return strs[0];
}
int main()
{
  return 0;
}