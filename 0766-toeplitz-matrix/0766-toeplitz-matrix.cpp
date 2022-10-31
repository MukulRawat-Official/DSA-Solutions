class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        
        for(int i = 0;i<n;i++)
        {
         int x = i ,y = 0;
          int curr = matrix[x][y];   
          while(x<n && y < m)
          {
              if(curr != matrix[x][y]) return 0;
              x++;
              y++;
          }
        }
        
        for(int j = 1;j<m;j++)
        {
           int x = 0 ,y = j;
          int curr = matrix[x][y];   
          while(x<n && y < m)
          {
              if(curr != matrix[x][y]) return 0;
              x++;
              y++;
          } 
        }
        
        return 1;
    }
};