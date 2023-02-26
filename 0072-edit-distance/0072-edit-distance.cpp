class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size() , m = b.size();
        if(!n || !m) return n + m;
        int dp[n][m];
        memset(dp,-1,sizeof(dp));
        
        auto recurr = [&](int i , int j,auto&& recurr)->int{
            if(i >= n || j >= m) return m + n - j - i;
            if(dp[i][j] != -1) return dp[i][j];    
            int ans = INT_MAX;
            
            if(a[i] == b[j]) ans = recurr(i+1,j+1,recurr);
            else  ans = min( {ans, recurr(i+1,j,recurr) + 1 , recurr(i,j+1,recurr) + 1 , recurr(i+1,j+1,recurr) + 1});
            
            
            return dp[i][j] = ans;
        };
        
        
        return recurr(0,0,recurr);
    }
};