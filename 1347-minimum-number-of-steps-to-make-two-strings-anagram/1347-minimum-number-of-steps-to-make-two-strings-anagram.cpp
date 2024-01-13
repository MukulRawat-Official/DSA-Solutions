class Solution {
public:
    int minSteps(string s, string t) {
        int cnt = 0;
        unordered_map<int,int>mp;
        
        for(auto& x : s) mp[x]++;
        for(auto& x : t) mp[x]--;
        for(auto& [x,f] : mp) cnt += abs(f);
        
        return cnt / 2;
    }
};