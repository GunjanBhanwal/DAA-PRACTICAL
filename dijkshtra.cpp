#include<bits/stdc++.h>
using namespace std;
const int INF=numeric_limits<int>::max();
void dijkshtra(vector<vector<int>> &graph,int source){
int v=graph.size();
vector<int> dist(v,INF);
vector<int>prred(v,-1);
dist[source]=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
pq.push({0,source});
while(!pq.empty()){
    int current_distance = pq.top().first;
    int current_node = pq.top().second;
    pq.pop();
    if (current_distance > dist[current_node]) continue;
    for(int i=0;i<v;i++){
        if(graph[current_node][i]>0){
            int distance=current_distance+graph[current_node][i];
            if(distance<dist[i]){
                dist[i]=distance;
                prred[i]=current_node;
                pq.push({distance,i});
            }
        }
    }
}
for(int i=0;i<v;i++){
    if(dist[i]==INF){
        cout<<"no path exists"<<endl;
    }
    else{
        stack<int>path;
        for(int at=i;at!=-1;at=prred[at]){
        path.push(at);
        }
        while(!path.empty()){
            cout<<path.top()+1<<" ";
            path.pop();
        }
        cout<<" "<<dist[i]<<endl;
    }
}
}
int main(){
    int v;
   cin>>v;
    vector<int> vis[v];
    vector<bool> visited(v,false);
    vector<vector<int>>matrix;
    for(int i=0;i<v;i++){
        vector<int>temp;
        for(int j=0;j<v;j++){
            int a;
            cin>>a;
            temp.push_back(a);
        }
        matrix.push_back(temp);
    }
    int source;
    cin>>source;
    dijkshtra(matrix,source-1);
    return 0;
}
