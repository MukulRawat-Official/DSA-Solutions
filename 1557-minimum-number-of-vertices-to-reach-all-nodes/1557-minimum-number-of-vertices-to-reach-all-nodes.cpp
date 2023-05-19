class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans, inc(n,0);
        for(auto& x : edges){
            inc[x[1]]++;
        }
        
        for(int i = 0;i<n;i++){
            if(!inc[i]) ans.push_back(i);
        }
        
        if(!ans.size()) ans.push_back(0);
        return ans;
    }
};