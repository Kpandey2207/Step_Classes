#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int n=str.length();
    deque<char> dq;
    for(int i=0;i<n;i++)
        dq.push_back(str[i]);
    
    int count=0;
    bool flag = true;
    while(!dq.empty()){
        if(dq.front()==dq.back()){
            dq.pop_front();
            dq.pop_back();
        }
        else{
            flag=false;
            count++;
            dq.pop_back();
            dq.pop_front();
        }
    }
    if(flag)
        cout<<"Palindrome: YES\n";
    else{
        cout<<"Palindrome: NO\n";
        cout<<"Mismatched Pairs: "<<count<<"\n";
    }
    return 0;
}