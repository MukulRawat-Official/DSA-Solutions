class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>adj(n);
        vector<int>inc(n,0);
        vector<vector<int>>clrs(n,vector<int>(26));
        for(auto& x : edges){
            adj[x[0]].push_back(x[1]);
            inc[x[1]]++;
        }
        
        queue<int>q;
        
        for(int i = 0;i<n;i++) {
             clrs[i][colors[i]-'a']++;
            if(!inc[i]) q.push(i);
        }
        
        int ans = 1 , curr;
        if(q.size())
        while(q.size()){
            curr = q.front(); q.pop();
            ans = max(ans,clrs[curr][colors[curr] - 'a']);
            
            for(auto& x : adj[curr]){
                if(!inc[x]) return -1;
                inc[x]--;
                for(int i = 0;i<26;i++) clrs[x][i] = max(clrs[curr][i] + (colors[curr] - 'a' == i) , clrs[x][i]);
                if(!inc[x]) q.push(x);
            }
        }
        for(auto& x : inc) if(x) ans = -1;
        return ans;
        
    }
};