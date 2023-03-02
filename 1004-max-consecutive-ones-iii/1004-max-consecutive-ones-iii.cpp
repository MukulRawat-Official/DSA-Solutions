class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int l = 0 , n = nums.size();
     int ans = 0 , one = 0;
     for(int i = 0;i<n;i++){
         if(nums[i] == 1)    one++;
         else k--;
         
         while(k<0){
             if(nums[l] == 0)k++;
             l++;
         }
         
         ans = max(ans, (i-l+1));
         
     }
        
        return ans;
    }
};