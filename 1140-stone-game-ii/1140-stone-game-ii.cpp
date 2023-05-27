class Solution {
public:
    int stoneGameII(vector<int>& arr) {
        
        int n = arr.size();
        int dp[n+1][200][2];
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int i , int m , int t,auto&& recurr)->int{
           if(i == n){return 0;}
            if(dp[i][m][t] != -1) return dp[i][m][t];
            int ans = t ? INT_MIN : INT_MAX;
            int sum = 0;
            for(int j = 0;j< 2 * m && j + i < n;j++)
            {
                int id = i + j;
                sum += arr[id];
                
                
                if (t) ans = max(ans , recurr(id + 1 , max(m,j+1) , t ^ 1,recurr) + sum);
                else ans = min(ans, recurr(id+1, max(m,j+1) , t ^ 1 , recurr));
            }
            
            return dp[i][m][t] = ans;
        
        };
        
        
        return recurr(0,1,1,recurr);
    }
};