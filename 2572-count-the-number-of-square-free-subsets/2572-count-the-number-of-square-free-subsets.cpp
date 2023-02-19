#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    vector<int>pr = {2,3,5,7,11,13,17,19,23,29};    
    
    int give(int num){
        int mask = 0;
        
        for(int i = 0;i<10;i++){
            if(num % pr[i]== 0){
                if(num/pr[i] % pr[i] == 0) return -1;
                mask |= (1<<i);
            }
        }
        
        return mask;
    }
    
    int dp[1001][(1<<11)];
    
    long recurr(int idx , vector<int>&num, int mask){
        if(idx == num.size()) return 1;
        
        if(dp[idx][mask] != -1) return dp[idx][mask];
        long ans = recurr(idx+1,num,mask);
        
        int curr = give(num[idx]);
    
        if( curr != -1  && (mask & curr) == 0){
           ans += recurr(idx+1, num ,mask | curr); 
        }
        return dp[idx][mask] = ans % mod;
    }

    int squareFreeSubsets(vector<int>& nums) {
      memset(dp,-1,sizeof(dp));
      return (recurr(0,nums,0) - 1) % mod;
    }
};