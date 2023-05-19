class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
     int n = adj.size(); 
     vector<int>clr(n,0);  
      
     for(int i = 0;i<n;i++){
      if(clr[i]) continue;
      queue<int>q; q.push(i);
      clr[i] = 1;
      while(q.size()){
          int t = q.front(); q.pop();
          
          for(auto& x : adj[t]){
              if(clr[x]){
                if(clr[x] == clr[t]) return false;
                continue;
              }
              
              if(clr[t] == 1) clr[x] = 2;
              else clr[x] = 1;
              q.push(x);
          }
      }
     }
    
      return true;
    }
};