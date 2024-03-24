class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n = nums.size();
       for(int i = 0;i<nums.size();i++){
           int curr = nums[i] % n;
           
           if(nums[curr] >= n) return (curr);
           nums[curr] += n;
       }   
    
       // Kool approach
       return -1;
    }
};