class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0 , f = 0;
        for(int i = s.size()-1; i>=0;i--){
            if(s[i] == ' ' && f) break;
             if(s[i] == ' ') continue; 
            f = 1;
            ans++;
        }
        
        return ans;
    }
};