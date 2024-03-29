class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        vector<int>ans(3,-1e9);
        
        for(auto& x :nums)
        {
            for(int i =0;i<3;i++)
            {
                if(ans[i] == -1e9)
                {ans[i] = x; break;}
                
                else if(ans[i] >= x)
                {ans[i] = x; break;}
            }
        }
        
        for(auto& x : ans)
            if(x == -1e9) return false;
        
        return true;
    }
};