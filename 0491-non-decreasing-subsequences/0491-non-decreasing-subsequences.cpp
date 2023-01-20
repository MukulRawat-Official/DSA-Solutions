class Solution {
public:
    set<vector<int>>ans;
    void dfs(vector<int>& nums, vector<int>&curr , int idx){
        if(idx == nums.size()){
            if(curr.size() > 1) ans.insert(curr);
            return;
        }
        
        if(curr.size() == 0 || curr.back()<=nums[idx]) {
            curr.push_back(nums[idx]);
            dfs(nums,curr,idx+1);
            curr.pop_back();
        }
        
        dfs(nums,curr,idx+1);
        
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>curr;
        dfs(nums,curr,0);
        vector<vector<int>>tmp;
        for(auto&x : ans) tmp.push_back(x);
        return tmp;
    }
};