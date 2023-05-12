class Solution {
public:
    long long mostPoints(vector<vector<int>>& arr) {
        
        int n = arr.size();
        vector<long long>dp(n,0);
       /*
         dp[i] = max value you can make till idx i
      */ 
       long long mx = 0;
       for(int i = 0;i<n;i++){
           mx = max(mx,dp[i]);
           dp[i] = mx + arr[i][0];
           int id = arr[i][1] + i + 1;
           if(id < n)  dp[id] = max(dp[id] , dp[i]);
       }
    
       long long ans = 0;
        for(auto& x : dp) ans = max(ans,x);
        return ans;
    }
};