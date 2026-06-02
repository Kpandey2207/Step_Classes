#include<bits/stdc++.h>
using namespace std;

long long prefixSum(vector<int>& transactions,long long K){
    long long prefix=0;
    long long count=0;

    unordered_map<long long,long long> mp;

    // Empty prefix sum
    mp[0]=1;

    for(int i=0;i<transactions.size();i++){

        // Build current prefix sum
        prefix+=transactions[i];

        // Check how many previous prefixes
        // can form a subarray with sum K
        if(mp.find(prefix-K)!=mp.end())
            count+=mp[prefix-K];

        // Store current prefix
        mp[prefix]++;
    }

    return count;
}

int main(){
    int n;
    cin>>n;

    vector<int> transactions(n);

    // Read transactions
    for(int i=0;i<n;i++)
        cin>>transactions[i];

    long long K;
    cin>>K;

    cout<<"Matching Segments: "
        <<prefixSum(transactions,K)
        <<endl;

    return 0;
}