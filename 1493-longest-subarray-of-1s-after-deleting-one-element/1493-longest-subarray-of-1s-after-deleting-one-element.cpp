class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>arr;
        int z = 0 , o = 0;
        
        if(nums[0]) o++;
        else z++;
        int ans = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]){
                if(z == 1) arr.push_back(0);
                z = 0;
                o++;
            }
            else{
                if(o) arr.push_back(o);
                z++;
                o = 0;
            }
        }
        if(o) arr.push_back(o);
        
        for(int i = 0;i<arr.size();i++){
            if(arr[i]) ans = max(ans,arr[i]);
            else if(i && i + 1 < arr.size()){
                ans = max(ans , arr[i-1] + arr[i+1]);
            }
        }
        
        
        return min((int)nums.size() - 1 , ans);
        
    }
};