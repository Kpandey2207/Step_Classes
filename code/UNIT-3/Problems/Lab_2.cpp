#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> value(n+1);
    vector<int> link(n+1);

    for(int i=1;i<=n;i++){
        cin>>value[i];
    }

    // Build XOR links
    for(int i=1;i<=n;i++){
        int prev=i-1;
        int next=i+1;

        if(i==1)
            prev=0;

        if(i==n)
            next=0;

        link[i]=prev^next;
    }

    // Forward Traversal
    cout<<"Forward: ";

    int prev=0;
    int cur=1;

    while(cur!=0){
        cout<<value[cur]<<" ";

        int next=link[cur]^prev;
        prev=cur;
        cur=next;
    }
    cout<<endl;

    // Backward Traversal
    cout<<"Backward: ";

    prev=0;
    cur=n;

    while(cur!=0){
        cout<<value[cur]<<" ";

        int next=link[cur]^prev;
        prev=cur;
        cur=next;
    }
    cout<<endl;

    // XOR Links
    cout<<"XOR Links: ";

    for(int i=1;i<=n;i++){
        cout<<link[i]<<" ";
    }
    cout<<endl;

    return 0;
}