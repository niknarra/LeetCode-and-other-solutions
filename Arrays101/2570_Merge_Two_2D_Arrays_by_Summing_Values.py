# Sorting Approach - O(n log n)
class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        counts = {}

        for num in nums1:
            idx,val = num[0], num[1]
            counts[idx] = counts.get(idx, 0) + val
        
        for num in nums2:
            idx,val = num[0], num[1]
            counts[idx] = counts.get(idx, 0) + val
        
        res = [ [key, val] for key, val in counts.items() ]
        
        return sorted(res)
            
# Optimal Approach - O(n)
class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        ptr1 = 0
        ptr2 = 0
        res = []

        print(len(nums1), len(nums2))

        while ptr1 < len(nums1) and ptr2 < len(nums2):
            if nums1[ptr1][0] == nums2[ptr2][0]:
                res.append([nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]])
                ptr1 += 1
                ptr2 += 1

            elif nums1[ptr1][0] < nums2[ptr2][0]:
                res.append([nums1[ptr1][0], nums1[ptr1][1]])
                ptr1 += 1
            
            else:
                res.append([nums2[ptr2][0], nums2[ptr2][1]])
                ptr2 += 1
        
        print(ptr1, ptr2)

        res.extend(nums1[ptr1:])
        res.extend(nums2[ptr2:])
        
        return res
            

