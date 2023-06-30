class Solution {
public:
    vector<int>le = {1,0,-1,0} , ri = {0,1,0,-1};
    int latestDayToCross(int n, int m, vector<vector<int>>& qu) {
        vector<vector<int>>arr(n,vector<int>(m)) , vis(n,vector<int>(m));
        
        
        int ans = 0 , i , j , l = - 1, h = qu.size();
        auto pos = [&](int mid)->bool
        {
          for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) arr[i][j] = 1 , vis[i][j] = 0;
          for(int i = 0;i<= mid;i++) {
              int x = qu[i][0]  - 1, y = qu[i][1] - 1;
              arr[x][y] = 0;
          }
          queue<long>q;
          
          for(j = 0;j<m;j++)    if(arr[0][j]) q.push(j);
          while(q.size()){
              long curr = q.front(); q.pop();
              long row = curr / m , c = curr % m;
              
              for(int k = 0;k<4;k++){
                  int x = row + le[k] , y = c + ri[k];
                  if(x < 0 || y < 0 || x == n || y == m || vis[x][y] || !arr[x][y]) continue;
                  vis[x][y] = 1;
                  if(x + 1 == n) return true;
                  q.push(x * m + y);
              }
          }
            
          return false;
        };
        
        
        while(h - l > 1){
            int mid = (h + l) >> 1;
            if(pos(mid)) l = mid;
            else h = mid;
        }
        
        return l + 1;
    }
};