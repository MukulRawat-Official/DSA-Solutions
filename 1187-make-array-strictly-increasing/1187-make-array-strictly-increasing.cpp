int dp[2002][2002][2];
class Solution {
public:
    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        a.insert(a.begin(), -1);
        sort(b.begin() , b.end());
        int n = a.size();
        int m = b.size();
        for(int i = 0;i<n;i++) for(int j = 0;j<=m;j++) dp[i][j][0] =-1 ,  dp[i][j][1] = -1;

        function<int(int,int,int)> recurr = [&](int i , int j , int t){
           if(i == n) return 0;
           int& ans = dp[i][j][t]; if(ans != -1) return ans; ans = 1e4;
           
           int prv = t ? a[i-1] : b[j-1];
           if(a[i] > prv)     ans = recurr(i+1,j,1);
           int id = lower_bound(b.begin() + j , b.end() , prv + 1) - b.begin();
           if(id != m)    ans = min(ans , recurr(i+1,id + 1 , 0) + 1);
           return ans;
        };
        
        int ans = recurr(1,0,1);
        return ans >= 1e4 ? -1 : ans;
        
    }
};