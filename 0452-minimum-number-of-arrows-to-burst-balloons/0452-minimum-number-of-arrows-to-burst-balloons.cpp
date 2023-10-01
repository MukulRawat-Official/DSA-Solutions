class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr){
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0;i<n; ){
            ans++;
            int j = i+1 , minm = arr[i][1];
            
            while(j < n && arr[j][0] <= minm){
                minm = min(minm, arr[j][1]);
                j++;
            }
            i = j;
        }
        
        return ans;
    }
};