class Solution {
public:
    
    
    bool closeStrings(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        if(n != m) return 0;
        vector<int>a(26,0) , b(26,0);
   
        for(auto& x : word1) a[x-'a']++;
        for(auto& x : word2) b[x-'a']++;
        for(int i = 0;i<26;i++){
            if((a[i] && b[i]) ||(!a[i] && !b[i])) continue;
            return 0;
        }
        map<int,int>mp;
        for(auto& x: a) mp[x]++;
        for(auto& x: b) {
            if(!mp.count(x)) return 0;
            if(mp[x] > 1) mp[x]--;
            else mp.erase(x);
        }
        
        return 1;
    }
};