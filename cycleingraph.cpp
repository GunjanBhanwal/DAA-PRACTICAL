#include<bits/stdc++.h>
using namespace std;
bool iscycle(int node,vector<bool> &visited,vector<int> adjacent[],vector<int> pathvisited){
    visited[node]=true;
    pathvisited[node]=true;
    for(auto i:adjacent[node]){
        if(!visited[i]){
           if(iscycle(i,visited,adjacent,pathvisited)==true){
           return true;
           }
        }
        else if(pathvisited[i]==true){
                return true;} 
}
pathvisited[node]=false;
    return false;
}

int main(){
    int v;
    cin>>v;
    vector<bool>visited(v,false);
    vector<int> adjacency[v];
    vector<vector<int>>matrix;
    vector<int>pathvisited(v,false);
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
                adjacency[i].push_back(j);
            }
        }
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
     if(iscycle(0,visited,adjacency,pathvisited)==true){
        cout<<"cycle exists";
        return 0;}
         }
    }
    cout << "Cycle does not exist\n";
    return 0;
}