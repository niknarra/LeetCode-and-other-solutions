# Approach 1 - Hashing using Dictionary
# O(n)

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        ans = []
        counts = {}

        for num in nums:
            counts[num] = counts.get(num, 0) + 1
        
        for key in counts:
            if counts[key] == 2:
                ans.append(key)
        
        return ans

# Approach 2 - Using Sets
# O(n)

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        ans = []

        numbers = set()

        for num in nums:
            if num not in numbers:
                numbers.add(num)
            else:
                ans.append(num)
        
        return ans

# Approach 2.1 - Early Termination
# O(n), best case O(k) where k is the index at which second repeating element is found

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        ans = []

        numbers = set()

        for num in nums:
            if len(ans) == 2:
                return ans
            else:
                if num not in numbers:
                    numbers.add(num)
                else:
                    ans.append(num)
        
        return ans

