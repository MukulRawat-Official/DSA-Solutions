class Solution {
public:
    int numWays(vector<string>& s, string target) {
  
        int m = s[0].size();
        
        
        /*
          
          dp[j][t] = no of ways we can make till column j till index of target string t
          
          if(arr[i][j] == target[t]){
             
          }
        
        */
        
        int mod = 1e9 + 7;
        long dp[m + 1][target.size() + 1];
        memset(dp,-1,sizeof(dp));
        
        vector<vector<int>>arr(26,vector<int>(m,0));
        for(int j = 0;j<m;j++){
            for(int i = 0;i<s.size();i++){
                int ch = s[i][j] - 'a';
                arr[ch][j]++;
            }
        }
        
        auto recurr = [&](int idx , int t , auto&& recurr)->long{
          if(t == target.size()) return 1;
          if(idx == m) return 0;
          
          if(dp[idx][t]!= -1) return dp[idx][t];
            
          long ans = recurr(idx+1,t,recurr);
          for(int i = 0;i<26;i++){
             if(i + 'a' ==  target[t])    ans += (1ll* arr[i][idx] * recurr(idx+1,t+1,recurr) % mod);
             ans %= mod;
          }
            
          return dp[idx][t] = ans;
        
        };
        
        
        return recurr(0,0,recurr);
    }
};