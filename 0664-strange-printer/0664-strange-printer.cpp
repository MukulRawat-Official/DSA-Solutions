int dp[100][100];
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int l , int h, auto&& recurr)->int{
            if(l == h) return 1;
            
            int& ans = dp[l][h];
            if(ans != -1) return ans; ans = 101;
            
            for(int k = l; k<h;k++)
               ans = min(ans , recurr(l,k , recurr) + recurr(k + 1 , h , recurr));
            
            
            return ans -= (s[l] == s[h]);
        };
        
        return recurr(0,n-1,recurr);
    }
};