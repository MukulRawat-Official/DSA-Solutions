class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>arr(n,vector<int>(n));
        int r1 = 0 , r2 = n-1 , c1 = 0 , c2 = n-1 , cnt = 0;
        
        while(cnt < n * n){
            for(int j = c1; j<=c2 && cnt < n * n; j++)arr[r1][j] = ++cnt;
            r1++;
            for(int i = r1;i<=r2 && cnt < n * n;i++)  arr[i][c2] = ++cnt;
            c2--;
            for(int j = c2;j>=c1 && cnt < n * n;j--) arr[r2][j] = ++cnt;
            r2--;
            for(int i = r2;i>=r1 && cnt < n * n;i--) arr[i][c1] = ++cnt;
            c1++;
        }
        
        return arr;
    }
};