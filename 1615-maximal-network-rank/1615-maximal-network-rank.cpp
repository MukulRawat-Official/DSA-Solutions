class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& edg) {
        vector<vector<int>>adj(n+1);
        
        for(auto& x : edg){
            int u = x[0] , v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
         
                int curr = adj[i].size() + adj[j].size();
                
                for(auto &x : adj[i]) if(x == j) {curr--;}
                
                ans = max(ans,curr);
            }
        }
        
        
        return ans;
    }
};