#include<bits/stdc++.h>
using namespace std;
class disjoint{
    vector<int> rank,parent;
    public:
    disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findupper(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findupper(parent[node]);
    }
    void unionbyrank(int u,int v){
        int up=findupper(u);
        int vp=findupper(v);
        if(up==vp)return;
        if(rank[up]<rank[vp]){
         parent[up]=vp;
        }
        else if(rank[vp]<rank[up]){
            parent[vp]=up;
        }
        else{
            parent[vp]=up;
            rank[up]++;
        }
    }
};
int main(){
int v;
cin>>v;
vector<vector<int>>adj[v];
for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        int a;
        cin>>a;
        if(a!=0){
            adj[i].push_back({j,a});
        }
    }
}
vector<pair<int,pair<int,int>>> edges;
for(int i=0;i<v;i++){
    for(auto j:adj[i]){
        int node=j[0];
        int wt=j[1];
        int current=i;
        edges.push_back({wt,{current,node}});

    }
}
disjoint ds(v);

sort(edges.begin(),edges.end());
int mini=0;
for(auto it:edges){
    int wt=it.first;
    int u=it.second.first;
    int v=it.second.second;
    if(ds.findupper(u) != ds.findupper(v)){
        mini+=wt;
        ds.unionbyrank(u,v);
    }
}
cout<<mini;

    return 0;
}