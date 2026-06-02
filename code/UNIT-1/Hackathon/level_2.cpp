#include<bits/stdc++.h>
using namespace std;

// Min heap that keeps the "worst" product on top.
// Lower sales = worse
// If sales are equal, lexicographically larger id = worse
struct cmp{
    bool operator()(pair<int,string>& a,
                    pair<int,string>& b){
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }
};

int main(){
    int n;
    cin>>n;

    vector<pair<string,int>> ans;

    // Heap stores {sales,id}
    // Top of heap = worst product among current top-k
    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        cmp
    > pq;

    vector<pair<string,int>> input;

    // Store all products
    for(int i=0;i<n;i++){
        string id;
        int sales;
        cin>>id>>sales;
        input.push_back({id,sales});
    }

    int k;
    cin>>k;

    // Maintain only the top k products
    for(auto &x:input){

        pair<int,string> curr={x.second,x.first};

        // Heap not full yet
        if(pq.size()<k){
            pq.push(curr);
        }

        // Current product is better than
        // the worst product in top-k
        else if(curr.first>pq.top().first ||
               (curr.first==pq.top().first &&
                curr.second<pq.top().second)){

            pq.pop();      // Remove current worst
            pq.push(curr); // Insert better product
        }
    }

    // Extract remaining top k products
    while(!pq.empty()){
        ans.push_back({pq.top().second,pq.top().first});
        pq.pop();
    }

    // Final ranking:
    // Higher sales first
    // If tie, smaller id first
    sort(ans.begin(),ans.end(),[](auto &a,auto &b){
        if(a.second!=b.second)
            return a.second>b.second;
        return a.first<b.first;
    });

    for(auto &x:ans)
        cout<<x.first<<" "<<x.second<<endl;
}