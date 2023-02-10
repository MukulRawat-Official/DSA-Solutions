class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>inc(n,0);
        for(auto& x : prerequisites){
            adj[x[1]].push_back(x[0]);
            inc[x[0]]++;
        }
        
        vector<int>ans;
        queue<int>q;
        int id = 0;
        for(auto& x : inc){if(!x) q.push(id); id++;}
        
        while(q.size()){
            int curr = q.front(); q.pop();
            ans.push_back(curr);
            
            for(auto& x : adj[curr]){
                inc[x]--;
                if(!inc[x]) q.push(x);
            }
        }
        
        return ans.size() != n ? vector<int>() : ans;
    }
};