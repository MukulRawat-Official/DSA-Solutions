class Solution {
public:
    struct DSU{
        vector<int>par;
        int cmp;
        
        DSU(int n){
          par.resize(n+1,1);
          iota(par.begin(),par.end(),0);
          cmp = n;
        }
        
        int find(int a){ return par[a] == a ? a : par[a] = find(par[a]);}
        bool join(int a, int b){
           a = find(a);
           b = find(b);
           if(a == b) return false;
           par[b] = a;
           cmp--;
           return true;
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
         sort(edges.rbegin(),edges.rend());
         DSU a(n) , b(n);
         
         int ans = 0;
         for(auto& x : edges){
             int t = x[0] , u = x[1] , v = x[2];
             if(t == 3){
                 ans += (a.join(u,v) + b.join(u,v)) == 0;
             }
             else if(t == 2) ans += !a.join(u,v);
             else ans += !b.join(u,v);
         }
        
        if(a.cmp == 1 && b.cmp == 1) return ans;
        return -1;
    }

};