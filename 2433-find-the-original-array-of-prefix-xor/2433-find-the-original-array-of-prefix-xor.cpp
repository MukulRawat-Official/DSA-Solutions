class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);
        
        ans[0] = arr[0];
        int pref = arr[0];
        for(int i = 1;i<n;i++){
            ans[i] = pref ^ arr[i];
            pref ^= ans[i];
        }
        
        return ans;
    }
};