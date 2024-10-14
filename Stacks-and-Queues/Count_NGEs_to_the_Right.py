# Approach 1 - Without Stacks
# TC - O(N * Q)

class Solution:
    
    def getNGEs(self, arr, index):
        st = []
        count = 0
        
        for i in range(len(arr)-1, index-1,-1):
            if arr[i] > arr[index]:
                count += 1
        
        return count
        
    
    def count_NGEs(self, N, arr, queries, indices):
        # Code here
        ans = []
        
        for index in indices:
            ans.append(self.getNGEs(arr, index))
        
        return ans

# Approach 2 - With Stack
# TC - O(N + Q)

class Solution:
    def count_NGEs(self, N, arr, queries, indices):
        # Code here
        
        nge_counts = [0] * N
        
        # Stack to store indices of elements
        st = []
        
        # Iterate over the array from right to left
        for i in range(N-1, -1, -1):
            # Pop elements from the stack that are smaller than the current element
            while st and arr[st[-1]] <= arr[i]:
                st.pop()
                
            # The number of elements greater than arr[i] to its right
            nge_counts[i] = len(st)
            
            # Push the current element index to the stack
            st.append(i)
        
        # Answer the queries based on the precomputed nge_counts
        ans = []
        for index in indices:
            ans.append(nge_counts[index])
        
        return ans

