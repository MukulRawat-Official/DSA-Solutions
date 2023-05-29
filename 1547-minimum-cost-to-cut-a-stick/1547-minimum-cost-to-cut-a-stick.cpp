class Solution {
public:
    int minCost(int n, vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int m = arr.size();
        int dp[m][m];
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int l , int r ,int low , int high, auto&& recurr)->int{
            if(r < l) return 0;  
            
            if(dp[l][r] != -1) return dp[l][r];
            int ans = INT_MAX;
            int sum = high - low; 
            for(int j = l;j<=r;j++){
                ans = min(ans, recurr(l,j-1,low,arr[j] , recurr) + recurr(j+1,r,arr[j] , high , recurr) + sum);
            }
            
            return  dp[l][r] = ans;
            
        };
        
        return recurr(0,arr.size() - 1, 0 , n , recurr);
    }
};