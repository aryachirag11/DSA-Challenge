#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
  long long findMinDiff(vector<long long> a, long long n, long long m)
  {
    if (m == 0 || n == 0)
      return 0;
    sort(a.begin(), a.end());

    if (n < m)
      return -1;

    long long minDiff = LONG_MAX;

    for (int i = 0; i + m - 1 < n; i++)
    {
      minDiff = min(minDiff, a[i + m - 1] - a[i]);
    }

    return minDiff;
  }
};
int main()
{
  return 0;
}
