#include <bits/stdc++.h>
using namespace std;
#define MAX 10
void Display(int arr[][MAX],int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout<<arr[i][j]<<" ";
    cout<<endl;
}
vector<int> goAnticlockwise(int k, int arr[][MAX], int n, map<pair<int, int>, bool> &map)
{
    vector<int> ans;
    if (k <= (n - 1) / 2)
    {
        for (int i = k; i < n - k; i++)
            ans.push_back(arr[i][k]);
        for (int i = k + 1; i < n - k - 1; i++)
            ans.push_back(arr[n - k - 1][i]);
    }
    else
    {
        for (int i = k; i >= n - k - 1; i--)
            ans.push_back(arr[i][k]);
        for (int i = k - 1; i >= n - k; i--)
            ans.push_back(arr[n - k - 1][i]);
    }
    return ans;
}
void ModifyArr1(vector<int> temp,int j,int arr[][MAX],int n)
{
    if (j <= (n - 1) / 2)
    {
        int count=0;
        for (int i = j; i < n - j; i++)
        {
            arr[i][j]=temp[count];
            count++;
            //ans.push_back(arr[i][k]);
        }
        for (int i = j + 1; i < n - j - 1; i++)
        {
            arr[n - j - 1][i]=temp[count];
            count++;
            //ans.push_back(arr[n - k - 1][i]);
        }
    }
    else
    {
        int count=0;
        for (int i = j; i >= n - j - 1; i--)
        {
            arr[i][j]=temp[count];
            count++;
            //ans.push_back(arr[i][k]);
        }
        for (int i = j - 1; i >= n - j; i--)
        {
            arr[n - j - 1][i]=temp[count];
            count++;
            //ans.push_back(arr[n - k - 1][i]);
        }
    }
}
void Insertion_sort(vector<int> &temp, int i,int arr[][MAX],int n,int index)
{
    int j;
    j=i;
    i--;
    while (i >= 0)
    {
        if (temp[i] > temp[j])
        {
            int t = temp[i];
            temp[i] = temp[j];
            temp[j] = t;
            j=i;
        }
        i--;
    }
    ModifyArr1(temp,index,arr,n);
}
void Insertion_sort_2(vector<vector<int>> &finalLists, int i,int arr[][MAX],int n,int index)
{
    int t=n-index-1,to_i,to_j;
    to_i=index;
    to_j=i;
    int size=finalLists[t].size();
    for(int k=i-1;k>=0;k--)
    {
        if(finalLists[index][k] > finalLists[to_i][to_j] )
        {
            int temp=finalLists[to_i][to_j];
            finalLists[to_i][to_j]=finalLists[index][k];
            finalLists[index][k]=temp;
            to_i=index;
            to_j=k;
        }
    }
    for(int k=size-1;k>=0;k--)
    {
        if(finalLists[t][k] > finalLists[to_i][to_j])
        {
            //cout<<finalLists[t][k]<<" "<<finalLists[to_i][to_j]<<endl;
            int temp=finalLists[to_i][to_j];
            finalLists[to_i][to_j]=finalLists[t][k];
            finalLists[t][k]=temp;
            //cout<<":"<<finalLists[t][k]<<" "<<finalLists[to_i][to_j]<<endl;
            to_i=t;
            to_j=k;
        }
    }
    ModifyArr1(finalLists[index],index,arr,n);
    ModifyArr1(finalLists[t],t,arr,n);
}
void Sort(vector<vector<int>> &finalLists,int arr[][MAX])
{
    int n = finalLists.size();
    int counter = 1;
    int Max = finalLists[0].size();
    for (int j = 1; j < Max; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (counter < finalLists[i].size())
                Insertion_sort(finalLists[i], counter,arr,n,i);
        }
        Display(arr,n);
        counter++;
    }
    counter=0;
    for (int j = 0; j < Max; j++)
    {
        for (int i = n/2; i < n; i++)
        {
            if (counter < finalLists[i].size())
            {
                Insertion_sort_2(finalLists, counter,arr,n,i);
            }
        }
        Display(arr,n);
        counter++;
    }
}
vector<vector<int>> makelists(int arr[][MAX], int n)
{
    vector<vector<int>> finalLists(n);
    map<pair<int, int>, bool> map;
    for (int i = 0; i < n / 2; i++)
    {
        finalLists[i] = goAnticlockwise(i, arr, n, map);
        finalLists[n - 1 - i] = goAnticlockwise(n - 1 - i, arr, n, map);
    }
    if (n % 2 != 0)
    {
        finalLists[n / 2] = goAnticlockwise(n / 2, arr, n, map);
    }
    return finalLists;
}
int main()
{
    int n;
    cin >> n;
    int arr[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<vector<int>> lists = makelists(arr, n);
    Sort(lists,arr);
}