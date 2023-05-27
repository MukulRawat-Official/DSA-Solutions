class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int i ,auto&& recurr)->int{
           if(i == n) return 0;
           if(dp[i] != -1) return dp[i];
           
           long ans = INT_MIN;
            
           long sum = 0;
           for(int j = 0;j<3 && j + i < n;j++)
           {
                sum += arr[j+i];
                ans = max(ans , - recurr(j+i+1,recurr) + sum);
           }        
           return dp[i] = ans;
        };
        
        long res = recurr(0,recurr);
        
        return (res > 0 ? "Alice" : (res < 0 ? "Bob" : "Tie"));
    }
};