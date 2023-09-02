class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {    
        int n = s.size();
        map<string,int>mp;
        for(auto& x : dictionary) mp[x];
        vector<int>dp(n+1,INT_MAX); dp[n] = 0;
        
        for(int i = n-1;i>=0;i--){
            string tmp = "";
            for(int j = i;j<n;j++){
                tmp.push_back(s[j]);
                dp[i] = min(dp[i] , !mp.count(tmp) * (j - i + 1)  +  dp[j+1]);
            }
        }
        
        
        return dp[0];
    }
};