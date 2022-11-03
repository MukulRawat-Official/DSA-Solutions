class Solution {
public:
    struct node{
        int i , j , k , s;
    };
    vector<int> l = {1,0,-1,0} , r = {0,1,0,-1};
    int shortestPath(vector<vector<int>>& arr, int k) {
        int n = arr.size() , m = arr[0].size();
        if(n == 1 && m==1){
            if( (arr[0][0] && k) || !arr[0][0]) return 0;
            return -1;
        }

        queue<node>q;
        q.push({0,0,k,1});
        int ans = 1e4;
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        
        vis[0][0][k] = 1;
        while(q.size()){
            node t = q.front();
            q.pop();
            if(t.i == n-1 && t.j == m-1)
                ans = min(ans, t.s);
            
            else
            for(int tt = 0; tt < 4;tt++){
                int x = t.i + l[tt] , y = t.j + r[tt];
                if(x>=0 && y>=0 && x<n && y<m){
                    if(vis[x][y][t.k]) continue;
                    vis[x][y][t.k] = 1;
                    
                    if(arr[x][y] && t.k)
                    q.push({x,y,t.k-1,t.s+1});     
                         
                    
                    else if (!arr[x][y])
                       q.push({x,y,t.k,t.s+1});
                                            
                }
            }
        }
        
        
        if(ans == 1e4) return -1;
        return ans-1;
        
    }
};