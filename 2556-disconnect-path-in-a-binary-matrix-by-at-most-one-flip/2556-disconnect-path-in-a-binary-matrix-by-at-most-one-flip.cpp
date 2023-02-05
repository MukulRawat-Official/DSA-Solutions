class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        auto dfs = [&](int x , int y,auto&& dfs)->bool{
           if(x == n - 1 && y == m-1)  return true;
           if(x == n || y == m) return false;
           
           bool ans = false;
           
           if(arr[x][y]) {
               arr[x][y] = 0;
               ans = dfs(x+1,y,dfs) || dfs(x,y+1,dfs);
           }
            
           return ans;
        };
        
        bool ans  = dfs(0,0,dfs);
        if(!ans) return true;
        arr[0][0] = 1;
        ans &= dfs(0,0,dfs);
        return !ans;
    }
};