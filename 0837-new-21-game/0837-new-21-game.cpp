class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
       int sz = min(n + 1 , k + maxPts);
       vector<double>dp(sz);
       for(int i = k;i<sz;i++) dp[i] = 1;
       if(k){
           dp[k-1] = (sz - k) * 1. / maxPts;
       } 
        
        // initial commit is necessary to apply sliding window as  from k all are 
        // base cases i.e dp[k] -> dp[n] = 1;
        // dp[k-1] -> dp[0] =  (dp[i + 1] + dp[i+2] ... dp[i+mx]) / maxPts 
       for(int i = k-2;i>=0;i--){
           // dp[i] = dp[i+1] + .... dp[i + mx]
           // dp[i+1] = dp[i+2] .... dp[i + mx + 1]
           // dp[i] = dp[i+1] + (dp[i+1] - dp[i + mx + 1]) / maxPts;
           double curr = dp[i+1];
           if(i + 1 + maxPts < sz) curr -= dp[i+1+maxPts];
           dp[i] = dp[i+1] + curr / maxPts;
       }
        
       return dp[0];
        
    }
};