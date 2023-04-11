class Solution {
public:
    string removeStars(string s) {
        string st;
        
        for(auto& x : s){
             if(x == '*'){
                 if(st.size()) st.pop_back();
             }
            
             else st.push_back(x);
        }
        
        return st;
    }
};