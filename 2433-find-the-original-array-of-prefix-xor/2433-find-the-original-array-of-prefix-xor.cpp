class Solution {
public:
    vector<int> findArray(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);   
        ans[0] = arr[0];
        for(int i = 1;i<n;i++){
            ans[i] = arr[i-1] ^ arr[i];
        }
        
        return ans;
    }
};