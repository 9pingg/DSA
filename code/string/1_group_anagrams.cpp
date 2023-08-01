// basically a list of strings is given, we have to put strings which have the same char (with same freq), in one list.

// brute force: to find strings which same char and freq, just sort the string put in map.
// n = number of strings
// k = max length of a string
// t : o(n * k * log(k))
vector<vector<string>> groupAnagrams(vector<string>& strs) {        
    unordered_map<string, vector<string>> m;
    for(string s : strs){
        string t = s;
        sort(t.begin(), t.end());
        m[t].push_back(s);
    }
    vector<vector<string>> res;
    for(auto i : m){
        res.push_back(i.second);
    }
    return res;
}

// this can be improved as basic sorting takes k * log(k), we can use counting sort which only takes (2 * k)

/*
Counting sort is a sorting algorithm that sorts the elements of an array by counting the number 
of occurrences of each unique element in the array
*/

// note the input arr only has lower case letters. so are count arr has a size of 26.
void countsort(string &s){
    // make a count array
    int count[26] = {0};
    for(char c : s){
        count[c-'a']++;
    }
    int index = 0;
    for(int i = 0 ; i < 26 ; i++){
        while(count[i]--){
            s[index++] = 'a' + i;
        }
    }   
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {        
    unordered_map<string, vector<string>> m;
    for(string s : strs){
        string t = s;
        countsort(t);
        m[t].push_back(s);
    }
    vector<vector<string>> res;
    for(auto i : m){
        res.push_back(i.second);
    }
    return res;
}




