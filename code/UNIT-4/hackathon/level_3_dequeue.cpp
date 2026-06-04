#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    int n,window;
    cin>>n>>window;
    vector<int> store(n);
    for(int &x:store)
        cin>>x;

    cout<<"Window Maxima: ";
    for(int i=0;i<n;i++){
        // Remove indices that are out of the current window
        while(!dq.empty() && dq.front()<=i-window)
            dq.pop_front();

        // Maintain decreasing order of values
        while(!dq.empty() && store[dq.back()]<=store[i])
            dq.pop_back();
        dq.push_back(i);
        if(i>=window-1)
            cout<<store[dq.front()]<<" ";
    }
    cout<<endl;
    return 0;
}