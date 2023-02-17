#define pll pair<int,int> 
#define inf 100 
class Solution {
public:
    vector<int> l = {0,0,1,-1} , r = {1,-1,0,0};
    int minCost(vector<vector<int>>&arr ) {
        priority_queue<pll , vector<pll> , greater<pll>>pq;
        int n = arr.size() , m = arr[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,inf));
        // single value we'll give for indexing
        pq.push({0,0});
        vis[0][0] = 0;
        int val,curr;
        while(pq.size()){
            tie(val,curr) = pq.top(); pq.pop();
            int xx = curr / m , yy = curr % m;
            for(int k = 0;k<4;k++){
                int x = l[k] + xx , y = yy + r[k];
                
                if(x< 0 || x == n || y < 0 || y == m) continue;
                int curr = val + (k+1 != arr[xx][yy]);
                
                if(curr < vis[x][y]){
                    vis[x][y] = curr;
                    pq.push({curr , x * m + y});
                }
                
            }
        }
        return vis[n-1][m-1];
    }
};