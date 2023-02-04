class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int>curr(26,0),hv(26,0);
       for(auto& x : s1) curr[x-'a']++;
       
       int rng = s1.size() , m = s2.size();
        
       for(int i = 0;i<min(m,rng);i++)hv[s2[i]-'a']++;
       if(curr == hv) return true;
        
       for(int i = rng;i<m;i++){
           hv[s2[i]-'a']++; hv[s2[i-rng]-'a']--;
           if(curr == hv) return true;
       }
           
       return false;
    
    }
};