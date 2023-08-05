#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
  stack<int> st;
  for (auto it : s)
  {
    if (it == '(' ||
        it == '[' ||
        it == '{')
      st.push(it);
    else
    {
      if (st.empty())
        return false;
      char ch = st.top();
      st.pop();
      if (it == ')' && ch == '(' ||
          it == ']' && ch == '[' ||
          it == '}' && ch == '{')
        continue;
      else
        return false;
    }
  }
  return st.empty();
}

int main()
{
  return 0;
}