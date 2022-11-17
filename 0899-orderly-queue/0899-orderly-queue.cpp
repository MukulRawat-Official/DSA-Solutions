class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k != 1) {sort(s.begin(),s.end()); return s;}
        string ans = s , curr = s;
        
        s = s.substr(1) + s[0];  
        
        while(curr != s){
            if(ans.compare(s) > 0) ans = s;
            s = s.substr(1) + s[0];
        }
        
        return ans;
    }
};