class Solution:
    def compressedString(self, word: str) -> str:
        ans = []
        i = 0

        while i < len(word):
            count = 1
            while i + 1 < len(word) and word[i] == word[i + 1]:
                if(count >= 9):
                    ans.append(str(count))
                    ans.append(word[i])
                    count = 0
                count += 1
                i += 1
            ans.append(str(count))
            ans.append(word[i])
            i += 1

        return "".join(ans)
