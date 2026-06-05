#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;

    deque<char>dq;

    for(char c:str)
        dq.push_back(c);

    int mismatches=0;

    while(dq.size()>1) {
        char a = dq.front();
        char b = dq.back();
        dq.pop_front();
        dq.pop_back();
        if(a!=b)
            mismatches++;
    }
    cout << "Palindrome: "<< (mismatches == 0 ? "Yes" : "No") << "\n";
    cout << "Mismatched Pairs: "<< mismatches << "\n";
    return 0;
}