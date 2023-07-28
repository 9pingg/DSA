// o(m+n) s: o(1)
void merge(vector<int>& n1, int n, vector<int>& n2, int m) {
    // this question cant be solved if space isnt used if we start iterating from n1 from the start 
    // but if we iterate from the end, then it works

    int i = n-1;
    int j = m-1;
    int k = n+m-1;
    while(i >= 0 && j >= 0){
        if(n1[i] < n2[j]){
            n1[k--] = n2[j--];
        }else{
            n1[k--] = n1[i--];
        }
    }
    while(i >= 0){
        n1[k--] = n1[i--];
    }
    while(j >= 0){
        n1[k--] = n2[j--];
    }
}