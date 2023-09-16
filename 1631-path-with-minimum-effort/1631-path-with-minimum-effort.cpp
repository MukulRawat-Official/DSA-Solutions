class Solution {
public:
    #define pii pair<long long,long long>
    #define ll long long
    int minimumEffortPath(vector<vector<int>>& arr) {
        
        priority_queue<pii>pq;
        int n = arr.size();
        int m = arr[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        pq.push({0,0});
        vector<int> l = {1,0,-1,0} , r = {0,1,0,-1};
        ll ans = INT_MAX;
        while(pq.size()){
            auto curr = pq.top(); pq.pop();
            
            ll val = -curr.first;
            ll cord = curr.second;
            ll x = curr.second / m , y = curr.second % m;
            
            if(x == n- 1 && y == m-1)    { ans = min(ans,val); continue;}
            if(vis[x][y]) continue;
            vis[x][y] = 1;
        
            for(int k = 0;k<4;k++){
                int i = l[k] + x , j = r[k] + y;
                if(i == n || j == m || i < 0 || j < 0 || vis[i][j]) continue;
                ll vl = max(val , abs(1ll* arr[i][j] - arr[x][y]) );
                pq.push({-vl ,  i * m + j});
            }
        }
        
        
        return ans;
    }
};