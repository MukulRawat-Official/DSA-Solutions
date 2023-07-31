class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> recurr = [&](int i , int j){
           if(i == n && j == m) return 0;
           int& ans = dp[i][j]; if(ans != -1) return ans;
           ans = 1e6;
           if(i == n) ans = min(ans , recurr(i,j+1) + s2[j]);
           else if(j == m) ans = min(ans , recurr(i+1,j) + s1[i]);
           else{
               if(s1[i] == s2[j]) ans = min(ans , recurr(i+1,j+1));
               else{             
                  ans = min(ans , recurr(i+1, j) + s1[i]);
                  ans = min(ans , recurr(i, j+1) + s2[j]);
               }
           }   
               
           return ans;
        };   
        return recurr(0,0);
    }
};