#include<bits/stdc++.h>
using namespace std;
void primsAlgorithm(vector<vector<int>> adjacent[],int v,int &mini,int source)
{
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<bool> visited(v,false);
 pq.push({0, 0});
 int sum=0;
 while (!pq.empty()) {
        int u = pq.top().second; 
        int weight = pq.top().first;
        pq.pop();
        if (visited[u]) continue; 
        visited[u] = true;
        sum+=weight;
        for (auto i: adjacent[u]) {
            int k=i[0];
            int w=i[1];
            if (!visited[k]) {
                pq.push({w, k}); 
            }
        }
    }
    cout<<sum;

}
int main(){
    int V;
    cin >> V;
    vector<vector<int>> adjList[V];

    // Input the graph as adjacency list
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                adjList[i].push_back({j,weight});
            }
        }
    }
int minimum=0;
int source;
cin>>source;
primsAlgorithm(adjList, V,minimum,source);

    return 0;
}
