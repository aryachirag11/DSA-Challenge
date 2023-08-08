#include <iostream>
#include <string>
#include <vector>
using namespace std;
void addParanthesis(vector<string> &ans, string s, int openN, int closeN, int n)
{
  // base
  if (openN == n && closeN == n)
  {
    ans.push_back(s);
    return;
  }

  // if no.of open paranthesis is less than n , add open paranthesis
  if (openN < n)
  {
    // s += "(";
    addParanthesis(ans, s + "(", openN + 1, closeN, n);
  }

  // if no. of close paranthesis is less than no. of closed paranthesis add clsoe paranthesis
  if (closeN < openN)
  {
    //  s += ")";
    addParanthesis(ans, s + ")", openN, closeN + 1, n);
  }
}

vector<string> generateParenthesis(int n)
{
  /* add open parathesis if open < n
     add close paranthesis if close < open
     base case open == close == n
  */
  vector<string> ans;
  string s = "";
  addParanthesis(ans, s, 0, 0, n);
  return ans;
}
int main()
{
  return 0;
}