class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0 , ans = 0 , c = 0 , i = 0 , cnt = 0;
        
        for(auto& x : nums){
            if(x & 1) c++;
            
            if(c > k){
                cnt = 0;
                
                while(c > k){
                   if(nums[l] & 1) c--;
                   l++;
                }
            }
            
            while(c == k){
                if(nums[l] & 1) break;
                else cnt++ , l++;
            }
            if(c == k) ans += (cnt + 1);
            i++;
        }
        
        return ans;
    }
};