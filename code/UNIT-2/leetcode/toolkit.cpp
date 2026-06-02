/*
Sieve of Eratosthenes is an efficient algorithm for finding all prime numbers 
up to N. It works by iteratively marking the multiples of each prime 
starting from 2. The numbers which remain unmarked after all multiples
of each prime have been marked are the prime numbers.
*/


#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<=1)
        return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

vector<int> remove(vector<int>& primes, int p){
    for(int i=2*p;i<primes.size();i+=p){
            primes[i]=0;
    }
    return primes;
}

int gcd(int a, int b){
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}

int main(){
    int n,b,mod;
    cin>>n>>b>>mod;

    if(isPrime(n))
        cout<<n<<" is prime."<<endl;
    else
        cout<<n<<" is not prime."<<endl;

    cout<<"GCD: "<<gcd(n,b)<<endl;

    cout<<"LCM: "<<(n*b)/gcd(n,b)<<endl;


    vector<int>primes(n+1);
    for(int i=2;i<=n;i++){
        primes[i]=i;
    }
    for(int i=2;i*i<=n;i++){
        if(primes[i]!=0)
            primes=remove(primes,i);
    }
    for(int i=2;i<=n;i++){
        if(primes[i]!=0)
            cout<<primes[i]<<" ";
    }

    cout<<"(a*b) mod m: "<<((long long)n*b)%mod<<endl;
    cout<<"(a+b) mod m: "<<((long long)n+b)%mod<<endl;

    return 0;
}