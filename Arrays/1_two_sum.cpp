#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
  map<int, int> hash;
  for (int i = 0; i < nums.size(); i++)
  {
    int needed = target - nums[i];
    if (hash.find(needed) != hash.end())
      return {hash[needed], i};
    hash[nums[i]] = i;
  }
  return {-1, -1};
}

int main()
{
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> ans = twoSum(nums, target);
  for (auto it : ans)
  {
    cout << it << " ";
  }
  return 0;
}