class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<int,int>mp;
        for(int i = 0;i<26;i++) mp[order[i]] = i;
        
        auto cmp = [&](string& a , string& b){
            int i = 0 , j = 0;
            
            while(i < a.size() && j < b.size()){
                if(a[i] == b[j]) {i++,j++; continue;}
                if(mp[a[i]] < mp[b[j]]) return true;
                return false;
           }
           
           return a.size() == b.size() || i == a.size();
        };
        
        
        for(int i = 1;i<words.size();i++){
            if(!cmp(words[i-1],words[i])) return false;
        }
        
        return true;
    }
};