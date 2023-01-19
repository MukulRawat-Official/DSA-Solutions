class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>mp(k+1,0); mp[0]++;
        int sum = 0 , ans = 0;
        for(auto& x : nums){
          x %= k;
        if(x<0) x+= k;
          sum += x;
          sum %= k;
          ans += mp[sum];
          mp[sum]++;
        }
        
        return ans;
        
    }
};