class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>vis(n,0);
        long long ans = 0;
        for(int i = 0;i<n;i++){
            if(vis[i]) continue;
            vector<int>s;
            int j = i;
            
            while(!vis[j]){
                vis[j] = 1;
                s.push_back(arr[j]);
                j = (j + k) % n;
            }
            
            sort(s.begin(),s.end());
            int idx = s.size() / 2;
            
            for(auto& x : s) ans += abs(s[idx] - x);
        }
        
        return ans;
        
    }
};