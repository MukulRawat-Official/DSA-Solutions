class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double , int>>pq;
        vector<vector<pair<int,double>>>adj(n);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0] , v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        double ans = 0;
        vector<double>vis(n,0); vis[start] = 1;
        pq.push({1,start});
        int node;
        double val;
        while(pq.size()){
           tie(val,node) = pq.top(); pq.pop();
           
            for(auto [x,vl] : adj[node]){
                if(x == end)  ans = max(ans , vl * val);    
                else if(vis[x] < vl * val) {
                  vis[x] = vl * val;
                  pq.push({val * vl , x});
                }
            }
        }
        
        
        return ans;
    }
};