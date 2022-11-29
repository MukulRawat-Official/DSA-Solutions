class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long,long>>dp(n);
        
        int ans = 0;
        for(int i = 1;i<n;i++){
            for(int j = i - 1;j>=0;j--){
               long diff =  (long) nums[j] - (long) nums[i];
               ans += dp[j][diff];
                dp[i][diff] += dp[j][diff] + 1;
            }
        }
        
        return ans;
    }
};