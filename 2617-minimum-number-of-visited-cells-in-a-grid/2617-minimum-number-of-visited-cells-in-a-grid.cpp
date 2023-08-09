class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        int inf = n * m + 10;
        vector<vector<int>>dp(n,vector<int>(m,inf));
        dp[0][0] = 1;
        vector<priority_queue<pair<int,int>>>col(m);
        
        for(int i = 0;i<n;i++){
            priority_queue<pair<int,int>>pq;
           
            for(int j = 0;j<m;j++){
             int curr = dp[i][j];
                
             auto& tmp = col[j];
             while(tmp.size() && tmp.top().second < i) tmp.pop();
             if(tmp.size()) curr = min(curr , 1 - tmp.top().first);
             while(pq.size() && pq.top().second < j) pq.pop();
             if(pq.size()) curr = min(curr , 1 - pq.top().first);
             
             dp[i][j] = curr;
             tmp.push({-curr , i + arr[i][j]});   
             pq.push({-curr , j + arr[i][j]});
          }
        }
        
        
       return dp[n-1][m-1] == inf ? -1 : dp[n-1][m-1];
    }
};