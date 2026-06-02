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
    for(int i=0;i<primes.size();i++){
        if(primes[i]!=p && primes[i]%p==0)
            primes[i]=0;
    }
    return primes;
}

int main(){
    int n;
    cin>>n;
    vector<int>primes;
    for(int i=2;i<=n;i++){
        primes.push_back(i);
    }
    for(int i=2;i*i<=n;i++){
        if(primes[i-2]!=0)
            primes=remove(primes,i);
    }
    for(int i=0;i<primes.size();i++){
        if(primes[i]!=0)
            cout<<primes[i]<<" ";
    }
    return 0;
}