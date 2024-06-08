#include<bits/stdc++.h>
using namespace std;
static bool custom(pair<int,int> a,pair<int,int> b){
    return (a.second<b.second);
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }
    sort(v.begin(),v.end(),custom);
    int taken=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int dead=v[i].second;
        int comp=v[i].first;
        if(taken+comp<=dead){
         ans++;
         taken=taken+comp;
        }
    }
    cout<<ans;

}