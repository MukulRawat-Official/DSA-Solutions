class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp; mp[0]++;
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