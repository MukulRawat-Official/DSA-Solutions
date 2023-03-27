class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,1e8));
        
        dp[n-1][m-1] = arr[n-1][m-1];
        
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(i<n-1)
                    dp[i][j] = min(dp[i+1][j] + arr[i][j] , dp[i][j]);
                if(j<m-1)    
                    dp[i][j] = min(dp[i][j] , dp[i][j+1] + arr[i][j]);
            }
        }
        
        return dp[0][0];
    }
};