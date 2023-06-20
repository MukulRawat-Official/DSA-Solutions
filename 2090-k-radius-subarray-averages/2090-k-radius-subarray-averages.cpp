class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long>psum(n,0);
        vector<int>ans(n,-1);
        for(int i = 0;i<n;i++) {
            psum[i] = nums[i];
            if(i) psum[i] += psum[i-1];
        }
        for(int i = 2 * k;i<n;i++){
            long sum = psum[i] - (i - 2 * k ? psum[i-2*k - 1] : 0);
            ans[i-k] = sum / (2* k + 1);
        }
        
        return ans;
    }
};