#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> cat;
    int m,k;
    cin>>m;

    for(int i=0;i<m;i++){
        string s;
        int p;
        cin>>s>>p;
        cat[s]=p;
    }

    cin>>k;
    long long CartTotal=0;

    for(int i=0;i<k;i++){
        string s;
        int qty;
        cin>>s>>qty;
        //Support cart ids that may be missing from the catalog.
        if(cat.find(s)==cat.end()){
            cout<<"Product "<<s<<" not found!"<<endl;
            continue;
        }
        CartTotal+=(long long)cat[s]*qty;
    }
    cout<<"Cart Total: "<<CartTotal<<endl;
    return 0;
}