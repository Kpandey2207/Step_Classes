#include <bits/stdc++.h>
using namespace std;

vector<int> comp(vector<int> &a){
    int  n=a.size();
    vector<int>prefix(n);
    prefix[0]=a[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    return prefix;
}

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n);
    for(auto &x:a)
    cin>>x;
    vector<int> prefix = comp(a);

    //fails for edges case when L=0, array out of bound
    cout<<"SUM("<<l<<", "<<r<<") = "<<prefix[r]-prefix[l-1]<<endl;
    return 0;
}