#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> minStack;
    stack<int> mainStack;
    int n;
    cin>>n;
    while(n--){
        string input;
        cin>>input;
        
        if(input=="PUSH"){
            int num;
            cin>>num;
            mainStack.push(num);
            minStack.push(min(num,minStack.empty() ? num : minStack.top()));
        }
        else if(input=="POP"){
            if(mainStack.empty() && minStack.empty())
                cout<<"Stack is empty\n";
            else{
                mainStack.pop();
                minStack.pop();
            }
        }
        else if(input=="MIN"){
            if(minStack.empty())
                cout<<"Stack is empty\n";
            else
                cout<<"Min: "<<minStack.top()<<endl;
        }
        else
            cout<<"Invalid operation\n";
    }
    cout<<"Size: "<<mainStack.size()<<endl;
    return 0;
}
