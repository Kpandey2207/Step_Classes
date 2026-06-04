/*
2 Stack = 1 Queue
*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    stack<int> s1,s2;
    int n;
    cin>>n;
    string input;
    while(n--){
        cin>>input;
        if(input=="ENQUEUE"){
            int num;
            cin>>num;
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(num);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if(input=="DEQUEUE"){
            if(!s1.empty()){
                cout<<s1.top()<<endl;
                s1.pop();
            }
            else
                cout<<"Queue is empty\n";
        }
        else
            cout<<"Invalid operation\n";
    }
    return 0;
}