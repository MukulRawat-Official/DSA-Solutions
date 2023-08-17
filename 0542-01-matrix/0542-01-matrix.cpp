class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,n * m + 1));
        priority_queue<pair<int,int>>pq;
        for(int i = 0;i<n;i++) for(int j=0;j<m;j++){
            if(!mat[i][j]){
                ans[i][j] = 0;
                pq.push({0,i * m + j});
            }
        }
        vector<int> l = {0,1,0,-1} , r = {1,0,-1,0};
        while(pq.size()){
            int curr = pq.top().second; pq.pop();
            int x = curr / m , y = curr % m;
            for(int k = 0;k<4;k++){
                int i = x + l[k];
                int j = y + r[k];
                
                if(i < 0 || j < 0 || i ==n || j == m || ans[i][j] <= ans[x][y] + mat[i][j])
                    continue;
                ans[i][j] = ans[x][y] + mat[i][j];
                pq.push({-ans[i][j] , i * m + j});
            }
        }
        
        return ans;
    }
};