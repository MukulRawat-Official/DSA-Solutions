class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        int dp[n+1][2];
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int i , int t,auto&& recurr)->int{
           if(i == n) return 0;
            if(dp[i][t] != -1) return dp[i][t];
           long ans = t ? INT_MIN : INT_MAX;
            
           long sum = 0;
           for(int j = 0;j<3 && j + i < n;j++)
           {
                sum += arr[j+i];
                if(t) ans = max(ans , recurr(j+i+1 , t ^ 1,recurr) + sum);
                else ans = min(ans , recurr(j+i+1 , t ^ 1,recurr) - sum);
           }
           
           return dp[i][t] = ans;
        };
        
        long res = recurr(0,1,recurr);
        
        return (res > 0 ? "Alice" : (res < 0 ? "Bob" : "Tie"));
    }
};