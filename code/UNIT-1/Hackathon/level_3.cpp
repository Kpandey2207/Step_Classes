#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> revenue(n);

    // Read daily revenues
    for(int i=0;i<n;i++)
        cin>>revenue[i];

    long long T;
    cin>>T;

    int left=0;
    int ans=INT_MAX;
    long long sum=0;

    for(int right=0;right<n;right++){

        // Expand window
        sum+=revenue[right];

        // Window reached target
        while(sum>=T){

            // Update shortest valid window length
            ans=min(ans,right-left+1);

            // Shortest possible answer
            if(ans==1){
                cout<<"Shortest Window: 1"<<endl;
                return 0;
            }

            // Shrink window from left
            sum-=revenue[left];
            left++;
        }
    }

    // No valid window found
    if(ans==INT_MAX)
        cout<<"Shortest Window: 0"<<endl;
    else
        cout<<"Shortest Window: "<<ans<<endl;

    return 0;
}