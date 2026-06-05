#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,window;
    cin>>n>>window;

    vector<int>a(n);

    // Input array
    for(auto &x:a)
        cin>>x;

    // Deques store indices, not values
    deque<int>maxdq;   // Monotonically decreasing -> front is maximum
    deque<int>mindq;   // Monotonically increasing -> front is minimum

    vector<int>maxima;
    vector<int>minima;

    for(int i=0;i<n;i++){

        /* ---------- MAXIMUM DEQUE ---------- */

        // Remove indices outside current window
        while(!maxdq.empty() && maxdq.front()<=i-window)
            maxdq.pop_front();

        // Remove smaller elements from the back
        while(!maxdq.empty() && a[maxdq.back()]<=a[i])
            maxdq.pop_back();

        maxdq.push_back(i);

        /* ---------- MINIMUM DEQUE ---------- */

        // Remove indices outside current window
        while(!mindq.empty() && mindq.front()<=i-window)
            mindq.pop_front();

        // Remove larger elements from the back
        while(!mindq.empty() && a[mindq.back()]>=a[i])
            mindq.pop_back();

        mindq.push_back(i);

        /* ---------- WINDOW COMPLETE ---------- */

        if(i>=window-1){
            maxima.push_back(a[maxdq.front()]);
            minima.push_back(a[mindq.front()]);
        }
    }

    cout<<"Window Maxima: ";
    for(int x:maxima)
        cout<<x<<" ";

    cout<<"\nWindow Minima: ";
    for(int x:minima)
        cout<<x<<" ";

    int maxSpread=0;

    for(int i=0;i<maxima.size();i++){
        int spread=maxima[i]-minima[i];
        maxSpread=max(maxSpread,spread);
    }

    cout<<"\nMax Spread: "<<maxSpread<<"\n";

    return 0;
}