class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = -1 , h = nums.size() + 1;
        
        auto chk = [&](int sz)->bool{
          int one = 0;
          for(int i = 0;i<sz;i++)    one += nums[i];
          int cnt = sz - one;
            
          if(cnt <= k) return true;
            
          for(int i = sz;i<nums.size();i++){
              one += nums[i] - nums[i-sz];
              cnt = sz - one;
              
              if(cnt <= k) return true;
          }
            
          return false;
        };
        while(h -l > 1){
            int mid = (h+l) / 2;
            
            if(chk(mid)) l = mid;
            else h = mid;
        }
        
        return l;
    }
};