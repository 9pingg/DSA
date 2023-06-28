// brute force we can sort the array and return arr[k-1] where k = 2  if second largest is asked
// here 3rd largest is asked so we maintain f,s and t. 
// we need both first and second largest, to check for third largest.
// if asked for nth largest we take n variables

// now coming to the if blocks: 3rd largest so 3 if blocks each calc k largest where k = 1, 2, 3
// now if we change something for first largest, then its prev value would go to second largest, and the second largest's value would go to third largest
// similarly if we change only the second largest, its prev value would go to third largest.

// optimal : O(n)
int thirdLargest(int a[], int n)
    {
        int f = INT_MIN;
        int s = INT_MIN;
        int t = INT_MIN;
        if(n < 3) return -1;
        for(int i = 0; i < n ; i++){
        if(f < a[i]){
            int temp = f;
            int temp1 = s;
            f = a[i];
            s = temp;
            t = temp1;
        }
        else if(s < a[i]){
            int temp = s;
            s = a[i];
            t = temp;
        }else if(t < a[i]){
            t = a[i];
        }
        // cout << i << " " << f << " " << s << " " << t << endl;
        }
    return t;
}

int getFourthLargest(int a[], int n)
{
    if(n < 4) return INT_MIN;
    int f = INT_MIN;
    int s = INT_MIN;
    int t = INT_MIN;
    int res = INT_MIN; //fourth largest

    for(int i = 0 ; i < n ; i++){
        if(a[i] > f){
            int temp1 = f;
            int temp2 = s;
            int temp3 = t;
            f = a[i];
            s = temp1;
            t = temp2;
            res = temp3;
        }
        else if(a[i] > s){
            int temp1 = s;
            int temp2 = t;
            s = a[i];
            t = temp1;
            res = temp2;
        }
        else if(a[i] > t){
            int temp1 = t;
            t = a[i];
            res = temp1;
        }
        else if(a[i] > res){
            res = a[i];
        }
    }
    return res;
}