class Solution {
public:
    int even(string& s,  int i){
        int l = i - 1, h = i;
        
        int ans = 0;
        
        while(l >=0 && h < s.size()){
            if(s[l--] != s[h++]) break;
            ans++;
        }
        
        return ans;
    }
    int odd(string& s,  int i){
        int l = i, h = i;
        
        int ans = 0;
        
        while(l >=0 && h < s.size()){
            if(s[l--] != s[h++]) break;
            ans++;
        }
        
        return ans;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            ans += even(s,i);
            ans += odd(s,i);
        }
        
        return ans;
    }
};