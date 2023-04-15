class Solution {
public:
    long long dp[1001][2001];
    int maxValueOfCoins(vector<vector<int>>& arr, int k) {
        
        for(auto& x : arr) for(int i  = 1;i<x.size();i++) x[i] += x[i-1];
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int i , int k , auto&& recurr)->int{
          if(i == arr.size()){
              if(k) return INT_MIN;
              return 0;
          }  
          if(dp[i][k] != -1) return dp[i][k];
            
          long long ans = dp[i][k] = recurr(i+1,k,recurr);
            
          for(int j = 0 ; j < k  && j < arr[i].size(); j++){
              long long curr = arr[i][j] + recurr(i+1, k - 1 - j , recurr);
              ans = max(ans,curr);
          }
            
          return dp[i][k] = ans;
        };
        
        
        return recurr(0,k,recurr);
    }
};