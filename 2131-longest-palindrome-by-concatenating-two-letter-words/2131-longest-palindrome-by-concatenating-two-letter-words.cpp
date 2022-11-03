class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        
        for(auto& x : words) mp[x]++;
        int o=  0 , e=  0  ,re = 0;
        
        for(auto& x : mp){
            // cout<<x.first<<" "<<x.second<<endl;
          if(x.first[0] == x.first[1]){
              re += x.second / 2 * 2;
              o |= x.second & 1;
          }
            
          else
          {
             string t = x.first;
             reverse(t.begin(),t.end());
             if(mp.count(t)){
                 int tt = min(mp[t],x.second);
                 e += tt;
             }
          }
        }
        
        // cout<<o<<" "<<e<<" "<<re<<endl;
        return 2 * (o + e + re);
        
    }
};