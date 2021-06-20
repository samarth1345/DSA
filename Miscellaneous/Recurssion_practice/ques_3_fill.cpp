#include<iostream>
using namespace std;
void fill(int *arr,int row,int col,int tofill,int prevfill)
{
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=sizeof(arr[0])/sizeof(arr[0][0]);
    if(row<0 || row>n || col<0 || col>m)
    {
        return;
    } 
    if(prevfill!=tofill)
    {
        return;
    }
    arr[row][col]=tofill;
    fill(arr,row-1,col,tofill,arr[row][col]);
    fill(arr,row+1,col,tofill,arr[row][col]);
    fill(arr,row,col-1,tofill,arr[row][col]);
    fill(arr,row-1,col+1,tofill,arr[row][col]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    fill((int *)arr,n/2,m/2,1,0);
}