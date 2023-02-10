class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string>st;
        auto give = [&](string& s){
            int idx = 0;
            for(auto& x : s) if(x == '@') break; else idx++;
            
            string lft = s.substr(0,idx);
            string curr = "";
            for(auto& x : lft) {
                if(x == '.') continue; 
                else if(x == '+') break;
                else curr.push_back(x);
            }
            
            curr += s.substr(idx);
            st.insert(curr);
        };
        for(auto& x : emails)    give(x);
        return st.size();
    }
};