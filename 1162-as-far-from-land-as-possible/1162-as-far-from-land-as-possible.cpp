class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n  =arr.size();
        vector<pair<int,int>>curr;
        int ans = 0;
        for(int i  =0;i<n;i++) for(int j = 0;j<n;j++){
            if(arr[i][j]) curr.push_back({i,j});
        }
        for(int i  =0;i<n;i++) for(int j = 0;j<n;j++){
            if(!arr[i][j]) {
                int cur = INT_MAX;
                for(auto [f,s] : curr)
                cur = min(cur, abs(i-f) + abs(j-s));
                ans = max(ans,cur);
            }
        }
        ans = ans == 0 || ans == INT_MAX ? -1 : ans;
        return ans;
    }
};