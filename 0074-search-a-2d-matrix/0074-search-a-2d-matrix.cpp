class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        
        cout<<m<<" "<<n<<endl;
        int i  = 0 ;int j = 0;bool ans = true;
        
        while(i<m-1)
            
        {
            if(matrix[i+1][0]<=target)
                i++;
         
         else
             break;
        }
        cout<<i<<" ";
        while(j<n)
        {
            if(matrix[i][j]<target)
                j++;
            
            else if(matrix[i][j] == target)
            {ans = true;break;}
            
            else
            {ans = false;break;}
        }
        
       cout<<j<<" ";
        if(j==n)
            ans = false;
        return ans;
        
        
    }
};