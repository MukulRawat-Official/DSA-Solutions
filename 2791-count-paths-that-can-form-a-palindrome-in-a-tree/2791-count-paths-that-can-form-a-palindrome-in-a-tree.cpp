class Solution {
public:
    typedef long long ll;
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>>adj(n);
        for(int i = 1;i<n;i++){
            int u = parent[i];
            adj[u].push_back(i);
        }
        
        ll m = 0;
        map<ll,ll>mp;  
        auto dfs = [&](int curr , ll& mask, auto&& dfs)->void{
             
             for(auto&x : adj[curr]){
                mask ^= (1ll << (s[x] - 'a'));      
                mp[mask]++;
                dfs(x,mask,dfs);
                mask ^= (1ll << (s[x] - 'a'));      
             }
        };
        
        
        dfs(0,m,dfs);
        ll ans = 0 , ans2 = 0;
        mp[0]++;
        for(auto& [x,f] : mp){
           // cout<<f<<" ";
           ans += 1ll * f * (f - 1) / 2;
           for(int i = 0;i<26;i++){
               ll curr = x ^ (1<<i);
               if(mp.count(curr))     ans2 += mp[curr] * f;
           }
        }
        
        
        return ans + ans2 / 2;
        
    }
};