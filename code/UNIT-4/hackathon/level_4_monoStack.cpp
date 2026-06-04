#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    stack<int> stack;
    vector<int> store(n);
    vector<int> result(n,0);
    for(int &x:store)
        cin>>x;

    for(int i=0;i<n;i++){
        while(!stack.empty() && store[i]>store[stack.top()]){
            result[stack.top()]=i-stack.top();
            stack.pop();
        }
        stack.push(i);
    }
    cout<<"Days to Higher: ";
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }

    return 0;
}