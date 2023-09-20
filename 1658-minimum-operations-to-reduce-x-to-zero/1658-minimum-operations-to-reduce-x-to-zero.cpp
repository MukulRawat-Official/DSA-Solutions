class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n  = nums.size();
        int sum = 0;
        
        for(auto& i : nums)
            sum+= i;
        
        if(sum == x)
            return nums.size();
        
        if(sum<x)
            return -1;
        
        sum -= x;
        

        
        int  l = 0;
        int ans = INT_MAX;
        int curr = 0;
        
        for(int i=0;i<n;i++)
        {
            curr += nums[i];
            
          
            while(curr>sum)
            curr-=nums[l++];
            

            if(curr == sum)
            ans =min(ans , n - (i-l+1) );
        }
        
        if(ans == INT_MAX)
            return -1;
        return ans;
        
    }
};