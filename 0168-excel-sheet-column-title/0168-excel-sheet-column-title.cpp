class Solution {
public:
    string convertToTitle(int x) {        
        string ans;
      
        
        while(x){
            x--;
            int r = x % 26;
            char ch = 'A' + r;
            ans.push_back(ch);
            x /= 26;    
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};