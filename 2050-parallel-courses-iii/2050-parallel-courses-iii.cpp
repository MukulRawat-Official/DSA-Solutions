class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
         vector<vector<int>>adj(n);
         vector<int>inc(n,0);
         for(auto& x : relations){
             adj[x[0]-1].push_back(x[1]-1);
             inc[x[1]-1]++;
         }
         vector<int>ans(n,0);
         priority_queue<pair<int,int>>q;
         for(int i = 0;i<n;i++){
             if(!inc[i]){
                 q.push({time[i], i});
                 ans[i] = time[i];
             }
         }
         
         while(q.size()){
             int curr = q.top().second; q.pop(); 
             
             for(auto& x : adj[curr]){
                 if(!inc[x]) continue;
                 inc[x]--;
                 ans[x] = max(ans[x] , ans[curr] + time[x]);
                 if(!inc[x]){
                    q.push({ans[x] , x});
                 }
             }
         }
        
        
        return *max_element(ans.begin(),ans.end());
    }
};