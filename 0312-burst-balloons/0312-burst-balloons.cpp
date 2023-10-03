class Solution {
public:
    int maxCoins(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        function<int(int,int)> recurr = [&](int l , int r){
            if(r<l) return 0;
            int& ans = dp[l][r];
            if(ans != -1) return ans;
            ans = 0;
            for(int k = l;k<=r;k++){
                ans = max(ans , recurr(l,k-1) + recurr(k+1,r) + arr[k] * (l - 1 >= 0 ? arr[l-1] : 1) * (r+1 < n ? arr[r+1] : 1));
             }
        
            return ans;
        };
                          
        return recurr(0,n-1);
    }
};