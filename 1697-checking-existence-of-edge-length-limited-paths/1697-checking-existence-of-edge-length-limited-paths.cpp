class Solution {
public:
    
    struct DSU{
      vector<int>par;
      int cmp;
      
      DSU(int n){
          par.resize(n+1,0);
          iota(par.begin(),par.end(),0);
          cmp = n;
      }
      
      int find(int a){
          return a == par[a] ? a : par[a] = find(par[a]);
      } 
        
      bool join(int a, int b){
          a = find(a);
          b = find(b);
          
          if(a == b) return false;
    
          par[a] = b;
          cmp--;
          return true;
      }
    };
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU ds(n);
        sort(edgeList.begin(),edgeList.end(), [&](vector<int>& a , vector<int>&b){
          return a[2] < b[2]; 
        });
        
        int cnt = 0;
        for(auto& x : queries) x.push_back(cnt++);
        sort(queries.begin(),queries.end(),[&](vector<int>& a , vector<int>&b){
           return a[2] < b[2]; 
        });
        vector<bool>ans(queries.size(),0);
        
        cnt = 0;
        for(auto& x : queries){
            int u,v;
            while(cnt < edgeList.size() && x[2] > edgeList[cnt][2]){
                u = edgeList[cnt][0];
                v = edgeList[cnt][1];
                ds.join(u,v); cnt++;
            }
            
            u = x[0]; v = x[1];
            ans[x[3]] = ds.find(u) == ds.find(v);
        }
        
        return ans;
        
    }
};