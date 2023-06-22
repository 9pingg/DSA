// same as count subarray sum as K, O(n)

// suppose a0 to a4 = prefix_xor[4] = a0^a1 .... ^a4
// now we need to find a subarray whose prefix_xor is such that when both are xorred we get K(target)
// that subarray is a0 to a2 prefix_xor[2] = a0^ .. a2
// so prefix_xor[4] ^ prefix_xor[2] = k
// (a0^a1 .... ^a4)^(a0^ .. a2)  = k
// a3^a4 = k
// we dont know prefix_xor[2] (we need to find it in the map ), but we do know k 
// solve:
/*
prefix_xor[4] ^ prefix_xor[2] = k
prefix_xor[4] ^ prefix_xor[2] ^ k = k ^ k ^ k (remove prefix_xor[2] as not known)
prefix_xor[4] ^ prefix_xor[2] ^ k ^ prefix_xor[2] = prefix_xor[2]
prefix_xor[4]^k  = prefix_xor[2] (soln)

*/
#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    unordered_map<int,int> m;
    int prefix_xor = 0;
    int count = 0;
    for(int i = 0; i < a.size() ; i++){
        prefix_xor ^= a[i];
        if(prefix_xor == b){
            count++;
        }
        if(m.count(b^prefix_xor)){ // HOW DOES THIS WORK??
            count+=m[b^prefix_xor];
        }
        m[prefix_xor]++; // should be after if statement
    }
    return count;
}