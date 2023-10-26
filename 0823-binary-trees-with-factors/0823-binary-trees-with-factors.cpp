class Solution {
public:
    typedef long long ll;
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll n = arr.size();
        sort(arr.begin() , arr.end());
        
        ll ans = 0 , mod = 1e9 + 7;
        map<ll,ll>st;
        for(auto& x : arr){
            st[x] = 1;
            for(int fac = 1; fac * fac <= x; fac++){
                if(x % fac) continue;
                int a = fac , b = x / fac;
                
                if(a == b){
                    if(st.count(a)) {
                        ll ways = st[a];
                        st[x] +=  ways * ways % mod;
                    }
                }
                else {
                    if(st.count(a) && st.count(b)){
                        ll ways = 2ll * st[a] * st[b] % mod;
                        st[x] += ways % mod;
                    }
                }
            }
            
            ans = (ans + st[x]) % mod;
            
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};