#include <bits/stdc++.h>
using namespace std;


int nCr(int n, int r){
    if(n==r || r==0)
    return 1;
    else
    return nCr(n-1, r-1)+nCr(n-1,r);
}
int nPr(int n,int r){
    if(r==0)
    return 1;
    else
    return n*nPr(n-1, r-1);
}
int subset(int n){
    if(n==0)
    return 1;
    else
    return 2*subset(n-1);
}
int main() {
	int n,r;
	cin>>n>>r;
	
	int Combo=nCr(n,r);
	int Perm=nPr(n,r);
	int sub=subset(n);
	
	cout<<"\nCombination: "<<Combo<<"\nPermutation: "<<Perm<<"\nSubset: "<<sub;
	return 0;
}
