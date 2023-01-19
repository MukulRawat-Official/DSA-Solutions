class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st,rev;
        string curr  = "";
        bool p = 0;
        if(path.back() != '/')
        path += '/'; 
        for(auto& x : path){
            if(x == '/'){
                if(st.size() == 0) {st.push("/"); p = 1;}
                else  
                {
                
                   if(curr !=  "..")
                   { if(curr.size() && curr != ".")st.push(curr + "/"); }
                    else if(st.size() > 1) st.pop();
                    curr.clear();
                }
            } 
            else curr += x;
        }
        
    
        
        string ans = "";
        
        while(st.size()) {
            string s = st.top();
            st.pop();
            reverse(s.begin(),s.end());
            ans += s;
        }
        reverse(ans.begin(),ans.end());
   
        if(ans.size() > 1)ans.pop_back();
        return ans;
    }
};