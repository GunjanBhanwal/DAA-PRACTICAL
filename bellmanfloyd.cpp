#include<bits/stdc++.h>
using namespace std;
const int INF=numeric_limits<int>::max();
int main(){
    int v;
    cin>>v;
    vector<vector<int>> adjacent[v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            int a;
            cin>>a;
            if(a!=0){
               adjacent[i].push_back({a,j});
            }
        }
    }
    vector<int> dist(v,INF);
    vector<int> pred(v,-1);
    int source;
    cin>>source;
    dist[source-1]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<v;j++){
            for(auto k:adjacent[j]){
                int v = k[1];
                int weight = k[0];
                if(dist[j]!=INF && (dist[j]+weight)<dist[v]){
                    dist[v]=dist[j]+weight;
                    pred[v]=j;
                }
            }
        }
    }
    for(int j=0;j<v;j++){
            for(auto k:adjacent[j]){
                int v = k[1];
                int weight = k[0];
                if(dist[j]!=INF && (dist[j]+weight)<dist[v]){
                    cout<<"negative loop exist"<<endl;
                    return 0;
                }
            }
        }
    

    for(int i=0;i<v;i++){
         stack<int> path;
    for (int at = i; at != -1; at = pred[at]) {
        path.push(at);
    }
    while (!path.empty()) {
        cout << path.top() + 1 << " "; 
        path.pop();
    }
    cout<<":"<<dist[i]<<endl;
    }
    return 0;
}