// brute force
class bruteForceSolution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
      if (nums[i] == nums[i + 1])
        return nums[i];
    }
    return 0;
  }
};

// better solution using extra space
class betterSolution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    vector<int> frequencies(n + 1, 0);

    for (int i = 0; i < nums.size(); i++)
    {
      if (frequencies[nums[i]] == 0)
        frequencies[nums[i]]++;
      else
        return nums[i];
    }
    return 0;
  }
};

// optimal solution
class optimalSolution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int smallStep = nums[0];
    int bigStep = nums[0];
    do
    {
      smallStep = nums[smallStep];
      bigStep = nums[nums[bigStep]];
    } while (smallStep != bigStep);

    bigStep = nums[0];
    while (smallStep != bigStep)
    {
      smallStep = nums[smallStep];
      bigStep = nums[bigStep];
    }
    return smallStep;
  }
};