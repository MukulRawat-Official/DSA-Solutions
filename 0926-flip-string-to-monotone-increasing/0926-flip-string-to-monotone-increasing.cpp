class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int l = 0 , r = n-1;
        int o = 0 , z = 0;
        
        int ans = INT_MAX;
        for(auto& x : s) o += (x&1);
         ans = min(ans,z + o);
           
        for(int i = n-1;i>=0;i--){
            if(s[i] & 1) o--;
            else z++;
            ans = min(ans,z+o);
        }
        
        return ans;
    }
};