#include<bits/stdc++.h>
using namespace std;
int calculate(int capacity,int size,vector<int> & price){
    if(capacity<=0 || size<=0){
        return 0;
    }
    if(capacity<size){
        return calculate(capacity,size-1,price);
    }
    //pick
    int a=calculate(capacity-size,size,price)+price[size];
    //not pick
    int b=calculate(capacity,size-1,price);
    return max(a,b);
}
int main(){
    int t;
    cout<<"no of testcases"<<endl;
    cin>>t;
    while(t--){
        int n;
        cout<<"size of rod"<<endl;
        cin>>n;
        vector<int>price(n+1);
        for(int i=1;i<=n;i++){
            cin>>price[i];
        }
        int maxprice=calculate(n,n,price);
        cout<<"your answer is "<<maxprice<<endl;
        cout<<endl;
    }
    return 0;
}
