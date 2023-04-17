class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx= 0;
        for(auto& x : candies) mx = max(x,mx);
        vector<bool>ans;
        for(auto& x : candies){
            if(x + extraCandies >= mx) ans.push_back(1);
            else ans.push_back(0);
        }
        
        return ans;
    }
};