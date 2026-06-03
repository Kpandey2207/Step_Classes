/*
INPUT: 'ABABABC'
PATTERN: 'ABABC'
OUTPUT: TRUE
*/
#include <bits/stdc++.h>
using namespace std;

bool check(string s, string p){
    int n=s.size(), m=p.size();
    for(int i=0;i<=n;i++){
        if(i+m>n)
            break;
        string sub=s.substr(i,m);
        if(sub==p)
            return true;
    }
    return false;
}

int main(){
    string s,p;
    cin>>s>>p;
    bool found=check(s,p);
    if(found)
        cout<<"TRUE\n";
    else
        cout<<"FALSE\n";
    return 0;
}