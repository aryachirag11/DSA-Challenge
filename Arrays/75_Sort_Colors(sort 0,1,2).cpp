#include <iostream>
using namespace std;

// simply sort the array
class bruteForceSolution
{
public:
  void sortColors(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
  }
};

// better solution
class betterSolution
{
public:
  void sortColors(vector<int> &nums)
  {
    int zeroes = 0, ones = 0, twos = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
        zeroes++;
      else if (nums[i] == 1)
        ones++;
      else
        twos++;
    }

    // Replace the places in the original array:
    for (int i = 0; i < zeroes; i++)
      nums[i] = 0; // replacing 0's

    for (int i = zeroes; i < zeroes + ones; i++)
      nums[i] = 1; // replacing 1's

    for (int i = zeroes + ones; i < nums.size(); i++)
      nums[i] = 2; // replacing 2's
  }
};
int main()
{
  return 0;
}