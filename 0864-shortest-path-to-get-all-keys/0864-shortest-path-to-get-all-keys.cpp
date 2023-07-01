class Solution {
public:
    #define set_bit __builtin_popcountll
    #define v(x) vector<x>
    vector<int> l = {1,0,-1,0} , r = {0,1,0,-1};
    int shortestPathAllKeys(vector<string>& arr) {
       int n = arr.size();
       int m = arr[0].size();
       int keys = 0 , start = 0;
       for(int i = 0;i<n;i++) for(int j = 0;j<m;j++)
       {
           if(arr[i][j] == '@') start = i * m + j;
           if(islower(arr[i][j])) keys++;
       }
        
       v(v(v(int))) vis(n,v(v(int))(m,v(int)(1<<keys , 1e6)));
       queue<pair<int,int>>q;
       vis[start/m][start%m][0] = 0;
       q.push({start,0});
       int ans = 1e6 , curr , key;
       while(q.size()){
           tie(curr,key) = q.front(); q.pop();
           int xx = curr / m  , yy = curr % m;
           for(int k = 0;k<4;k++){
               int x = l[k] + xx , y = r[k] + yy;
               
               if(x < 0 || y < 0 || x == n || y == m || arr[x][y] == '#') continue;
               if(islower(arr[x][y])) {
                   int nkey = (1<<(arr[x][y] - 'a')) | key;
                   if(vis[x][y][nkey] <= vis[xx][yy][key] + 1) continue;
                   vis[x][y][nkey] = vis[xx][yy][key] + 1;
                   if(set_bit(nkey)  == keys) ans = min(ans , vis[x][y][nkey]);
                   else  q.push({x * m + y ,nkey});
               }
               
               
               else {
                   bool hv = 1;
                   if(isupper(arr[x][y])) hv = (1<<(arr[x][y] - 'A')) & key;
                   if(hv &&   vis[x][y][key] > vis[xx][yy][key] + 1)  {
                       vis[x][y][key] = vis[xx][yy][key] + 1;
                       q.push({x * m + y, key});
                   }
               }
           }
           
       }
        
        
       return ans == 1e6 ? -1 : ans;
       
       
    }
};