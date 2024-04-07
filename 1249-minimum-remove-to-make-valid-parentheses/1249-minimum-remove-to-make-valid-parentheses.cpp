class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        
        int c = 0;
        
        for(auto& x : s){
            if(x == ')') {
                if(c) { c--; ans.push_back(x);}
            }
            else if(x =='('){
                c++;
                ans.push_back(x);
            }
            else {
              ans.push_back(x);
            }
        }
        
        c = 0;
        s = ans;
        ans.clear();
        reverse(s.begin(),s.end());
        for(auto& x : s){
            if(x == '(') {
                if(c) { c--; ans.push_back(x);}
            }
            else if(x ==')'){
                c++;
                ans.push_back(x);
            }
            else {
              ans.push_back(x);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    
    }
};