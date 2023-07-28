#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
  int n = nums.size();
  map<int, int> hash;
  hash[0] = 1;
  int prefixSum = 0;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    prefixSum += nums[i];
    int prefix = prefixSum - k;
    count += hash[prefix];
    hash[prefixSum] += 1;
  }
  return count;
}
int main()
{
  return 0;
}