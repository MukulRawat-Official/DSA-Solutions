class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        long long sum = 0 , lft = 0;
        for(auto& x: nums) sum += x;
        
        vector<int>ans;
        
        for(auto& x : nums){
            sum -= x;
            ans.push_back(abs(sum - lft));
            lft += x;
        }
        
        return ans;
    }
};