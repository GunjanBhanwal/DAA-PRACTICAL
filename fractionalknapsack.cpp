#include<bits/stdc++.h>
using namespace std;
static bool custom(pair<int,int>a,pair<int,int> b){
    double x=(double)a.first/a.second;
    double y=(double)b.first/b.second;
    return x>y;
} 
void calculate(vector<pair<int,int>> &v,int n, int w){
    sort(v.begin(),v.end(),custom);
    double ans=0.0;
    for(int i=0;i<n;i++){
        if(w>=v[i].second){
            ans+=v[i].first;
            w-=v[i].second;
        }
        else{
            ans+=v[i].first*((double)w/v[i].second);
            break;
        }
    }
    cout<<setprecision(4)<<ans;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].first;
            }
    int w;
    cin>>w;
    calculate(v,n,w);
    return 0;
}