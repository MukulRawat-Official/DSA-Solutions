class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;
        vector<vector<int>>dp(n,vector<int>(1001,1));
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int d = arr[j] - arr[i] + 500;
                dp[j][d] = max(dp[j][d] , dp[i][d] + 1);
                ans = max(ans,dp[j][d]);
            }
        }
        
        return ans;
    }
};