#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int>inbox,outbox;
    vector<int> served;
    int n;
    cin>>n;

    while(n--){
        string input;
        cin>>input;

        if(input=="ENQUEUE"){
            int num;
            cin>>num;
            inbox.push(num);
        }
        else if(input=="DEQUEUE"){
            if(outbox.empty()){
                while(!inbox.empty()){
                    outbox.push(inbox.top());
                    inbox.pop();
                }
            }
            if(!outbox.empty()){
                served.push_back(outbox.top());
                outbox.pop();
            }
            else
                cout<<"Queue is empty\n";
        }
        else
            cout<<"Invalid operation\n";
    }
    cout<<"Served: ";
    for(int x:served)
        cout<<x<<" ";
    cout<<endl;
    cout<<"Pending: "<<inbox.size()+outbox.size()<<endl;
    return 0;
}