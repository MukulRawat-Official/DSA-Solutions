class Solution {
public:
    vector<vector<int>>adj;
    int n;
    string s;

    pair<int,int> dfs(int curr){
        char ch = s[curr];
        vector<int>arr(2,0);
        int curr_two_max = 0;

        for(auto& x : adj[curr]){

            pair<int,int>  tmp = dfs(x);
            if(s[x] != ch)
              for(auto& x : arr)    if(tmp.first>=x) swap(x,tmp.first);
            curr_two_max = max(curr_two_max,tmp.second);
         }
        curr_two_max = max(curr_two_max , arr[0] + arr[1] + 1);
        
        return {arr[0] + 1,curr_two_max};
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