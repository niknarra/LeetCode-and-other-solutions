// Variable Size Sliding Window example function

int varSizeWindow(vector<int> arr, int threshold){
    int n = arr.size();
    int left = 0;
    int right = 0;
    int max_len = INT_MIN;
    int curr_len = 0;
    int total_weight = 0;
    
    while(right<n){
        total_weight += arr[right];
        
        if(total_weight <= threshold){
            curr_len += 1;
            if(curr_len>max_len){
                max_len = curr_len;
            }
        }
        else{
            total_weight -= arr[left];
            left += 1;
        }
        right += 1;
    }
    return max_len;
}

