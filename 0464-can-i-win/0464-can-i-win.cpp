typedef int ll;
class Solution {
public:
    
    bool canIWin(int mx, int res) {
    
    long mxm = mx * (mx+1) / 2;
    if(mxm<res) return false;
    vector<vector<ll>>dp(2,vector<ll>( (1<<mx) +1,-1));
    // turn can be replace by resultant value as we have mask to taken values.
    
    auto chk = [&](ll t , ll res , ll mask , auto&& chk)->bool{
        if(dp[t][mask] != -1) return dp[t][mask];
     
        for(int i = 1;i<=mx;i++){
           if( mask &  1<<(i-1))  continue;
           mask |= 1<<(i-1);
           if(res - i <= 0 || (chk(1^t , res - i  , mask , chk) == false) ) // need curr true and next false
               return dp[t][mask ^ (1<<(i-1))] = true;
           
           mask ^= 1 <<(i-1);
        }
        
        
        return dp[t][mask] = false;
    };
        
        
    return chk(1,res,0,chk);
    }
};