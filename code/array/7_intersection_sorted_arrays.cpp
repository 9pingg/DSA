#include <bits/stdc++.h> 
// o(m+n) spcace: O(1)
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> res;
	int i = 0;
	int j = 0;
	while(n > i && m > j){
		if(arr1[i] == arr2[j]){
			res.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr2[j] > arr1[i]) i++;
		else if(arr2[j] < arr1[i]) j++;
	}
	return res;
	
}