class Solution {
public:
    const int mod = 1e9 + 7;
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n = num2.size();
        while(num1.size() < n) num1.insert(num1.begin(), '0');
        int dp[23][2][2][401];
        memset(dp,-1,sizeof(dp));
        
        function<int(int,int,int,int)> recurr = [&](int i , int lb , int ub , int sum){
            if(sum > max_sum) return 0;
            if(i == n) { return  1 * (min_sum <= sum); }  
             
            int l = lb ? 0 : num1[i] - '0';
            int u = ub ? 9 : num2[i] - '0';
            
            int& ans = dp[i][lb][ub][sum];
            if(ans != -1) return ans; ans = 0;
            
            for(int j = l;j<=u;j++){
                ans = (ans + recurr(i+1, lb |  (num1[i] - '0' < j) ,  ub | (num2[i] - '0' > j) , sum + j)) % mod;
            }
            
            return ans;
        };
        
        return recurr(0,0,0,0);
        
    }
};