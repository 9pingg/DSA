/*
Time Complexity: O((f^2) * e)
Space Complexity: O(f * e)
gives tle beacuse of linear search 
*/
/*
We are given with the number of eggs and the number of floors in the building

We have to find the minimum number of attempts to find the critical floor with the given number of eggs (we can have leftover eggs)

If we have only one egg then there is only strategy to keep dropping eggs starting from the bottom till we get to a floor where the egg breaks then we found the critical floor which will be the floor below it

We do not have any facts on where from dropping from a particular floor wheather the egg breaks or not, for every floor the egg may or may not break

We have to find the niminum number of attemps it would take to find the threshold floor in the worst case

What would be best case? We select any floor and drop the egg from it and it does not break and we drop the egg from the floor above it and it does break, then our previous floor will be the critical floor. So in the best case it would take us two attempts and 1 egg to find the critical floor.

Why just testing for in the middle and halving the floor is not necerrily a good solution? Becuase if you have only one egg left then you would have had to make as many attempts as there are floors to find the critical floor.

What we are doing here? Our function returns the minimum number of attempts required to find the critical floor with E eggs and F floor (given in arguments), we dont what would the most optiomal floor to make the first attempt from so we are making attempt from every floor, we also dont know if by dropping from a floor wheather the egg would break or not so we test for both the cases, we recursively call the function for the left over floor and eggs, since we assume the worst possible case here and we do not know if from dropping from a floor wheather the egg will break or not, we check for which situation it would take greater number of attempts to find the critical floor and take that one.

Also since we want the minimum number of attempts to find the critical floor in the worst possible case we take the minimum of the number of attempts required in the worst possible case when the first attempt is made from that fllor and return that as our answer.


Under standing base cases,

When there is only one egg then we would have to make as many attempts are there are floors in the worst case to find the critical floor.

When there is only one floor then we would have to make only one attempt if the egg does not break then its the critical floor and if it does then ground floor is the critical floor, so the number of attempts in this case also would be as many as there are floors.


When we have no eggs then its not possible to find the critical floor.

Wehn there are no floors i.e. 0 floors then the group floor will be the critical floor so the answer would be equal to 0 i.e. number of floors.
*/
int dp[105][10005];
int solve(int e, int f){
    if(f == 0) return 0; 
    if(f == 1) return 1;
    if(e == 1) return f;
    if(dp[e][f] != -1) return dp[e][f];
    int ans = INT_MAX;
    for(int k = 1 ; k <= f ; k++){
        int temp = 1 + max(solve(e-1, k-1), solve(e, f-k));
        ans = min(ans, temp);
    }
    return dp[e][f] = ans;
}
int superEggDrop(int k, int n) {
    memset(dp, -1, sizeof(dp));
    return solve(k , n);
}
/*
If left is less than right which mean if we go right we get more number of  
moves in worst case which is the ultimate goal, so reduce the problem in half because
we want max number of moves in worst case so I go to right only using this:
l = mid+1; otherwise the right < left which means I need to go left to maximize it, which is right = mid-1;

Time Complexity: O((n * k) * logn )
Space Complexity: O(n * k)

*/

int dp[105][10005];
int solve(int e, int f){
    if(f == 0) return 0; 
    if(f == 1) return 1;
    if(e == 1) return f;
    if(dp[e][f] != -1) return dp[e][f];
    int ans = INT_MAX;
    int l = 1;
    int r = f;
    while(l <= r){
        int k = (l+r)/2; // k here is mid
        int left = solve(e-1, k-1); //egg broken check for down floors of mid
        int right = solve(e, f-k); // not broken check for up floors of mid
        int temp = 1 + max(left,right);  //store max of both 
        ans = min(ans, temp);
        if(left < right) {  // so more attempts in the right side, so we search for k in right
                            // since right is more than left and we need more in worst case 
            l = k +1;       // so l=mid+1 to gain more temp for worst case so check upper floors

        }else{
            r = k-1; // mid -1
        }        
    }
    return dp[e][f] = ans;
}
int superEggDrop(int k, int n) {
    memset(dp, -1, sizeof(dp));
    return solve(k , n);
}