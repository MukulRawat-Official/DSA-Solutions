class Solution {
public:
    bool chk(string& s, int sz){
        if(sz == s.size()) return false;
        string  t = s.substr(0,sz);
        string ans;
        while(ans.size() < s.size()) ans += t;
        return ans == s;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int l = 1; l * l <= s.size();l++){
            if(n % l) continue;
            
            if(chk(s,l) || chk(s,n/l)) return true;
        }
        
        return false;
    }
};