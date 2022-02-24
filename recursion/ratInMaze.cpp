#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool check(int row, int col, vector<vector<char>> &board, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == to_string(val)[0])
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == (to_string(val))[0])
            return false;
    }
    row = (row / 3) * 3;
    col = (col / 3) * 3;
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            if (board[i][j] == to_string(val)[0])
                return false;
        }
    }
    return true;
}
pair<int, int> findNext(int row, int col, vector<vector<char>> &board)
{
    for (int i = row; i < 9; i++)
    {
        for (int j = col; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                return {i, j};
            }
        }
        col = 0;
    }
    return {-1, -1};
}
bool travel(int row, int col, vector<vector<char>> &board)
{
    bool flag = false;
    for (int i = 1; i <= 9; i++)
    {
        if (check(row, col, board, i))
        {
            board[row][col] = to_string(i)[0];
            pair<int, int> next = findNext(row, col, board);
            if (next.first == -1)
                return true;
            bool ans = travel(next.first, next.second, board);
            if (!ans)
            {
                board[row][col] = '.';
            }
            else
                return true;
        }
    }
    return flag;
}
void solveSudoku(vector<vector<char>> &board)
{
    pair<int, int> t = findNext(0, 0, board);
    travel(t.first, t.second, board);
}