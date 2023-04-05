class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
      long long l = -1 , h = 0;
        
        for(auto& x : nums) h = max(h,1ll* x+1);
        
        
        while(h-l>1){
            int mid = (h+l) / 2;
            
            long long rem = 0;
            
            for(int i =  nums.size() - 1;i>=0;i--){
                long long curr = rem + nums[i];
                rem = max(0ll, curr - mid);                
            }
            
            if(rem) l =  mid;
            else h =  mid;
        }
        
        return h;
    }
};