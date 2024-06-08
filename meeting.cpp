#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>start(n);
    vector<int>end(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    int current_start=start[0];
    int current_end=end[0];
    int ans=1;
    vector<int>anslist;
    anslist.push_back(1);
    for(int i=1;i<n;i++){
        if(start[i]>=current_end){
            ans+=1;
            anslist.push_back(i+1);
            current_start=start[i];
            current_end=end[i];
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<anslist.size();i++){
        cout<<anslist[i]<<" ";
    }
    return 0;
}