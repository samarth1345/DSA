#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = 0;
    int start = 0;
    int end = matrix[0].size()-1;
    int mid;
    while (start <= end && row < matrix.size())
    {
        mid = (start + end) / 2;
        if (matrix[row][mid] == target)
        {
            return true;
        }
        else if (matrix[row][mid] < target)
        {
            if (target > matrix[row][end])
            {
                row++;
            }
            else
            {
                start=mid+1;
            }
        }
        else if (matrix[row][mid] > target)
        {
            end=mid-1;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int New;
            cin >> New;
            temp.push_back(New);
        }
        matrix.push_back(temp);
    }
    int key;
    cin>>key;
    cout<<searchMatrix(matrix,key);
    return 0;
}