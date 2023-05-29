class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                dp[i][j] = INT_MIN;
                if(i + 1 < n && j + 1 < m) dp[i][j] = arr[i][j] + max(dp[i+1][j] , dp[i][j+1]);
                
                else if(i + 1 < n) dp[i][j] = arr[i][j] + dp[i+1][j];
                else if(j + 1 < m) dp[i][j] = arr[i][j] + dp[i][j+1];
                else dp[i][j] = arr[i][j];
                
                dp[i][j] = min(0,dp[i][j]);
            }
        }
        
        return -dp[0][0] + 1;
    }
};