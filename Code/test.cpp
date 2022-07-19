#include <bits/stdc++. h>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
    int res = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,0)); // 0 is weight ,0 is the starting point
    vector<int> visited;
    visited.resize(points.size(),0);
    int res =0;
    
    while(!pq.empty()){
        auto v1 = pq.top();pq.pop();
        int v = v1.second;   
        if(visited[v] == 1) continue;
        visited[v] = 1;
        res += v1.first;
        for(auto v2 : points[v]){
            if(visited[v2] == 1) continue;
            int w = abs(points[v][0] - points[v2][0]) + abs(points[v][1] - points[v2][1]);
            pq.push(make_pair(w,v2));
        }

    } 
    return res;
}