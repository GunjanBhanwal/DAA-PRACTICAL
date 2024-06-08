#include<bits/stdc++.h>
using namespace std;
const int INF=numeric_limits<int>::max();
void dijkshtra(vector<vector<int>> adjacent[],int v,int source){
    vector<int> dist(v,INF);
    vector<int> pred(v,-1);
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    while(!pq.empty()){
        int current_distance=pq.top().first;
        int current_node=pq.top().second;
        pq.pop();
        if(current_distance > dist[current_node]) continue;
        for(auto i:adjacent[current_node]){
            int weight=i[0];
            int node=i[1];
            int distance=weight+current_distance;
            if(distance<dist[node]){
                dist[node]=distance;
                pred[node]=current_node;
                pq.push({distance,node});
            }
        }
    }
    for(int i=0;i<v;i++){
        if(dist[i]==INF){
            cout<<"path dont exist"<<endl;
        }
        else{
            stack<int>path;
            for(int at=i;at!=-1;at=pred[at]){
                path.push(at);
            }
            while(!path.empty()){
                cout<<path.top()+1<<" ";
                path.pop();
            }
            cout<<" "<<":"<<dist[i]<<endl;
        }
    }

}
int main(){
    int v;
    cin>>v;
    vector<vector<int>> adjacency[v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            int a;
            cin>>a;
            if(a>0){
                adjacency[i].push_back({a,j});
            }
        }
    }
    int source;
    cin>>source;
    dijkshtra(adjacency,v,source-1);
    return 0;
}