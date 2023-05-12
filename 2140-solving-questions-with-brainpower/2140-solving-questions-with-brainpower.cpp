class Solution {
public:
    long long mostPoints(vector<vector<int>>& arr) {
        
        int n = arr.size();
        vector<long long>dp(n,-1);
        auto recurr = [&](int i , auto&& recurr)->long long{
           if(i >= n) return 0;
           if(dp[i] != -1) return dp[i]; 
           long long ans = recurr(i+1,recurr);
           ans = max(ans , recurr(i + arr[i][1] + 1, recurr ) + 1ll* arr[i][0]);
           return dp[i] = ans;
        };
        return recurr(0,recurr);
    }
};