#include <bits/stdc++.h>
using namespace std;

vector<int> comp(vector<int> &a){
    int  n=a.size();
    vector<int>prefix(n+1);
    prefix[0]=0;
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+a[i];
    }
    return prefix;
}

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n);
    for(auto &x:a)
    cin>>x;

    vector<int> prefix(n+1);
    prefix=comp(a);
    cout<<"SUM("<<l<<", "<<r<<") = "<<prefix[r+1]-prefix[l]<<endl;
    return 0;
}