class Solution {
public:

    vector<int> findBall(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        vector<vector<int>>vis(n+1,vector<int>(m,0));
        
        iota(vis[0].begin(),vis[0].end(),1);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m-1;j++)
                if(arr[i][j] == 1 && arr[i][j+1] == -1){
                    vis[i][j] = -2;
                    vis[i][j+1] = -2;
                } 
        
        }
 
        for(int i = 0;i<n;i++)
        {
          for(int j = 0;j<m;j++){
             
              if(!vis[i][j] || vis[i][j] == -2) continue;
              int y = j + arr[i][j];
              
              if(y>=0 && y<m && vis[i+1][y] != -2){
                 vis[i+1][y] = vis[i][j];
              }
          }
        }
        
        
        vector<int>res(m,-1);
        
        for(int i = 0;i<m;i++) {
            if(vis[n][i])
            res[vis[n][i]-1] = i;
        }
        return res;
        
    }
};