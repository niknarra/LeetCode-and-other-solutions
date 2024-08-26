class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        ans = [-1,-1]
        
        low = 0
        high = len(nums) - 1
        
        while low <= high:
            mid = (low+high)//2
            
            if nums[mid] == target:
                if mid == 0 or nums[mid - 1] != target:
                    ans[0] = mid
                    break
                else:
                    high = mid - 1
                
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
                
        if ans[0] == -1:
            return ans
        
        low, high = ans[0], len(nums) - 1  
        
        while low <= high:
            mid = (low+high)//2
            
            if nums[mid] == target:
                if mid == len(nums) - 1 or nums[mid + 1] != target:
                    ans[1] = mid
                    break
                else:
                    low = mid + 1
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        
        return ans
        
