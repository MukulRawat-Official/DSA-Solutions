class Solution {
public:
    stack<char> give(string& s){
        stack<char>st;
        for(auto& x : s){
            if(x == '#') { if(st.size()) st.pop();}
            else st.push(x);
        }
        return st;
    }
    bool backspaceCompare(string s, string t) {
        auto a = give(s);
        auto b = give(t);
        
        return a == b;
    }
};