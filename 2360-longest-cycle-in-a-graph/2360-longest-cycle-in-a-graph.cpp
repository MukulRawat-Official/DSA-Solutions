class Solution {
public:
    int longestCycle(vector<int>& adj) {
        int n = adj.size();
        
    
        vector<pair<int,int>>vis(n);
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(vis[i].first) continue;
            int curr = 1;
            queue<int>q;
            vis[i] = {1,i};
            q.push(i);
            
            while(q.size()){
                int t = q.front(); q.pop();
                curr++;
                
                int ele = adj[t];
                
                if(ele == -1) continue;
                if(vis[ele].first){
                    if(vis[ele].second == i){
                        ans = max(ans , curr - vis[ele].first);
                    } 
                }
                
                else{
                    q.push(ele);
                    vis[ele] = {curr,i};
                }
            }
        }
        
        return ans;
    }
};