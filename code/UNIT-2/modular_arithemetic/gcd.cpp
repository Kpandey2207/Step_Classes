/*
Euclid's algorithm is an efficient method for computing the 
greatest common divisor (GCD) of two integers. The algorithm is 
based on the principle that the GCD of two numbers also divides 
their difference.
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}