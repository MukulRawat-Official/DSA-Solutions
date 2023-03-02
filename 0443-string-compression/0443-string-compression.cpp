class Solution {
public:
    
    int compress(vector<char>& chars) {
       int prv = chars[0] , cnt = 0 , ans = 0;
        chars.push_back('x');
        int idx = 0;
        for(auto& x : chars){
           if(x == prv) cnt++;
           else{
               chars[idx++] = prv;
               if(cnt>1){
               string s =to_string(cnt);
               for(auto& x : s) chars[idx++] = x;
               ans +=  s.size() + 1;
               }
               else ans++;    
               cnt = 1;
           }
            
           prv = x;
        }
        
        while(chars.size() > idx) chars.pop_back();
        
        return ans;
    }
};