// recursive way to check palindrome // not optimal
// Time complexity: O(n), Auxiliary Space: O(n), For recursion stack

//NOTE: STR IS PALINDROME IF reverse(str) == str

bool solve(string s, int l, int r){
    
    if(l >= r) return 1;
    if(s[i] == s[n]){
        return solve(s, l+1, r-1);
    }else{
        return 0;
    }
}
int isPalindrome(string S)
{
    
    if(S.size() <= 1) return 1;
    int n = S.size()-1;
    return solve(S, 0, n);

}

// better aproach : O(n) and space O(n) due to temp string
int isPalindrome(string s)
{
	    string t = s;
	    reverse(s.begin(), s.end());
	    if(s == t) return 1;
	    else return 0;
	    
}

// optimal aproach : iterative way to check palindrome
// O(N), no extra space req
int isPalindrome(string S)
{
    if(S.size() <= 1) return 1;
    int n = S.size()-1;
    int i = 0;
    while(i < n){
        if(S[i] == S[n]){
            i++;
            n--;
        }else{
            return 0;
        }
    } 
    return 1;
    
}
