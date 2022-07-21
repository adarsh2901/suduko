#include <bits/stdc++.h>
using namespace std;
bool isvalid(int row, int col, vector<vector<char>> &board, char k)
{
  for (int i = 0; i < 9; i++)
  {
    if (board[i][col] == k)
      return false;
    if (board[row][i] == k)
      return false;
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)
      return false;
  }
  return true;
}
bool solve(vector<vector<char>> &board)
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[i][j] == '.')
      {
        for (char k = '1'; k <= '9'; k++)
        {
          if (isvalid(i, j, board, k))
          {
            board[i][j] = k;
            if (solve(board))
              return true;
            board[i][j] = '.';
          }
        }
        return false;
      }
    }
  }
  return true;
}
bool solveSudoku(vector<vector<char>> &board)
{
  return solve(board);
}
int main()
{
  vector<vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
      };

  if (solveSudoku(board))
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }
  else
  {
    cout << "No solution found!" << endl;
  }
  return 0;
}