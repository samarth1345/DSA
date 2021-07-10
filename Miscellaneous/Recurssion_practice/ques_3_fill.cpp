#include<iostream>
#include<vector>
using namespace std;
void fill(vector<vector<int>> &arr,int row,int col,int tofill,int prevfill,int n,int m)
{
    cout<<arr[0][0];
    if(row<0 || row>n || col<0 || col>m)
    {
        return;
    } 
    if(prevfill!=tofill)
    {
        return;
    }
    arr[row][col]=tofill;
    fill(arr,row-1,col,tofill,arr[row][col],n,m);
    fill(arr,row+1,col,tofill,arr[row][col],n,m);
    fill(arr,row,col-1,tofill,arr[row][col],n,m);
    fill(arr,row-1,col+1,tofill,arr[row][col],n,m);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    fill(arr,n/2,m/2,1,0,n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}