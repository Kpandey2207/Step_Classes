/*
Knuth-Morris-Pratt Algorithm Implementation in C++
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string p){
    int m=p.size();
    vector<int> lps(m,0);

    int len=0;
    int i=1;

    while(i<m){
        if(p[i]==p[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }

    return lps;
}

bool KMP(string s,string p){
    int n=s.size(),m=p.size();

    vector<int> lps=buildLPS(p);

    int i=0,j=0;

    while(i<n){

        if(s[i]==p[j]){
            i++;
            j++;
        }

        if(j==m)
            return true;

        else if(i<n && s[i]!=p[j]){

            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }

    return false;
}

int main(){
    string s,p;
    cin>>s>>p;
    bool found=KMP(s,p);
    if(found)
        cout<<"TRUE\n";
    else
        cout<<"FALSE\n";
    return 0;
}