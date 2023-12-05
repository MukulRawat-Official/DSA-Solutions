class Solution:
    def numberOfMatches(self, n: int) -> int:
        ans = 0
        while n > 1:
            ans = ans + int(n / 2);
            n = int( (n+1) / 2);
        
        return ans