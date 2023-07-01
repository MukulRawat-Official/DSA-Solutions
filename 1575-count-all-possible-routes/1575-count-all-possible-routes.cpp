class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int dp[n][fuel+1];
        memset(dp,0,sizeof(dp));
        int mod = 1e9 + 7;
        dp[start][fuel] = 1;
        for(int w = fuel;w>=0;w--){
            for(int i = 0;i<n;i++)
                for(int j = 0;j<n;j++){
                    int t = abs(locations[i] - locations[j]);
                    if(i != j && t <= w){
                        dp[j][w - t] = (dp[j][w-t] + dp[i][w]) % mod;
                    }
                }
        }
        
        int ans = 0;
        for(auto& x: dp[finish]) ans = (ans + x) % mod;
        return ans % mod;
        
    }
};