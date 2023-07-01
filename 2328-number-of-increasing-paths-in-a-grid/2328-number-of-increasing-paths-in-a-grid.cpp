class Solution {
public:
    vector<int>l = {0,1,0,-1} , r = {1,0,-1,0};
    int mod = 1e9 + 7;
    int countPaths(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        function<int(int,int)> recurr = [&](int i , int j){   
           int& ans = dp[i][j]; if(ans != -1) return ans; 
           ans = 1;
           for(int k = 0;k<4;k++){
               int x = i + l[k];
               int y = j + r[k];
               
               if( min(x,y) < 0 || x == n || y == m || arr[i][j] >= arr[x][y]) continue;
               
               ans = (ans + recurr(x,y)) % mod;
           }
           return ans;
        };
        
        int ans = 0;
        
        for(int i = 0;i<n;i++) for(int j =0;j<m;j++) ans = (ans + recurr(i,j)) % mod;
        
        return ans;
    }
    
};