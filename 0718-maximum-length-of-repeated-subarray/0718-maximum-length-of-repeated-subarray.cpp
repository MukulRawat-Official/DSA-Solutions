class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        int ans = 0;
        for(int i = 0;i + ans <n;i++){

            for(int j = 0;j <m;j++){
              int jj = j;
              int ii = i;
              int curr = 0;
                
              while(ii<n && jj < m && nums1[ii] == nums2[jj]) ii++,jj++,curr++;
              ans = max(ans,curr);
            }
        }
        
        return ans;
    }
};