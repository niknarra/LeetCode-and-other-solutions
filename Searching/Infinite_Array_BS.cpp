// Consider a sorted infinite array or an array of unknown length and we are to search for an element

// First, we need to assume the start and end points of the array to begin searching
// Let's begin by assuming the size to be 2 and then continue doubling the size until the window's end element is bigger than the target

#include <bits/stdc++.h>
using namespace std;

int findAnswer(int arr[], int target){

	int start = 0; // Initially, let's say start is the first element
	int end = 1; // And the second element is the end

	while(target > arr[end]){ // As long as the target value is bigger than our current end, 
	
		int newStart = end + 1; // We store the new start point in a temp variable
		
		end = end + (end - start + 1) * 2; // New end will be end - start + 1, the size of the currnt window + the current end index
		start = newStart; // Set start to be new start
	
	}
	
	return binarySearch(arr, target, start, end); // Pass the values to the binary search function

}

int binarySearch(int arr[], int target, int start, int end){ // Regular Binary Search

	while(start<=high){
		
		int mid = start + (end - start)/2;		
	
		if(arr[mid] == target){
		
			return mid+1;		

		}	

		if(arr[mid] > target){
			
			end = mid - 1;		

		}
		
		else{
		
			start = mid + 1;		

		}
	}

	return -1;
}


int main(){

	int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 
                               140, 160, 170};
	
	int target = 10;

	return findAnswer(arr, target);


}

