class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>inc;
        vector<int> ans;
        
        for(auto& x : adjacentPairs){
            int u = x[0] - 1, v = x[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            inc[u]++;
            inc[v]++;
        }
        
        
        function<void(int,int)> dfs = [&](int curr , int prv){
            ans.push_back(curr + 1);  
            for(auto&   x  : adj[curr]){
                if(x == prv) continue;
                dfs(x,curr);
            }
        };
        
        for(auto& [x,f] : inc){
            if(f == 1){
                dfs(x,-1);
                break;
            }
        }
        
        return ans;
        
    }
};