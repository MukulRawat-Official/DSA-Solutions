#define inf 1e6
class Solution {
public:
    vector<vector<vector<int>>>adj;
    int findCheapestPrice(int n, vector<vector<int>>& edge, int src, int dst, int k) {
        adj.resize(n);
        for(auto& x : edge) adj[x[0]].push_back({x[1],x[2]});
        vector<int>ans(n,inf);
        ans[src] = 0;
        queue<pair<int,int>>q; q.push({src,0});
        
        
        
        for(int i = 0;i<=k;i++){
            int sz = q.size();
            
            while(sz--){
             pair<int,int> tmp = q.front(); q.pop();
             for(auto& x : adj[tmp.first])
             {
                 if(ans[x[0]] > tmp.second + x[1])
                 {
                   ans[x[0]] = tmp.second + x[1];
                   q.push({x[0],ans[x[0]]});
                }
             }
                
            }
            
            for(auto& x : ans) cout<<x<<" ";
            cout<<endl;
            
        }
        
        
        if(ans[dst] == inf)return  -1;
        return ans[dst];
        
    }
};