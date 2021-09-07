#include <iostream>
using namespace std;
int *spirallyTraverse(int r, int c, int **matrix)
{
    int size = r * c;
    int *ans = new int[size];
    int i = 0, j = 0;
    int count = 0;
    bool row_right = true;
    bool row_left = false;
    bool col_up = false;
    bool col_down = false;
    while (size > 0)
    {
        if (row_right)
        {
            ans[count] = matrix[i][j];
            matrix[i][j] = -1;
            j++;
        }
        else if (row_left)
        {
            ans[count] = matrix[i][j];
            matrix[i][j] = -1;
            j--;
        }
        else if (col_up)
        {
            ans[count] = matrix[i][j];
            matrix[i][j] = -1;
            i--;
        }
        else if (col_down)
        {
            ans[count] = matrix[i][j];
            matrix[i][j] = -1;
            i++;
        }
        size--;
        count++;
        if (col_up || col_down)
        {
            if (i > r - 1 || i < 0 || matrix[i][j] == -1)
            {
                if (i > r - 1)
                {
                    i--;
                    j--;
                    row_left = true;
                }
                else if (matrix[i][j] == -1)
                {
                    if (col_up)
                    {
                        row_right = true;
                        i++;
                        j++;
                    }
                    else
                    {
                        i--;
                        j--;
                        row_left = true;
                    }
                }
                else
                {
                    i++;
                    j++;
                    row_right = true;
                }
                col_up = false;
                col_down = false;
            }
        }
        else if(row_left || row_right)
        {
            if (j > c - 1 || j < 0 || matrix[i][j] == -1)
            {
                if (j > c - 1)
                {
                    j--;
                    i++;
                    col_down = true;
                }
                else if (matrix[i][j] == -1)
                {
                    if (row_right)
                    {
                        j--;
                        i++;
                        col_down = true;
                    }
                    else
                    {
                        j++;
                        i--;
                        col_up = true;
                    }
                }
                else
                {
                    j++;
                    i--;
                    col_up = true;
                }
                row_right = false;
                row_left = false;
            }
        }
    }
    return ans;
}
int main()
{
    int row, col;
    cin >> row >> col;
    int **matrix = new int *[col];
    for (int i = 0; i < col; i++)
    {
        matrix[i] = new int[row];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int *ans = spirallyTraverse(row, col, matrix);
    for (int i = 0; i < row * col; i++)
    {
        cout << ans[i] << " ";
    }
}