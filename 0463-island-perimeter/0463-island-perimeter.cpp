class Solution {
public:
    int islandPerimeter(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> l = {1,0,-1,0} , r= {0,1,0,-1};
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!arr[i][j]) continue;
                ans += 4;
                for(int k = 0;k<4;k++){
                    int x = i + l[k] , y = j + r[k];
                    if(  min(x,y) < 0 || x == n || y == m || !arr[x][y]) continue;
                    ans--;
                }
            }
        }
        
        return ans;
    }
};