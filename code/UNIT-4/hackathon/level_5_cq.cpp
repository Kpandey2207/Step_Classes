#include <bits/stdc++.h>
using namespace std;

int main(){
    int C, n;
    cin>>C>>n;
    vector<int> buffer(C);
    int front=0;
    int curr=0;
    int overwrite=0;
    while(n--){
        string op;
        int id;
        cin>>op>>id;
        int rear=(front+curr)%C;
        buffer[rear]=id;
        if(curr<C)
            curr++;
        else{
            front=(front+1)%C;
            overwrite++;
        }
    }
    cout<<"Buffer: ";
    for(int i=0;i<curr;i++){
        int idx=(front+i)%C;
        cout<<buffer[idx]<<" ";
    }
    cout<<"\nOverwrite Count: "<<overwrite<<endl;
}