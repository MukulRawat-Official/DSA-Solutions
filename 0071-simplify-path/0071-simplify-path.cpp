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
            rev.push(st.top());
            st.pop();
        }
        while(rev.size()){
            ans += rev.top();
            rev.pop();
        }
        if(ans.size() > 1)ans.pop_back();
        return ans;
    }
};