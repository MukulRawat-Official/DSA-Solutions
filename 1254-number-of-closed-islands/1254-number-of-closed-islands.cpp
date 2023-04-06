class Solution {
public:
    int closedIsland(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int> l = {0,1,0,-1} , r= {1,0,-1,0};
        int ans = 0;
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j] || vis[i][j]) continue;
                queue<long long>q;
                long long curr = i * m + j;
                
                vis[i][j] = 1;
                q.push(curr);
                bool pos = 1;
                
                while(q.size()){
                    curr = q.front(); q.pop();
                    int x = curr / m  , y = curr % m;
                    
                    for(int k  =0;k<4;k++){
                        int xx = x + l[k] , yy = y + r[k];
                        if(xx < 0 || yy < 0 || xx == n || yy == m){
                            pos = 0;
                            continue;
                        }
                        
                        if(vis[xx][yy] || arr[xx][yy]) continue;
                        vis[xx][yy] = 1;
                        q.push(xx * m + yy);
                    }
                }
                
                
                ans += pos;
                
            }
        }
        
        return ans;
        
    }
};