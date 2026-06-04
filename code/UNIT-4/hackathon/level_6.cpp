#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,quantum;
    cin>>n>>quantum;

    vector<int> remaining(n+1);
    queue<int> q;

    for(int i=1;i<=n;i++){
        cin>>remaining[i];
        q.push(i);
    }

    vector<int> completion;
    int turns=0;

    while(!q.empty()){
        int id=q.front();
        q.pop();

        int run=min(remaining[id],quantum);
        remaining[id]-=run;
        turns++;

        if(remaining[id]==0)
            completion.push_back(id);
        else
            q.push(id);
    }

    cout<<"Completion Order: ";

    for(int x:completion)
        cout<<x<<" ";

    cout<<endl;
    cout<<"Turns: "<<turns<<endl;

    return 0;
}