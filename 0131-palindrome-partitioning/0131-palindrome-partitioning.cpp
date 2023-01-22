class Solution {
public:
    bool chk(string& s){
        if(!s.size()) return 0;
        int l = 0 , h = s.size() -1;
        while(l<h){
            if(s[l++] != s[h--]) return false;
        }
        return true;
    }
    vector<vector<string>>ans;
    void dfs(string& s , string& curr , int idx , vector<string>& tmp){
        if(idx == s.size()){
            if(chk(curr)) { tmp.push_back(curr); ans.push_back(tmp); tmp.pop_back();}
            return;
        }
        curr.push_back(s[idx]);
        if(chk(curr)) { 
            tmp.push_back(curr); 
            curr = "";
            dfs(s,curr,idx+1,tmp);
            curr = tmp.back(); tmp.pop_back();
        }
        
        dfs(s,curr,idx+1,tmp);
        curr.pop_back();
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>tmp;
        string curr;
        dfs(s,curr,0,tmp);
        return ans;
    }
};