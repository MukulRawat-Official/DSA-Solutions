class Solution {
public:
    string reverseVowels(string s) {
        string tmp = "";
        
        for(auto& x : s){
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x =='A' || x == 'E'|| x == 'I' || x == 'O' || x == 'U'){
                tmp += x;
            }
        }
        
        reverse(tmp.begin(),tmp.end());
        
        string ans = "";
        int idx = 0;
        for(auto& x : s){
            
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x =='A' || x == 'E'|| x == 'I' || x == 'O' || x == 'U'){
                ans += tmp[idx++];
            }
            else 
            ans += x;
        }
        
        return ans;
    }
};