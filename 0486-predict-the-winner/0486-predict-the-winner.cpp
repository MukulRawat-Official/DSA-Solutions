class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int dp[21][21];
        memset(dp,-1,sizeof(dp));
        
        auto recurr= [&](int i , int j, auto&& recurr)->int{
          if(i == j) return nums[i];
           if(dp[i][j] != -1) return dp[i][j];  
           int first = nums[i] - recurr(i+1,j,recurr);
           int second = nums[j] - recurr(i,j-1,recurr);
    
           return dp[i][j] = max(first,second);
        };
        
        return recurr(0,nums.size()-1,recurr) >= 0;
    }
};