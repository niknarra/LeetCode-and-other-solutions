class Solution{
	function max1s(vector<vector<int>> &arr){ 

       int max_index = -1;  // To handle the case when no 1 is found in any row
        int curr_max = 0;    // Initialize the maximum number of 1's found so far

        for (int i = 0; i < arr.size(); i++) {
            int low = 0;
            int high = arr[i].size() - 1;
            
            // Binary search to find the first occurrence of 1 in the row
            while (low <= high) {
                int mid = (low + high) / 2;

                if (arr[i][mid] == 1) {
                    high = mid - 1;  // Move left to find the first 1
                } else {
                    low = mid + 1;   // Move right since we're looking for 1
                }
            }

            int num_of_1s = arr[i].size() - low; // Number of 1s in the current row

            if (low < arr[i].size() && num_of_1s > curr_max) {
                curr_max = num_of_1s;
                max_index = i;
            }
        }

        return max_index;
		}
	}
}
