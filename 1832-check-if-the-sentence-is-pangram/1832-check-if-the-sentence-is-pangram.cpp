class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>arr(26,0);
        
        for(auto& x : sentence)
         arr[x-'a']++;
        
        
        for(auto x : arr) if(!x) return false;
        return 1;
    }
};