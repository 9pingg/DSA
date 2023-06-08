#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7
#define INF 1e18
// #define int long long

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// highest common factor
/*
gcd(a,b) if coprime = 1
gcd(a,1) if coprime = 1
gcd(a,0) if coprime = a
*/


// O(min(a,b)) trivial approach
int gcd_basic_0(int a, int b){
    int gcd = 1;
    if (a == 0) return b;
    if (b == 0) return a;
    for(int i = 1; i < min(a,b) ; i++){
        if ((a % i == 0) && (b % i == 0)) {
            gcd = i;
        }
 
    }
    return gcd;
}
// but gcd is the highest common factor so it makes sense to start from min(a,b) rather than 1
// still here the hworst case complexity is O(min(a,b))
int gcd_basic_1(int a, int b){
    int gcd = 1;
    if (a == 0) return b;
    if (b == 0) return a;
    for(int i = min(a,b); i >= 1 ; i--){
        if ((a % i == 0) && (b % i == 0)) {
            gcd = i;
            break;
        }
    }
    return gcd;
}

// but theres a better approach calc gcd using euclidean algorithm
// gcd(a,b) = gcd(a-b,b) if a > b
// or u could directly go to gcd(a,b) = gcd(a%b, b)

// iterative O(log(min(a,b)))
// ITR ONLY WORKS if a >0 and b > 0
int gcd_itr(int a, int b){
    while(a > 0 && b > 0){
        if (a > b) a = a % b;
        else b = b % a;
    }
    if(a == 0) return b;
    return a;
}

// recursive O(log(min(a,b)))

// int gcd(int a, int b){
//     if (a == 0) return b;
//     if (b == 0) return a;
//     if(a > b) return gcd(a%b, b)
//     else return gcd(a, b%a)
// }

// more clear solution 
// works for all values 
int gcd(int a, int b){
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(b, a%b); // we know b is bigger than a%b so b is the new a. generally a > b 
}

// Extended euclidean algo to get : ax + by = gcd(a, b)
// to get integral soln of x and y given a, b

struct result{
    int x;
    int y;
    int gcd;
};
result extended_euclidean(int a, int b){
    if (b == 0){
        result res;
        res.x = 1;
        res.y = 0;
        res.gcd = a;
        return res;
    }
    // x = y1
    // y = x1 - int(a/b) * b (theory)
    result res_1 = extended_euclidean(b, a%b);
    result res;
    res.x = res_1.y;
    res.y = res_1.x - floor(a/b) * res_1.y;
    res.gcd = res_1.gcd;
    return res;
}


// A Linear Diophantine Equation (in two variables) is an equation of the general form: ax + by = c
// goal to get integral values of x and y which satisfy the eqn.
/*
In this article, we consider several classical problems on these equations:

finding one solution
finding all solutions
finding the number of solutions and the solutions themselves in a given interval

Now for a solution to exist gcd(a,b) must be a factor of c. so c = K * gcd(a,b)

*/
// this gives only one soln 
// for multiple soln (x - t * b/g), (y + t*a/g) where t is any integer
result diophantine_eqn_one_soln(int a, int b, int c){
    int gcd = gcd_itr(a, b);
    if (c % gcd == 0) {
        int k = c / gcd;
        // ax + by = K * gcd(a,b)
        // a/K x + b/K y = g
        // a x' + b y' = g
        //  x' = x / k, y' = y / k  
        // x' * k = x
        result r = extended_euclidean(a, b);
        r.x = r.x * k;
        r.y = r.y * k;
        return r;
    }
    return {1,1,1}; // no soln
}


int main() {
    fastIO();
    // result r = extended_euclidean(5,3);
    // cout << r.x << " " << r.y << " " << r.gcd << "\n";

    result r = diophantine_eqn_one_soln(3, 6, 7);
    cout << r.x << " " << r.y << " " << r.gcd << "\n";
    return 0;
}