class Solution {
public:
    
    vector<long long>hash , poly;
    const int mod = 1e9 + 7;
    const long long p = 30;
    typedef long long ll;
    ll expo(ll a, ll b){
        ll ans = 1;
        
        while(b){
            if(b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        
        return ans;
    }
    int deleteString(string s) {
        
        long long n = s.size() , f = 1;
        hash.resize(n);
        
        // a = 1 , z = 26 
        for(int i = 0;i<n;i++){
            if(i) hash[i] = hash[i-1];
            hash[i] = (hash[i] + 1ll* f * (s[i] - 'a') % mod) % mod;
            poly.push_back( expo(f , mod - 2));
            f = (1ll * f * p) % mod;
        }
        
        
        vector<int>dp(n);
        
        function<int(int,int)> give = [&](int l , int r){
            int val = hash[r];
            if(l) {
                val = (val - hash[l-1]) * poly[l] % mod;
                val = (1ll * val + mod) % mod;
            }
            
            return val;
        };
        
        // cout<<give(0,2)<<" "<<give(3,5)<<" "<<give(6,8)<<endl;
        
        for(int i = n-1;i>=0;i--)
        {
            dp[i] = 1;
            for(int j = i; 2 * j  - i + 1<n;j++){
                int curr = give(i,j) , res = give(j+1 , 2 * j - i + 1);
                if(curr == res){
                    dp[i] = max(dp[i] , dp[j+1] + 1);
                }
            }
        }
        
        return dp[0];
    }
};