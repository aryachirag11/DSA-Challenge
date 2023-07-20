#include <iostream>
#include <vector>
using namespace std;

// brute force solution
class bruteForceSolution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    vector<int> non_zeroes;
    // store non zeroes in temp
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
        non_zeroes.push_back(nums[i]);
    }

    // insert non zeroes in front of original array
    for (int i = 0; i < non_zeroes.size(); i++)
    {
      nums[i] = non_zeroes[i];
    }

    // insert zeroes to remaing positions
    for (int i = non_zeroes.size(); i < nums.size(); i++)
    {
      nums[i] = 0;
    }
  }
};

// optimal solution
class optimalSolution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int j = -1;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
      {
        j = i;
        break;
      }
    }

    if (j == -1)
      return;

    for (int i = j + 1; i < nums.size(); i++)
    {
      if (nums[i] == 0)
      {
        swap(nums[i], nums[j]);
        j++;
      }
    }
  }
};
int main()
{

  return 0;
}