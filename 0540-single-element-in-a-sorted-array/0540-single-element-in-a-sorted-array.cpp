class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // invariant bs
        
        int l  = - 1, h = nums.size();
        
        if(h + l == 0) return nums[0];
        while(h-l>1){
            int mid = (h + l) / 2;
            int cnt = mid;
            if(mid % 2 == 0)  cnt++;
            else     mid--;
            
            
            if(nums[mid] == nums[cnt])  l = cnt;
            else h  = mid;
        }
        
        return nums[h];
    }
};