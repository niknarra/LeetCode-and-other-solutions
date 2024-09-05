class Solution:
    def rowWithMax1s(self, arr):
        # code here
        max_index = -1  
        curr_max = 0

        for i in range(len(arr)):
            low, high = 0, len(arr[0]) - 1

            while low <= high:
                mid = (low + high) // 2

                if arr[i][mid] == 1:
                    high = mid - 1
                else:
                    low = mid + 1

            num_of_1s = len(arr[0]) - low

            if num_of_1s > curr_max:
                curr_max = num_of_1s
                max_index = i

        return max_index

