#include <bits/stdc++.h>
#define MAX 10
using namespace std;
void rectify(pair<int,int> &ans,int row,int col)
{
    if(ans.first<0 || ans.first>=row)
    {
        if(ans.first<0) ans.first=0;
        else ans.first=row-1;
    }
    else if(ans.second<0 || ans.second>=col)
    {
        if(ans.second<0) ans.second=0;
        else ans.second=col-1;
    }
}
pair<int, int> reversespiral(int arr[][MAX], int row, int col, int i, int j,string which)
{
    pair<int, int> ans;
    int size = row * col;
    int b=col-1-j,stop=0;
    vector<int> visited(size);
    int k = 0;
    while (k < size)
    {
        while (j >= 0 && arr[i][j] != -1 && stop<=b)
        {
            visited[k] = arr[i][j];
            arr[i][j] = -1;
            k++;
            stop++;
            j--;
        }
        if(k>=size) 
        {
            if(arr[i][j] == -1)  j++;
            goto time;
        }
        j++;
        i++;
        stop=0;
        while (i < row && arr[i][j] != -1 && stop<=b)
        {
            visited[k] = arr[i][j];
            arr[i][j] = -1;
            k++;
            i++;
        }
        if(k>=size) 
        {
            if(arr[i][j] == -1)  i--;
            goto time;
        }
        i--;
        j++;
        stop=0;
        while (j < col && arr[i][j] != -1 && stop<=b)
        {
            visited[k] = arr[i][j];
            arr[i][j] = -1;
            k++;
            j++;
        }
        if(k>=size) 
        {
            if(arr[i][j] == -1)  j--;
            goto time;
        }
        j--;
        i--;
        stop=0;
        while (i >= 0 && arr[i][j] != -1 && stop<=b)
        {
            visited[k] = arr[i][j];
            arr[i][j] = -1;
            k++;
            i--;
        }
        if(k>=size) 
        {
            if(arr[i][j] == -1)  i++;
            goto time;
        }
        j--;
        i++;
        stop=0;
        b++;
    }
    time:
    for (int i = 0; i < k; i++)
    {
        cout << visited[i] << " ";
    }
    ans.first=i; ans.second=j;
    rectify(ans,row,col);
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
            
            start={start_pos[1],(matrix-1-start_pos[0])};
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
            }
        }
        //right case 
        else
        {
            //
            start={start_pos[1],(matrix-1-start_pos[0])};
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
        pair<int,int> start;
        if(start_pos[1]==0)
        {
            start={(matrix-1-start_pos[0]),start_pos[2]};
            for(int i=0;i<row;i++)
            {
                int temp[MAX][MAX];
                int temp_i=0,temp_j=0;
                for(int j=0;j<col;j++)
                {
                    for(int k=matrix-1;k>=0;k--)
                    {
                        temp[temp_i][temp_j]=input[k][i][j];
                        temp_j++;
                    }
                    temp_j=0;
                    temp_i++;
                }
                start=reversespiral(temp,col,matrix,start.first,start.second,"top");
            }
        }
        else
        {
            start={(matrix-1-start_pos[0]),start_pos[2]};
            for(int i=row-1;i>=0;i--)
            {
                int temp[MAX][MAX];
                int temp_i=0,temp_j=0;
                for(int j=0;j<col;j++)
                {
                    for(int k=matrix-1;k>=0;k--)
                    {
                        temp[temp_i][temp_j]=input[k][i][j];
                        temp_j++;
                    }
                    temp_j=0;
                    temp_i++;
                }
                start=reversespiral(temp,col,matrix,start.first,start.second,"bottom");
            }
        }
    }
}