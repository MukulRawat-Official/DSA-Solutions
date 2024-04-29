class Solution {
public:
    int count(int x){
        int ans = 0;
        
        while(x){
            ans += (x & 1);
            x >>= 1;
        }
        
        return ans;
    }
    int minOperations(vector<int>& nums, int k) {
      int ans = k;
        
      for(auto& x : nums) ans ^= x;
        
      return count(ans);
        
    }
};