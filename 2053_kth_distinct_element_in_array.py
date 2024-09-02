class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        char_counts = {}
        count = 0

        for char in arr:
            char_counts[char] = char_counts.get(char, 0) + 1
        
        for char in char_counts:
            if char_counts[char] == 1:
                count += 1

                if count == k:
                    return char
        
        return ""
