#include<bits/stdc++.h>
using namespace std;
static bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
//check if angle is clockwise
bool cw(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    int ax=a.first,ay=a.second,bx=b.first,by=b.second,cx=c.first,cy=c.second;
    return ax * (cy - by) + bx * (ay - cy) + cx * (by - ay) > 0;
}
//check if angle is anticlockwise
bool acw(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    int ax=a.first,ay=a.second,bx=b.first,by=b.second,cx=c.first,cy=c.second;
    return ax * (cy - by) + bx * (ay - cy) + cx * (by - ay) < 0;
}
bool collinear(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    int ax=a.first,ay=a.second,bx=b.first,by=b.second,cx=c.first,cy=c.second;
    return ax * (cy - by) + bx * (ay - cy) + cx * (by - ay) == 0;
}
vector<pair<int, int>> grahams_scan(vector<pair<int, int>> points)
{
    int n=points.size();
    sort(points.begin(),points.end(),comp);
    vector<pair<int,int>> up,down;
    //first point is in both the sets
    up.push_back(points[0]); down.push_back(points[0]);
    for(int i=1;i<n;i++){
        //either it is last point or angle between first,this and last point is clockwise
        if(i==n-1 || cw(points[0],points[i],points[n-1])){
            //these are up region points
            while(up.size()>2 && acw(up[up.size()-2],up[up.size()-1],points[i]))
                up.pop_back();
            up.push_back(points[i]);
        }
        else if (i == n - 1 || acw(points[0], points[i], points[n - 1]))
        {
            // these are up region points
            while (down.size() > 2 && cw(down[down.size() - 2], down[down.size() - 1], points[i]))
                down.pop_back();
            down.push_back(points[i]);
        }
    }
    points.clear();
    for(auto i:up) points.push_back(i);
    for(auto i:down) points.push_back(i);
    sort(points.begin(),points.end());
    //taking only the unique points
    points.resize(unique(points.begin(),points.end())-points.begin());
    return points;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> points(n);
    for(int i=0;i<n;i++) cin>>points[i].first,cin>>points[i].second;
    vector<pair<int,int>> ans=grahams_scan(points);
    for(auto i:ans) cout<<i.first<<" "<<i.second<<endl; 
}