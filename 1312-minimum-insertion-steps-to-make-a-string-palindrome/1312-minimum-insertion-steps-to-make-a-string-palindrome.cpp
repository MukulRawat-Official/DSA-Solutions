class Solution {
public:
    int dp[501][501];
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int l , int r , auto&& recurr)->int{
           if(l >= r) return 0;
           if(dp[l][r] != -1) return dp[l][r];
           int ans = 1000;
           if(s[l] == s[r]) ans = min(ans , recurr(l+1,r-1,recurr));
           else{
               ans = min({ans , recurr(l+1,r,recurr) + 1, recurr(l,r-1,recurr) + 1});
           }
            
           return dp[l][r] = ans;
        };
        
        return recurr(0,s.size()-1,recurr);
    }
};