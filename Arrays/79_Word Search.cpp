#include <iostream>
#include <vector>
using namespace std;

// recursive function for backtracking
bool dfs(vector<vector<char>> &board, string &word, int i, int j, int s)
{
  if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
    return false;
  if (board[i][j] != word[s] || board[i][j] == '*')
    return false;
  if (s == word.length() - 1)
    return true;

  const char cache = board[i][j];
  board[i][j] = '*';
  const bool doesExist = dfs(board, word, i + 1, j, s + 1) ||
                         dfs(board, word, i - 1, j, s + 1) ||
                         dfs(board, word, i, j + 1, s + 1) ||
                         dfs(board, word, i, j - 1, s + 1);
  board[i][j] = cache;

  return doesExist;
}

// main function
bool exist(vector<vector<char>> &board, string word)
{
  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      if (dfs(board, word, i, j, 0))
      {
        return true;
      }
    }
  }
  return false;
}
int main()
{
  return 0;
}