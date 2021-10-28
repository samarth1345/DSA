#include <bits/stdc++.h>
#define MAX 10
using namespace std;
pair<int,int> reversespiral(int arr[][MAX], int row, int col, int i, int j,string which)
{
    pair<int,int> ans;
    int size = row * col;
    vector<int> visited(size);
    int k = 0;
    while (k < size)
    {
        while (j >= 0 && arr[i][j] != -1)
        {
            visited[k] = arr[i][j];
            arr[i][j] = -1;
            k++;
            j--;
        }
        if(k >= size)
        {
            break;
        }
        j++;
        i++;
        while (i < row && arr[i][j] != -1)
        {
            visited[k] = arr[i][j];
            arr[i][j] = -1;
            k++;
            i++;
        }
        if(k >= size)
        {
            break;
        }
        i--;
        j++;
        while (j < col && arr[i][j] != -1)
        {
            visited[k] = arr[i][j];
            arr[i][j] = -1;
            k++;
            j++;
        }
        if(k >= size)
        {
            break;
        }
        j--;
        i--;
        while (i >= 0 && arr[i][j] != -1)
        {
            visited[k] = arr[i][j];
            arr[i][j] = -1;
            k++;
            i--;
        }
        if(k >= size)
        {
            break;
        }
        j--;
        i++;
    }
    for (int i = 0; i < k; i++)
    {
        cout << visited[i] << " ";
    }
    if(which=="left")
    {
       ans.first=i;
       ans.second=j+1;
    }
    else if(which=="right")
    {

    }
    return ans;
}
int main()
{
    int matrix, row, col;
    cin >> matrix >> row >> col;
    int input[matrix][MAX][MAX];
    for (int i = 0; i < matrix; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                cin >> input[i][j][k];
            }
        }
    }
    int start_pos[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> start_pos[i];
    }
    if((start_pos[2]==col-1||start_pos[2]==0) && start_pos[1]!=0 && start_pos[1]!=row-1)
    {
        pair<int,int> start;
        //left case
        if(start_pos[2]==0)
        {
            start={start_pos[1],start_pos[2]+1};
            for(int i=0;i<col;i++)
            {
                int temp_i=0,temp_j=0;
                int temp[MAX][MAX];
                for(int j=0;j<row;j++)
                {
                    for(int k=matrix-1;k>=0;k--)
                    {
                        temp[temp_i][temp_j]=input[k][j][i];
                        temp_j++;
                    }
                    temp_j=0;
                    temp_i++;
                }
                start=reversespiral(temp,row,matrix,start.first,start.second,"left");
                cout<<endl<<start.first<<" "<<start.second<<endl;
            }
        }
        //right case 
        else
        {
            start={start_pos[1],start_pos[2]-1};
            for(int i=col-1;i>=0;i--)
            {
                int temp[MAX][MAX];
                int temp_i=0,temp_j=0;
                for(int j=0;j<row;j++)
                {
                    for(int k=matrix-1;k>=0;k--)
                    {
                        temp[temp_i][temp_j]=input[k][j][i];
                        temp_j++;
                    }
                    temp_j=0;
                    temp_i++;
                }
                start=reversespiral(temp,row,matrix,start.first,start.second,"right");
            }
        }
    }
    else
    {
        //top and bottom
    }
}
