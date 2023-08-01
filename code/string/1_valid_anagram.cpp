/*
s is an anagram of t if we can arrange s to make t
*/

// o(n + 26) uses one count array
bool isAnagram(string s, string t) {
    int count[26] = {0};
    if(s.size() != t.size()) return false;
    for(int i = 0 ; i < s.size() ; i++){
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for(int i : count){
        if(i != 0) return false;
    }
    return true;

}