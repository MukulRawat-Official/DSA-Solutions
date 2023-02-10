class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int r1 = 0 , r2 = arr.size(), c1 = 0 , c2 = arr[0].size();
        
        int cnt = r2 * c2; r2--; c2--;
        
        vector<int>t;
        while(cnt)
        {
            for(int i = c1;i<=c2 && cnt;i++ , cnt--)
            t.push_back(arr[r1][i]);      
            r1++;                     
            
            for(int i = r1;i<=r2 && cnt;i++ , cnt--)
            t.push_back(arr[i][c2]);
            c2--;
            
            for(int i = c2;i>=c1 && cnt; i-- , cnt--)
            t.push_back(arr[r2][i]);
            r2--;
            
            for(int i = r2;i>=r1 && cnt; i-- , cnt--)
            t.push_back(arr[i][c1]);
            c1++;
        }
        
        return t;
        
    }
};