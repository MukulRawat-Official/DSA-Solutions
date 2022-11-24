class Solution {
public:
    vector<vector<int>>vis;
    vector<int> l = {1,0,-1,0} , r = {0,1,0,-1};
    int n , m;
    bool is_safe(int x , int y){
      if(x<0 || y<0 || x == n || y == m) return false;
      return true;  
    }
    
    bool dfs(vector<vector<char>>&arr , int x ,int y ,string word , int idx){
      if(idx == word.size()) return true;
      bool ans = false;
      for(int k = 0;k<4;k++){
          int xx = x + l[k] , yy = y + r[k];
          if(is_safe(xx,yy) && (arr[xx][yy] == word[idx]) && !vis[xx][yy]){
              vis[xx][yy] = 1;
              ans |= dfs(arr,xx,yy,word,idx+1);
              vis[xx][yy] = 0;
          }
      }
        
      return ans;
    
    }
    bool exist(vector<vector<char>>& arr, string word) {
        n = arr.size();
        m = arr[0].size();
        vis.resize(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++){
           for(int j = 0;j<m;j++){
               if(arr[i][j] == word[0]){
                   vis[i][j] = 1;
                   if(dfs(arr,i,j,word,1)) return true;
                   vis[i][j] = 0;
               }
           }     
        }
        return false;
    }
};