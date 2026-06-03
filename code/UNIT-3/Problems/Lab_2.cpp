#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>link(n);
    vector<int>xor(n);
    for(auto &x:link){
        cin>>x;
        
    }
    cout<<endl;

    cout<<"Forward Links: "<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Backward Links: "<<endl;
    for(auto &x:link) 
        cout<<x<<" ";
    cout<<endl;


}