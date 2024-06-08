#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int j=1;
    int sum=0;
    for(int i=0;i<n-1;i++){
        v[j]=v[i]+v[i+1];
        sum+=v[j];
        j++;
    }
    cout<<sum;
    return 0;
}