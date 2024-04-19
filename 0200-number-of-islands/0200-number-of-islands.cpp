class Solution {
public:
    vector<int> l  = {0,0,1,-1} , r = {1,-1,0,0};    
    int n , m ,x , y;
    
    void dfs(vector<vector<char>>&arr , int i , int j)
    {
        
        for(int k=0;k<4;k++)
        {
            x = i + l[k] ; y = j + r[k];
            if(x<0 || x == n || y <0 || y == m || arr[x][y] == '0') continue;
            arr[x][y] = '0';
            dfs(arr,x,y);
        }
    }
    int numIslands(vector<vector<char>>& arr) {
         n = arr.size() ; m = arr[0].size();
        
        int ans = 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
               if(! (arr[i][j] & 1)) continue;
               ans++;
                            
               dfs(arr,i,j);
            }
        }
        
        return ans;
    }
};