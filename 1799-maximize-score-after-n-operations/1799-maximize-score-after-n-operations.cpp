class Solution {
public:
    int maxScore(vector<int>& arr) {
        int n  = arr.size();
        int mx = (1 << n) - 1;
        int dp[10][mx+1];
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int cnt , int mask , auto&& recurr)->int{
            if(mask == mx) return 0;
            if(dp[cnt][mask] != -1) return dp[cnt][mask];          
            int ans = 0;
            for(int i = 0;i<n;i++){
                int k = 1 << i;
                if(k & mask) continue;
                for(int j = i+1;j<n;j++){
                    int  l = 1 << j;
                    if(l & mask) continue;
                    int curr =  __gcd(arr[i] , arr[j]);
                    ans = max(ans , cnt * curr + recurr(cnt + 1, mask | k | l , recurr));
                }
            }
            
            return dp[cnt][mask] = ans;
        };
        
        return recurr(1,0,recurr);
    }
};