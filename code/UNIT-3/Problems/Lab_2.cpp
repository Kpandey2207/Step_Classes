#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> value(n);
    for(int &x:value)
        cin>>x;

    cout<<"Forward: ";
    for(int x:value)
        cout<<x<<" ";
    cout<<endl;

    cout<<"Backward: ";
    for(int i=n-1;i>=0;i--)
        cout<<value[i]<<" ";
    cout<<endl;

    cout<<"XOR Links: ";
    for(int i=1;i<=n;i++){
        int prev=i-1;
        int next=i+1;
        if(i==1)
            prev=0;
        if(i==n)
            next=0;
        cout<<(prev^next)<<" ";
    }
    cout<<endl;
    return 0;
}