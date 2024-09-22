// Binary Search
// Yet another Divide and Conquer Approach

// TC: O(log n)

#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> arr, int key){
	
	int low = 0;
	int high = arr.size()-1;
	
	while(low<=high){
		
		int mid = (low+high)/2;
		
		if(arr[mid] == key){
			return true;
		}
		else if(arr[mid] > key){
			high = mid -1;
		}
		else{
			low = mid + 1;
		}
	}
	
	return false;
}

int main(){
	
	int key = 9;
	vector<int> arr = {1,2,3,4,5,6,8,9,10,11};
	
	bool ans = binarySearch(arr, key);
	
	ans ? cout<<"Key Value Found" : cout<<"Key Not Found";
	
	return 0;
}

