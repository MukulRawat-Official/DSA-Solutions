class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>f,s;
        for(auto& x : arr)f[x]++;
        for(auto& x : f) {
            if(s.count(x.second)) return 0;
            s[x.second]++;
        }
        
        return 1;
    }
};