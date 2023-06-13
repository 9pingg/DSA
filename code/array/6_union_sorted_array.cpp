
// O(N+M)
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> res;
       
        int prev = -1;
        int i = 0, j = 0;
        while(n>i && m>j){
            if(arr1[i] < arr2[j] && prev!=arr1[i]) {
                prev = arr1[i];
                // cout << "add 1 " << arr1[i] << endl;               
                res.push_back(arr1[i++]);
               
                while(i< n){
                    if(arr1[i-1] == arr1[i]) i++;
                    else break;
                }
            }
            else if(arr1[i] > arr2[j] && prev!=arr2[j]){
                prev = arr2[j];
                // cout << "add 2 " << arr2[j] << endl;
                res.push_back(arr2[j++]);
                 while(j < m){
                    if(arr2[j-1] == arr2[j]) j++;
                    else break;
                }
            }
            else if(arr1[i] == arr2[j] && prev != arr1[i]){
                // cout << "add 1 and 2 " << arr2[j] << endl;
                res.push_back(arr1[i]);
                prev = arr1[i++];
                j++;
                while(j < m){
                    if(arr2[j-1] == arr2[j]) j++;
                    else break;
                }
                while(i< n){
                    if(arr1[i-1] == arr1[i]) i++;
                    else break;
                }
                // cout << "i,j" << i << j << endl;
            }
            else{
                i++;
                j++;
            }
        }
        if(i!=n){
            while(n>i){
                if(arr1[i-1] != arr1[i]) res.push_back(arr1[i++]);
                else i++;
            }
        }
        if(m!=j){
            while(m>j){
                if(arr2[j-1] != arr2[j]) res.push_back(arr2[j++]);
                else j++;
                
            }
        }
        return res;
        
    }