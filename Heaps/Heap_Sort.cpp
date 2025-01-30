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

void heapSort(vector<int>& arr){
    int n = arr.size();

    // Step 1: Build the heap -> O(n)
    for(int i = n/2-1; i>=0; i-=1){
        heapify(arr, n, i);
    }

    // Step 2: Extract and Swap current max element 'i' with the last element one by one -> O(n log n)
    for(int i=n-1;i>0;i-=1){
        swap(arr[0], arr[i]); // Move current root to the end
        heapify(arr, i, 0); // Restore heap property on reduced heap
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
