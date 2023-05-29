class Solution {
public:
    int minCost(int n, vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int m = arr.size();
        int dp[m][m];
        memset(dp,-1,sizeof(dp));
        auto give = [&](int l , int r)->int{
           pair<int,int>tmp = {0,n};
           if(l) tmp.first = arr[l-1];
           if(r + 1 < m) tmp.second = arr[r+1];
           return tmp.second - tmp.first;
        };
        auto recurr = [&](int l , int r, auto&& recurr)->int{
            if(r < l) return 0;  
            
            if(dp[l][r] != -1) return dp[l][r];
            int ans = INT_MAX;
            int sum = give(l,r); 
            for(int j = l;j<=r;j++){
                ans = min(ans, recurr(l,j-1,recurr) + recurr(j+1,r,recurr) + sum);
            }
            
            return  dp[l][r] = ans;
            
        };
        
        return recurr(0,arr.size() - 1,recurr);
    }
};