class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort() # Sort both the greed factor list
        s.sort() # and the size of cookies list

        lenOfGreed = len(g)
        lenOfCookies = len(s)

        greedIndex = 0
        cookieIndex = 0
        contentChildren = 0 # Var to store answer

        while(greedIndex < lenOfGreed and cookieIndex < lenOfCookies): # While we're not crossing bounds

            if g[greedIndex] <= s[cookieIndex]: # If the current greed factor is less than or equal to the current cookie
                contentChildren += 1 # Mark the child as content
                greedIndex += 1 # And move to the next child
                 
            cookieIndex += 1 # Move the cookie index in any case as the list is sorted
        
        return contentChildren

