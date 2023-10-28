class Solution {
public:
    int countVowelPermutation(int n) {
        
        if(n == 1)
          return 5;
        
        long long dp[5] = {0,0,0,0,0} , prev[5] = {1,1,1,1,1};
        int mod = 1e9 + 7;
        int a = 0 , e = 1 , i = 2 , o = 3 , u = 4;
        
        for(int k = 1;k<n;k++)
        {
           dp[a] = prev[e] % mod;
           dp[e] = (prev[a] + prev[i]) % mod;
           dp[i] = (prev[a] +  prev[e] + prev[o] +  prev[u]) % mod;
           dp[o] = (prev[i] + prev[u]) % mod;
           dp[u] = prev[a] % mod;
           
           for(int i = 0;i<5;i++)
              prev[i] = dp[i];
        }
        
        long long sum = (prev[a] + prev[e] + prev[i] + prev[o] + prev[u]) % mod;
        
        return sum;
        
    }
};