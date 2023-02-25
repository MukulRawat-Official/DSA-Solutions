class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = INT_MIN  , mn = INT_MAX;
        int ans = 0;
        for(auto& x : prices){
            mn = min(x,mn);
            ans = max(ans , x - mn);
            
        }
        
        return ans;
    }
};