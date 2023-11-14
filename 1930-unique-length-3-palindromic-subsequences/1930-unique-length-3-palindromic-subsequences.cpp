class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int>left(26,0) , right(26,0);
        long long ans = 0;
        vector<unordered_set<char>>cnt(26);
        for(int i = 1;i<n;i++) right[s[i] - 'a']++;
        for(int i = 1;i<n;i++) {
           right[s[i] - 'a']--;
           left[s[i-1] - 'a']++;
           for(int j = 0;j<26;j++){
               if(left[j] && right[j]){
                   cnt[j].insert(s[i]);
               }
           }
        }
        
        for(auto& x : cnt) ans += x.size();
        return ans;
    }
};