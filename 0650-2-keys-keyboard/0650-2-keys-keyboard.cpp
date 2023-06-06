class Solution {
public:
    int t;
    long dp[1001][1001][2];
    long r(int i , int curr , int f){
        if(i > t) return INT_MAX;
        if(i == t) return 0;
        
        long& ans = dp[i][curr][f];
     
        if(ans != -1) return ans;
        ans = INT_MAX;
        ans = min(ans , r(i + curr , curr , 1)+ 1);
        if(f)    ans = min(ans ,r(i,i,0) + 1);
        
        
        return ans;
        
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        t = n;
        memset(dp,-1,sizeof(dp));
        return r(1,1,0)+1;
    }
};