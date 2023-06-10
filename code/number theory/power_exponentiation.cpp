// https://leetcode.com/problems/powx-n/

// trivial solution O(N)
// recursive method or iterative method which multiplies x with itself n-1 times to get the result.
double pow_helper(double x, int n){
        if (n == 1) return x;
        return x * pow(x, n-1);
    }
double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n > 0) return pow_helper(x, n);
        else return 1/ pow_helper(x, -n);
}

// Optimal solution is O(log(n))
// complexity of this algorithm is  
// O(log(n)): we have to compute  O(log(n))  powers of x , and then have to do at most  O(log(n))  multiplications to get the final answer from them.
double pow(double x, long long n){
        if (n == 0) return 1;
        if (n % 2 == 0) return pow(x*x, n/2); // n = even 
        else return x * pow(x*x, (n-1) / 2); // n = odd
    }
    double myPow(double x, int n) {
        
        if (n == 0) return 1;
        if (n > 0) return pow(x, n);
        else {
            
            return 1/ pow(x, -(long long)n); // set to long long because if n = -2^31 then cannot be converted to 2^31 it will overflow in int. so we convert type to long long.
        }
    }