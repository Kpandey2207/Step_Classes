#include <bits/stdc++.h>
using namespace std;

long long hanoi(int n){
    if(n==0)
        return 0;
    else
    return 2*hanoi(n-1)+1;
}

double myPow(double x, long long n) {
    if(n==0)
        return 1;
    if(n<0)
        return 1.0/myPow(x,-n);
        
    double half=myPow(x,n/2);

    if(n%2==0)
        return half*half;
    else 
        return half*half*x;
}

int gcd(int a, int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}

int main() {
	int n,a,b;
	cin>>n>>a>>b;
	long long moves=hanoi(n);
	double expo=myPow(a,b);
	int gcdMod=gcd(a,b);
	
	cout<<"\nHanoi: "<<moves<<"\nPower: "<<expo<<"\nGCD: "<<gcdMod<<endl;
	return 0;
}
