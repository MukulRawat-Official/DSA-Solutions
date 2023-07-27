class Solution {
public:
    typedef long long ll;
    long long maxRunTime(int n, vector<int>& arr) {
        long long low = 0 , high = 1;
        for(auto& x : arr) high += x;
        auto chk = [&](ll mid)->bool{
           ll ctr = n * mid; 
           for(auto& x : arr) ctr -= min(mid , 1ll * x);
           return ctr<1;
        };
        while(high - low > 1){
            ll mid = (high + low) >> 1;
            
            if(chk(mid)) low = mid;
            else high = mid;
        }
        
        return low;
    }
};