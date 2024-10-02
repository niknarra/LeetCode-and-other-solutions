// Binary Search
// Yet another Divide and Conquer Approach

// TC: O(log n)

#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> arr, int key){
	
	int low = 0;
	int high = arr.size()-1;
	
	while(low<=high){
		
		// int mid = (low+high)/2; This summation can lead to int overflow

		int mid = low + ((high-low)/2); // This ensures no errors at runtime
		
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

// Order Agnostic BS - when we know array is sorted but order is unkown

int orderAgnosticBS(vector<int>& arr, int target){
    int start = 0;
    int end = arr.size() - 1;
    
    bool ascending = arr[start] < arr[end];
    
    while(start<=end){
        int mid = start + (end-start)/2;
        
        if(arr[mid] == target){
            return mid+1;
        }
        
        if(ascending){
            if(arr[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        else{
            if(arr[mid] < target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
    }
    return -1;
    
}

int main(){
	
	int key = 9;
	vector<int> arr = {1,2,3,4,5,6,8,9,10,11};
	
	bool ans = binarySearch(arr, key);
	
	ans ? cout<<"Key Value Found" : cout<<"Key Not Found";
	
	return 0;
}

