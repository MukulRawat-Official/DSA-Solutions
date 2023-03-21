class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            int c = i;
            while(nums[c] != c+1 && nums[c] > 0 && nums[c] <= nums.size() && nums[c] != nums[nums[c]-1])
             swap( nums[nums[c]-1] ,nums[c]);
            
        }
        
        for(int i = 0 ;i<nums.size();i++){
            if(nums[i] != i + 1) return i+1;
        }
        
        return nums.size() + 1;
    }
};