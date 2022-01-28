#include <bits/stdc++.h>
using namespace std;
//Battleships can only be placed horizontally or vertically on board. 
//In other words, they can only be made of the shape 1 x k (1 row, k columns) or
// k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or 
//vertical cell separates between two battleships (i.e., there are no adjacent battleships).
void locateships(vector<vector<char>> &board, int x, int y)
{
    if ((x >= 0) && (x < board.size()) && (y >= 0) && (y < board[0].size()))
    {
        if (board[x][y] == '.')
            return;
        board[x][y] = '.';
        locateships(board, x + 1, y);
        locateships(board, x - 1, y);
        locateships(board, x, y + 1);
        locateships(board, x, y - 1);
    }
}
int countBattleships(vector<vector<char>> &board)
{
    int row = board.size();
    int col = board[0].size();
    int ships = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 'X')
            {
                cout << i << " " << j << endl;
                ships++;
                locateships(board, i, j);
            }
        }
    }
    return ships;
}