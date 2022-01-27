#include<bits/stdc++.h>
using namespace std;
//logic:we are using prefix sum technique,we are going to store xor of subarrays
//in a map ,lets say numbers xor upto no. X and required xor is B, if X!=B then we can
//check from map if there is prefix sum as X^B,if there are subarrays with xor as X^B (let it be Y)
//we know that if Y subarray is removed we will be left with XOR as B
//eg k=6,arr=4 2 2 6 : lets say at 6 XOR would be 2,in map[6^2]=map[4]=2,so if we remove those two
//subarrays i.e [4],[4 2 2] we will left with subarray having XOR as 6 i.e [2 2 6] , [6].
int solve(vector<int> &A, int B) {
    unordered_map<int,int> map;
    int xr=0,size=A.size(),count=0;
    for(int i=0;i<size;i++)
    {
        xr=xr^A[i];
        if(xr==B)
            count++;
        count+=map[xr^B];
        map[xr]++;
    }
    return count;
}