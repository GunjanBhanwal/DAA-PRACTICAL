#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int maxi=0;
    for(int i=0;i<n-1;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(v[i]==v[j]){
                count++;
            }
            else{
                break;
            }
        }
        maxi=max(maxi,count);
        
    }
    if(maxi>n/2){
        cout<<"YES"<<endl;
    }
    if(n/2==0){
        cout<<v[n/2]<<" "<<v[(n/2)+1]<<endl;
    }
    else{
        cout<<v[n/2];
    }
    return 0;
}