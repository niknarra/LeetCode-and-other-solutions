// Max Heaps

#include <bits/stdc++.h>
using namespace std;

// Heapify for maxHeap
void heapify(vector<int>& arr, int n, int index){
    int largest = index; // Assume root to be the largest initially
    
    // As per Binary Trees, Left child of a parent i in an array is 2 * i + 1
    int left = 2*index+1;
    // Similarly, Right child of a parent i in an array is 2 * i + 2
    int right = 2*index+2;
    
    // If left child > largest(root)
    if(left < n && arr[left] > arr[largest]) largest = left;
    
    // If right child > current largest
    if(right < n && arr[right] > arr[largest]) largest = right;
    
    // If root is no longer the largest, swap and recursively heapify
    if(largest != index){
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to add a new element to the heap
// O(log n)
void insert(vector<int>& arr, int val){
    arr.push_back(val); // Push the new value to the end of the heap
    
    int i = arr.size() - 1; // Get the new value's index
    
    // We will make sure max heap property remains intact from bottom-up
    while(i > 0){
        int parent = (i-1) / 2; // Get the current parent
        
        // If parent is smaller than the current value, swap
        if(arr[parent] < arr[i]){
            swap(arr[parent], arr[i]);
            i = parent;
        }
        // If not, heap property is already satisfied, no swapping needed
        else{
            break;
        }
    }
}

// Function to pop and get the root -> max Value
int popRoot(vector<int>& arr){
    // Get the size of the heap
    int n = arr.size();
    
    // If heap is empty, return -1
    if(n == 0) return -1;
    
    // Store the root
    int root = arr[0];
    
    arr[0] = arr[n-1]; // Swap the root with the last leaf node
    arr.pop_back(); // Pop the last leaf node
    
    heapify(arr, n-1, 0); // Heapify to recover heap
    
    return root; // Return the root (max Value)
}

// Function to build a heap from an arr or vector
void heapBuilder(vector<int>& arr){
    // Start with n/2-1 -> index of the last non leaf node
    // and we do it bottom-up as it's better than heapifying each element
    // from top-bottom
    for(int i=arr.size()/2-1; i>=0; i-=1){
        heapify(arr, arr.size(), i);
    }
}

int main() {
    cout << "Heaps"<<endl;
    vector<int> arr = {4, 10, 3, 5, 1};
    heapify(arr, arr.size(), 0);
    
    // Printer
    for(int i:arr){
        cout<<i<<endl;
    }
    
    

    return 0;
}
