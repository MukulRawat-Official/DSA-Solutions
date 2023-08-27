class Solution {
public:
    int n;
    int dp[2000][2000];
    bool dfs(vector<int>&arr , int i , int  k)
    {
          if(i>= n-1)
              return true;
          
          if(dp[i][k] != -1)
              return dp[i][k];
        
          dp[i][k] = false;
          int curr = arr[i];
          for(int l =  i+1 ; l<n ; l++)
          {
              int x = arr[l] - curr - k;
              if(abs(x) <= 1)
              dp[i][k]|= dfs(arr,l, arr[l]-curr);
              
              else if(x > 1)
                  break;
                  
          }
        
        return dp[i][k];
        
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        memset(dp,-1,sizeof(dp));
        return dfs(stones,  0 , 0);
    }
};