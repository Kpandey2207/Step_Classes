#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,B;
    cin>>n>>B;

    vector<long long> dp(B+1,0);

    for(int i=0;i<n;i++){
        int cost;
        long long value;

        cin>>cost>>value;

        // Process budgets backwards
        for(int j=B;j>=cost;j--){
            dp[j]=max(dp[j],dp[j-cost]+value);
        }
    }

    cout<<"Max Delight: "<<dp[B]<<endl;

    return 0;
}