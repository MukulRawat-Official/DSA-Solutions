class Solution {
public:
    vector<vector<int>>adj;
    int n;
    string s;
    int ans = 0;
    pair<int,int> dfs(int curr){
        char ch = s[curr];
        int ans = 0;
        int ans2 = 0;
        int curr_two_max = 0;
        for(auto& x : adj[curr]){

            pair<int,int>  tmp = dfs(x);
            
            if(s[x] != ch)
            {
               if(ans == 0)  ans = tmp.first;
               else if(ans2 == 0){
                  ans2 = min(ans,tmp.first);
                  ans = max(ans,tmp.first);
                }
               else if(tmp.first >= ans){
                  swap(ans,ans2);
                   ans = tmp.first;
                  }
               else if(tmp.first>= ans2)    ans2 = tmp.first;
            }
            curr_two_max = max(curr_two_max,tmp.second);
            
        }
        curr_two_max = max(curr_two_max , ans + ans2 + 1);
        return {ans + 1,curr_two_max};
    }
    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        adj.resize(n);
        
        for(int i=0;i<n;i++){
           if(parent[i] == -1) continue;
           adj[parent[i]].push_back(i);
        }
        this->s = s;
        
        return  dfs(0).second;
    }
};