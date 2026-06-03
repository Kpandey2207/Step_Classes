// Lab 3 - Array Analytics: Maximum Subarray + Equilibrium Index
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This function contains a BUG. Find it and fix it.
long long maxSubarraySum(const vector<long long>& a) {
    long long best = a[0], cur = a[0];
    for (int i = 1; i < a.size(); i++){
        cur = max(a[i], cur + a[i]);
        best = max(best, cur);
    }
    return best;
}
// TODO: Implement this function from scratch.
// Return the first index where the sum to its left equals the sum to its
// right (excluding the index), or -1.
vector<long long> prefixSum(const vector<long long>& a){
    int n=a.size();
    vector<long long> prefix(n+1);
    prefix[0]=0;
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+a[i];
    }
    return prefix;
}
int equilibriumIndex(const vector<long long>& a){
    int n=a.size();

    vector<long long> prefix=prefixSum(a);

    for(int i=0;i<n;i++){
        long long left=prefix[i];
        long long right=prefix[n]-prefix[i+1];

        if(left==right)
            return i;
    }

    return -1;
}
int main() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "Max Subarray Sum: " << maxSubarraySum(a) << "\n";
    cout << "Equilibrium Index: " << equilibriumIndex(a) << "\n";
    return 0;
}