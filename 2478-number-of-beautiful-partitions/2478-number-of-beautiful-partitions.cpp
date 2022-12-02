class Solution {
public:
    int mod = 1e9+7 , minm;
    bool chk(char ch){
        return ch == '2' || ch == '3' || ch == '5' || ch == '7';
    }
    
    int dp[1001][1001];
    int dfs(string& s , int idx , int k){
       if(idx == s.size()) return k == 0;
       if(k<=0) return 0;
       if(dp[idx][k] != -1) return dp[idx][k];
       int ans = 0;
        if(chk(s[idx])){
            for(int i = idx + minm - 1;i<s.size();i++){
                if(!chk(s[i])){
                    ans += dfs(s,i+1,k-1);
                    ans %= mod;
                }
            }
        }
        
        return dp[idx][k] = ans;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        minm = minLength;
        memset(dp,-1,sizeof(dp));
        return dfs(s,0,k);
    }
};