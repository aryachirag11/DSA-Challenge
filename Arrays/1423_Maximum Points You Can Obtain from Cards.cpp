// uisng sliding window appraoch
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  return 0;
}

int maxScore(vector<int> &cardPoints, int k)
{
  int n = cardPoints.size();
  int left = 0;
  int right = n - k;
  int total = 0;
  int ans = 0;
  for (int i = right; i < n; i++)
    total += cardPoints[i];
  ans = total;

  while (right < n)
  {
    total += (cardPoints[left] - cardPoints[right]);
    ans = max(total, ans);
    left++;
    right++;
  }
  return ans;
}
