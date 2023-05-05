class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        auto give = [&](int ch)->bool{
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
            return false;
        };
        
        
        int ans = 0 , cnt = 0;
        
        for(int i = 0;i<k;i++){
             cnt += give(s[i]);            
        }
        ans = max(ans,cnt);
        
        for(int i =k;i<n;i++){
            cnt += give(s[i]) - give(s[i-k]);
            ans = max(ans,cnt);
        }
        
        return ans;
    }
};