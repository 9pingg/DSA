#include <bits/stdc++.h>
int arr_g[10000000]; // max size of array which can be declared globally 10^7

/*
Find Second Smallest and Second Largest Element in an array
*/
// brute: sort the array O(n*log(n))
// better: get the largest value and itr again ignoring the largest value. O(2*n)
// optimal : 1 pass O(n)
int second_max(int n, vector<int> &a) {
    int largest = INT_MIN;
    int second_largest = INT_MIN;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] > largest){
            second_largest = largest;
            largest = a[i];
            
        }
        else if(a[i] > second_largest && a[i] != largest){ // a[i] != largest if duplicates are there like 1 9 9 9 9
            second_largest = a[i];
        }
    }
    return second_largest;
}
int second_min(int n, vector<int> &a) {
    int sm = INT_MAX;
    int second_sm = INT_MAX;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] < sm){
            second_sm = sm;
            sm = a[i];
            
        }
        else if(a[i] < second_sm && a[i] != sm){
            second_sm = a[i];
        }
    }
    return second_sm;
    
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    return vector<int> {second_max(n,a), second_min(n, a)};
}



int main(){
    int arr_l[1000000]; // max size of array which can be declared local 10^6

    return 0;
}
