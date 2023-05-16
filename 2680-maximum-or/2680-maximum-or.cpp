class Solution {
public:
    typedef long long ll;
    long long maximumOr(vector<int>& arr, int k) {
        int n = arr.size();
        vector<ll> pref(n,0) , suff(n,0);
        pref[0] = arr[0]; suff[n-1] = arr[n-1];
        for(int i = 1;i<n;i++) pref[i] = arr[i] | pref[i-1];
        for(int i = n-2;i>=0;i--) suff[i] = arr[i] | suff[i+1];
        
        ll ans = 0;
        
        for(int i =0;i<n;i++){
            ll curr =1ll*  arr[i] << k;
            if(i) curr |= pref[i-1];
            if(i + 1 < n) curr |= suff[i+1];
            ans = max(ans,curr);
        }
        return ans;
        
    }
};