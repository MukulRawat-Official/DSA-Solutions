class Solution {
public:
    int countHomogenous(string s) {
        long long c = 0 , prv = '1';
        s.push_back('1');
        long long ans = 0 , mod = 1e9 + 7;
        for(auto& x : s){
            if(x != prv){
                ans += c * (c+1) / 2 % mod;
                ans %= mod;
                c = 1;
            }
            else c++;    
            prv = x;
        }
        
        return ans;
    }
};