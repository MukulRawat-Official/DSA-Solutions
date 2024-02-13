class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto& s : words){
            int l = 0 , h = s.size()-1;
            
            while(l < h){
                if(s[l] != s[h]) break;
                l++;
                h--;
            }
            
            
            
            if(l>=h) return s;
        }
        
        return "";
    }
};