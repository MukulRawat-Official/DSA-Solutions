class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0 , h = nums.size();
        
        while(h - l > 1){
            int mid = (h + l) >> 1;
            
            int c = 0;
            for(auto& x : nums){
                c += x <= mid;
            }
            
            if(c <= mid) l = mid;
            else h = mid;
        }
        
        return h;
    }
};