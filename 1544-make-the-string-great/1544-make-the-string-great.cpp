class Solution {
public:
    string makeGood(string s) {
        string ans  = "";
        
        for(auto& x : s){
            if(ans.size() && abs(ans.back()-x) == 32){
                ans.pop_back();
            }
            
            else ans.push_back(x);
        }
        
        return ans;
    }
};