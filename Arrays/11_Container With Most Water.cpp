class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int maxArea = 0;
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
      int area = (right - left) * (min(height[left], height[right]));
      maxArea = max(maxArea, area);

      if (height[left] < height[right])
        left++;
      // else if(height[left] > height[right]) right--;
      else
        right--;
    }

    return maxArea;
  }
};