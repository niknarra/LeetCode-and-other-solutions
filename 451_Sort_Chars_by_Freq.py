class Solution:
    def frequencySort(self, s: str) -> str:
        freq = {}

        for char in s:
            freq[char] = freq.get(char, 0) + 1

        sorted_freq = sorted(freq.items(), key=lambda item: item[1], reverse=True)
        
        return ''.join([char * count for char, count in sorted_freq])

# Initial Approach - O(n*2)

class Solution:
    def frequencySort(self, s: str) -> str:
        freq = {}
        ans = ''

        for char in s:
            freq[char] = freq.get(char, 0) + 1

        sorted_freq = dict(sorted(freq.items(), key=lambda item: item[1], reverse = True))

        for char in sorted_freq:
            for i in range(sorted_freq[char]):
                ans += char
        
        return ans
