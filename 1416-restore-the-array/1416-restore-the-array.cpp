class Solution {
public:
    long dp[(int)1e5 + 1];
    int numberOfArrays(string s, int k) {
       int n = s.size();
       int mod = 1e9 + 7;
       for(int i = 0;i<n;i++) dp[i] = -1;
       auto recurr = [&](int idx  , auto&& recurr)->long{
           if(idx == s.size()) return 1;
           if(s[idx] == '0') return 0;
           if(dp[idx] != -1) return dp[idx]; 
           long ans = 0 , curr = 0;
              
           for(int i = idx;i<n;i++){
               curr = curr * 10 + s[i] - '0';
               if(curr <= k){
                   ans += recurr(i+1,recurr) % mod;
                   ans %= mod;
               }
               else break;
           }
           
           return dp[idx] = ans % mod;
       };
        
       return recurr(0,recurr);
       
    }
};