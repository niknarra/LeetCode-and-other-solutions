class Solution:
    def getSum(self, num):
        ans = 0
        while(num>0):
            digit = num%10
            ans += digit
            num = num//10
        
        return ans%2 == 0


    def countEven(self, num: int) -> int:
        ans = 0
        for i in range(1, num+1):
            if(self.getSum(i)):
                ans += 1
        
        return ans
