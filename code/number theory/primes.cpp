#include <bits/stdc++.h>
using namespace std;
// if sqrt is prime
// complexity O(sqrt(N))
bool isPrime(long long n){
    if (n == 1) return false;
    if (n == 2 || n == 3) return true;
    long long sq = sqrt(n);
    for (long long i = 2; i <= sq; i++){
        if(n % i == 0) return false;
    }
    return true;
}

// complexity O(N * ln(ln(N)))
// proof 
/*

For 2, we have to cross out n/2 numbers.
For 3, we have to cross out n/3 numbers.
For 5, we have to cross out n/5 numbers.
...etc for each prime less than n.

This means that the time complexity of "crossing out" is O(n/2 + n/3 + n/5 + ... + n/(last prime before n)).

What can this sum be simplified to in terms of n?

Well, for starters, we can factor out the n:

O(n/2 + n/3 + n/5 + ... + n/(last prime before n))
= O(n) * O(1/2 + 1/3 + 1/5 + ... + 1/(last prime before n))

What can O(1/2 + 1/3 + 1/5 + ... + 1/(last prime before n)) be simplified to in terms of n?
O(n) * O(1/2 + 1/3 + 1/5 + ... + 1/(last prime before n))
= O(n) * O(log(log(n)))
= O(nlog(log(n)))


*/

#define SIZE 1000010
bool prime[SIZE];
void seive(long long n){
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for(long long p = 2; p * p <= n ; p++){
        if (prime[p]){
            // basically all multiples of a prime number are not prime. so if p = 2
            // then set 2 + 2, 2+2+2, .. so on as not prime.
            for(long long i = p * p ; i <= n ; i += p){ // why start from p *p  not from p + p because when p = 2
                prime[i] = 0;                           // it automatically sets all of its mutiples to not prime
                                                        // so if we start from p + p which is 2*p it would already be non prime no need to start from here.
            }
        }
    }
}