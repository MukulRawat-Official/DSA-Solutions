int dp[20][10005];
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();
        for(int i= 0;i<n;i++) for(auto& x : dp[i]) x = -1;
        function<int(int,int)> recurr = [&](int i , int w){
           if(i == n)    return !w ?  0 : -(int)1e6;
            
           int& ans = dp[i][w + 5000]; if(ans != -1) return ans; 
           ans = recurr(i + 1 , w); 
           ans = max(ans , recurr(i + 1, w - rods[i]));
           ans = max(ans , recurr(i + 1, w + rods[i]) + rods[i]);
        
           return ans;
        };
        
        return max(0 ,recurr(0,0));
        
    }
};