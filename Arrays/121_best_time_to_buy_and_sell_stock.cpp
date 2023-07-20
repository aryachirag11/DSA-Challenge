#include <iostream>
#include <vector>
using namespace std;

// brute force O(N^2) wont work on online compliers for input length >= 10^5
class bruteForceSolution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int maximumProfit = 0;
    for (int i = 0; i < prices.size();)
    {
      for (int j = i + 1; j < prices.size();)
      {
        if (prices[j] > prices[i])
        {
          maximumProfit = max(maximumProfit, prices[j] - prices[i]);
        }
      }
    }
    return maximumProfit;
  }
};

// optimal solution O(N)
class optimalSolution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int minPrice = INT_MAX;
    int maximumProfit = 0;

    for (int i = 0; i < prices.size(); i++)
    {
      minPrice = min(minPrice, prices[i]);
      maximumProfit = max(maximumProfit, prices[i] - minPrice);
    }
    return maximumProfit;
  }
};
int main()
{
  return 0;
}
