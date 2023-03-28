class Solution {
public:
    // 1  7 30
    int mincostTickets(vector<int>& arr, vector<int>& cost) {
        int n = arr.size();
        
        int dp[366];
        
        memset(dp,-1,sizeof(dp));
        auto recurr = [&](int idx, auto&& recurr)->int{
          if(idx >= n) return 0;
          if(dp[idx] != -1) return dp[idx];
            
          int &ans = dp[idx] = INT_MAX;
            
          for(int i = idx;i<n;i++){
              if(arr[i] - arr[idx] > 29) break;
              
              int diff = arr[i] - arr[idx];
              
              if(diff == 0) ans = min(ans, recurr(i+1,recurr) + *min_element(cost.begin() , cost.end()));
              else if(diff < 7) ans = min(ans,recurr(i+1,recurr) + cost[1]);
              else ans = min(ans,recurr(i+1,recurr) + cost[2]);
          }
            
          return ans;
        };
         
        return recurr(0,recurr);
    }
};