class Solution
{
public:
  int findAns(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
  {
    if (ind == n)
      return 0;
    if (dp[ind][buy] != -1)
      return dp[ind][buy];
    int maxProfit = 0;

    if (buy)
    {
      maxProfit = max((-prices[ind] + findAns(ind + 1, 0, prices, n, dp)), (0 + findAns(ind + 1, 1, prices, n, dp)));
    }
    else
    {
      maxProfit = max((prices[ind] + findAns(ind + 1, 1, prices, n, dp)), (0 + findAns(ind + 1, 0, prices, n, dp)));
    }

    return dp[ind][buy] = maxProfit;
  }
  int maxProfit(vector<int> &prices)
  {

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return findAns(0, 1, prices, n, dp);
  }
};