class Solution {
public:
    int kadane (vector<int>&arr , int f = 1){
     int n = arr.size();
     int ans = 0 , sum = 0;
        for(auto& x :arr){
            sum += x;
            if(sum<0) sum = 0; ans = max(ans,sum);
        }
        
        return ans * f;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        for(auto& x : nums) sum += x;
        int ans = kadane(nums);
        for(auto& x : nums) x = -x;
        if(ans){
         int t = kadane(nums,-1);
            ans = max(ans,sum - t);
        }
       else
         ans = -1 * *min_element(nums.begin(),nums.end());
        return ans;
    }
};