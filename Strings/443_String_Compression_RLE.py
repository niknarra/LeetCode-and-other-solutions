class Solution:
    def compress(self, chars: List[str]) -> int:
        if len(chars) == 1:
            return 1

        start = 0
        end = 1
        res = ''
        
        while end < len(chars):
            if chars[start] != chars[end]:
                res += chars[start]
                if end - start > 1:
                    res += str(end - start)
                start = end
            
            end += 1
        
        res += chars[start]
        if end - start > 1:
            res += str(end - start)
        
        for i in range(len(res)):
            chars[i] = res[i]

        return len(res)
