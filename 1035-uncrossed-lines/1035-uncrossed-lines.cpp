class Solution {
public:
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
          int n = a.size();
          int m = b.size();
          int dp[501][501];
          memset(dp,-1,sizeof(dp));
          auto recurr = [&](int i , int j , auto&& recurr)->int{
             if(i == n || j == m) return 0;
             if(dp[i][j] != -1) return dp[i][j];
             int& ans = dp[i][j] = 0;
              if(a[i] == b[j]) ans = recurr(i+1,j+1, recurr)+1;
              else   ans = max(recurr(i,j+1,recurr) , recurr(i+1,j,recurr));
              return ans;
          };
        
          
          return recurr(0,0,recurr);
    }
};