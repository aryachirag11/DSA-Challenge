#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// max reachable approach
bool canJump1(vector<int> &nums)
{
  int n = nums.size();
  int reachable = 0;

  for (int i = 0; i < n; i++)
  {
    if (reachable < i)
      return false;

    // max jump
    reachable = max(reachable, i + nums[i]);
  }
  return true;
}

// greedy approach
bool canJump2(vector<int> &nums)
{
  int n = nums.size();
  int goal = n - 1;

  for (int i = n - 1; i >= 0; i--)
  {
    if (i + nums[i] >= goal)
      goal = i;
  }

  return goal == 0;
}

int main()
{
  return 0;
}