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
