// Merge Sort
// Divide and Conquer Approach

// TC: O(n log n) - One of the efficient algos

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    
    vector<int> temp;
    
    int left = low;
    int right = mid + 1;
    
    while(left <= mid && right <= high){ // Comparing the two sorted arrays
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left += 1;
        }
        else{
            temp.push_back(arr[right]);
            right += 1;
        }
    }
    
    while(left <= mid){ // If there are any leftover elements from the left array
        temp.push_back(arr[left]);
        left += 1;
    }
    
    while(right <= high){ // If there are any leftover elements from the right array
        temp.push_back(arr[right]);
        right += 1;
    }
    
    for(int i =low;i<=high;i+=1){ // Replace the elements in actual arr with elements from temp
        arr[i] = temp[i - low]; // i-low bc temp indexing is from 0, and we're replacing elements in arr in their resp position
    }
    
}

void mergeSort(vector<int> &arr, int low, int high){
    if(low < high){  // Base Case (continue only if low < high)
        int mid = (low + high) / 2;
        
        mergeSort(arr, low, mid);   // Sort the left half
        mergeSort(arr, mid + 1, high); // Sort the right half
       
	merge(arr, low, mid, high); // Merge the sorted halves
    }
}    
    
int main() {    
    vector<int> arr = {1,6,9,3,5,2,8,7,4};
    int low = 0;
    int high = arr.size()-1;
    
    arr = mergeSort(arr,low,high);
    
    for(int i=0;i<arr.size();i+=1){
        cout<<arr[i]<<endl;
    }

    return 0;
}

