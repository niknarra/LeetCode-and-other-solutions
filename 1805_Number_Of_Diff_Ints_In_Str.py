# Approach 1
# TC: O(n+k)

class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        nums = {'0','1','2','3','4','5','6','7','8','9'}
        replaced_word = ""
        ans = set()

        for char in word:
            if char not in nums:
                replaced_word += " "
            else:
                replaced_word += char
        
        integers = replaced_word.split()

        for integer in integers:
            ans.add(int(integer))

        return len(ans)

# Approach 2
# TC: O(n)

class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        nums = {'0','1','2','3','4','5','6','7','8','9'}
        ans = set()
        current_num = ""

        for char in word:
            if char in nums:
                current_num += char
            elif current_num:
                ans.add(int(current_num))
                current_num = ""

        if current_num:
            ans.add(int(current_num))

        return len(ans)

