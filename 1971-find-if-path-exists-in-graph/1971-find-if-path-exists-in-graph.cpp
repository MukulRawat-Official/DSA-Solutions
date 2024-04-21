class Solution {
public:
    vector<int>vis;
    bool dfs(vector<vector<int>>&adj ,int curr  , int dest){
        if(curr == dest) return true;
        // cout<<curr<<endl;
        bool ans = false;
        for(auto& x : adj[curr]){
            if(vis[x]) continue;
            vis[x] = 1;
            ans |= dfs(adj,x,dest);
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.clear();
        vis.resize(n,0);
        vis[source] = 1;
        vector<vector<int>>adj(n);
        for(auto& x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        return dfs(adj,source,destination);
    }
};