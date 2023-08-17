class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,n * m + 1));
        queue<int>q;
        for(int i = 0;i<n;i++) for(int j=0;j<m;j++){
            if(!mat[i][j]){
                ans[i][j] = 0;
                q.push(i * m + j);
            }
        }
        vector<int> l = {0,1,0,-1} , r = {1,0,-1,0};
        while(q.size()){
            int curr = q.front(); q.pop();
            int x = curr / m , y = curr % m;
            for(int k = 0;k<4;k++){
                int i = x + l[k];
                int j = y + r[k];
                
                if(i < 0 || j < 0 || i ==n || j == m || ans[i][j] != n * m + 1)
                    continue;
                ans[i][j] = ans[x][y] + mat[i][j];
                q.push(i * m + j);
            }
        }
        
        return ans;
    }
};