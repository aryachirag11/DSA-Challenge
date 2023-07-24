#include <iostream>
#include <vector>
#include <set>
using namespace std;

// brute force
int removeDuplicates1(vector<int> &nums)
{
  set<int> st;
  for (int i = 0; i < nums.size(); i++)
  {
    st.insert(nums[i]);
  }
  int k = st.size();
  int j = 0;
  for (auto i : st)
  {
    nums[j++] = i;
  }
  return k;
}

// optimal approach
int removeDuplicates2(vector<int> &nums)
{
  int i = 0;
  int j = 1;

  while (j < nums.size())
  {
    if (nums[j] != nums[i])
    {
      swap(nums[++i], nums[j]);
    }
    j++;
  }
  return i + 1;
}

int main()
{
  vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << removeDuplicates2(v);

  return 0;
}
