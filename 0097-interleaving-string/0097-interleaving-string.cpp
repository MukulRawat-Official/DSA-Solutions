class Solution {
public:
    
    int dp[101][101][201];
    int  n , m , z; 
    
    int xyz(string&a , string&b , string&c , int i , int j , int k)
    {
       if(k == z)return true;
        
       if(dp[i][j][k] != -1)return dp[i][j][k];
       
       dp[i][j][k] = 0;
       
      if(i<n && a[i] == c[k]) dp[i][j][k] |= xyz(a,b,c,i+1,j,k+1);
        
      if(j<m && b[j] == c[k]) dp[i][j][k] |= xyz(a,b,c,i,j+1,k+1);
        
      return dp[i][j][k];
          
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        n = s1.size() , m = s2.size() , z = s3.size();
        if(n+m != z) return false;memset(dp,-1,sizeof(dp));
        return xyz(s1,s2,s3,0,0,0);
    }
};