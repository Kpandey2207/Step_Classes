#include <bit/stdc++.h>
using namespace std;

long long mod_exp(long long b,long long e,long long m){
    long long answer=1;
    b%=m;
    while(e>0){
        if(e&1)
            answer=(answer*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return answer;
}

int main(){
    int b,e,m;
    cin>>b>>e>>m;
    long long answer=mod_exp(b,e,m);
    cout<<answer;
    return 0;
}