class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        map<int,vector<char>> f;
        
        for(auto& x : s) m[x]++;
        for(auto& x : m) f[x.second].push_back(x.first);
        string ans = "";
        for(auto& x : f){
             for(auto& t : x.second){
                string tmp(x.first ,t);
                 ans += tmp;
             }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};