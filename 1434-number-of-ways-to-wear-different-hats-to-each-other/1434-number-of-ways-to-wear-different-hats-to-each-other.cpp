long dp[41][ (int)(1<<10)];
class Solution {
public:
   
    int numberWays(vector<vector<int>>& arr) {
        int n = arr.size();
        
        int mx  = (1<<n) - 1;
        for(int i = 0;i<41;i++) for(auto& x : dp[i]) x = -1;
        int mod = 1e9 + 7;
        
    
        function<int(int,int)> recurr = [&](int i , int mask){
           if(mask == mx) return 1; 
           if(i >= 40) return 0;
            
           long& ans = dp[i][mask];
           if(ans != -1) return (int)ans;
           ans = recurr(i+1,mask) % mod;
            
           for(int j = 0;j<n;j++){
               if(mask & (1<<j)) continue;
               for(auto& y : arr[j]){  
                  if(y == i + 1){
                      mask ^= (1<<j);
                      ans = (ans + recurr(i+1,mask)) % mod;
                      mask ^= (1<<j);
                  }
                   
               }
           }
            
            
           return (int)ans;
        };
        int mask = 0;
        return recurr(0,mask);
    }
};