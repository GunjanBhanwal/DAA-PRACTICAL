#include<bits/stdc++.h>
using namespace std;
bool bfs(int node,vector<int> adjacent[],vector<bool> &visited,vector<int> &color){
    visited[node]=true;
    color[node]=0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto i:adjacent[temp]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                color[i]=!color[temp];
            }
            else{
                if(color[i]==color[temp]){
                    return false;
                }
            }
        }

    }
    return true;
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
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(matrix[i][j]==1){
                vis[i].push_back(j);
                vis[j].push_back(i);
            }
        }
    }
    vector<int>color(v,-1);
    bool ans=bfs(0,vis,visited,color);
    cout<<ans;
    

    return 0;
}
