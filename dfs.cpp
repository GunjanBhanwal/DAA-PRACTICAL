#include<bits/stdc++.h>
using namespace std;
void dfs(int source,vector<int> adjacency[],vector<bool> &visited){
    visited[source]=true;
    for(auto i:adjacency[source]){
        if(!visited[i]){
            dfs(i,adjacency,visited);
        }
    }
}
int main(){
    int v;
    int n,m;
    cin>>v>>n>>m;
    vector<int> vis[v];
    vector<bool> visited(v,false);
    vector<vector<int>>matrix;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            temp.push_back(a);
        }
        matrix.push_back(temp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1){
                vis[i].push_back(j);
                vis[j].push_back(i);
            }
        }
    }
    int source,destination;
    cin>>source>>destination;
    dfs(source-1,vis,visited);
    if(visited[destination-1]){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    return 0;
}
