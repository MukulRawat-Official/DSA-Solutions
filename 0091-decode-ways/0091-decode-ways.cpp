class Solution {
public:
    map<string,int>m;
    int dp[101];
    int f(string&s , int idx)
    {
        if(idx >= s.size()) return 1;
        
        if(s[idx] == '0') return 0;
        
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = f(s,idx+1);
        
        if(idx + 1 < s.size())
        {
           string t = s.substr(idx,2);
           if(m.count(t))
           dp[idx] += f(s,idx+2);
        }
        
        return  dp[idx];
    }
    int numDecodings(string s) {
        
        string t = "1";
        
        for(int i = '0';i<= '9';i++)
        {
            t.push_back(i); 
            m[t]++;
            t.pop_back();
        }
        
        t = "2";
        
        for(int i = '0';i<= '6';i++)
        {
            t.push_back(i);
            m[t]++;
            t.pop_back();
        }
        
        memset(dp,-1,sizeof(dp));
        return f(s,0);
        
    }
};