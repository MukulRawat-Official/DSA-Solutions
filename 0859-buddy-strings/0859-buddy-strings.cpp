class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        if(n != goal.size()) return false;
        vector<int>arr;
        map<char,int>mp;
        for(int i = 0;i<n;i++){
            if(s[i] != goal[i]) arr.push_back(i);
            else mp[s[i]]++;
        }
        
        bool pos = 0;
        if( (arr.size() == 2) &&  (goal[arr[0]] == s[arr[1]]) && (goal[arr[1]] == s[arr[0]])) pos = 1;
        if(!arr.size()){
            for(auto& x : mp){
                pos |= x.second > 1;
            }
        }
        
        return pos;
    }
};