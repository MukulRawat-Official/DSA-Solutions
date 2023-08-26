class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        int mx = -2000 , ans = 0;
        
        for(auto& x : pairs){
            if(mx < x[0]){
                mx = x[1];
                ans++;
            }
            
            else mx = min(mx,x[1]);
        }
        
        return ans;
    }
};