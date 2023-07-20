#include <iostream>
#include <vector>
using namespace std;

class bruteForceSolution
{
public:
  void markRow(vector<vector<int>> &matrix, int m, int i)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] != 0)
        matrix[i][j] = INT_MAX;
    }
  }
  void markCol(vector<vector<int>> &matrix, int n, int j)
  {
    for (int i = 0; i < n; i++)
    {
      if (matrix[i][j] != 0)
        matrix[i][j] = INT_MAX;
    }
  }

  void setZeroes(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 0)
        {
          markRow(matrix, m, i);
          markCol(matrix, n, j);
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == INT_MAX)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

class betterSoultion
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 0); // row vector to track row index of 0s
    vector<int> col(m, 0); // col vector to track column index of 0s

    // iterate to marks the row and col index of 0s
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 0)
        {
          row[i] = 1;
          col[j] = 1;
        }
      }
    }

    // iterate to change the marked rows and cols to 0
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (row[i] == 1 || col[j] == 1)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
};

class optimalSolution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1; // track the 0th col

    // mark the rows and cols of 0 cell
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = -9999;
          if (j != 0)
            matrix[0][j] = -9999;
          else
            col0 = -9999;
        }
      }
    }

    // make cell 0s for the marked rows and cols except the tracking keeping row and col
    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        if (matrix[i][j] != 0)
        {
          if (matrix[0][j] == -9999 || matrix[i][0] == -9999)
            matrix[i][j] = 0;
        }
      }
    }

    // checking for 0th row
    if (matrix[0][0] == -9999)
    {
      for (int j = 0; j < m; j++)
        matrix[0][j] = 0;
    }

    // checking for 0th col
    if (col0 = -9999)
    {
      for (int i = 0; i < n; i++)
        matrix[i][0] = 0;
    }
  }
};
int main()
{
  return 0;
}
