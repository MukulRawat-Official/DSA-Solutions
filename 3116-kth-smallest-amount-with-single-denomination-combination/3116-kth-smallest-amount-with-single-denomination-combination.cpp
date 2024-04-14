class Solution {
public:
    
    long long findKthSmallest(vector<int>& arr, int k) {
        typedef long long ll;
        int n = arr.size();
        
       
        
        vector<ll>fact( (1<<n), 0) , sign = fact;
        
        for(int i = 0;i<(1<<n);i++){
            ll curr = 1 , sn = 0;
            for(int j = 0;j<n;j++)
            {
               if( (1<<j) & i) {
                   sn ^= 1;
                   curr = curr * arr[j] / gcd(curr,arr[j]);
               }
            }
            
            fact[i] = curr;
            sign[i] = (sn ? 1 : -1);
        }
        
       
        auto give = [&](ll val)->ll{
            
            ll sum = 0;
            for(int i = 1;i<(1<<n);i++){
                sum += sign[i] * (val / fact[i]);
            }
            
            return sum;
        };
        
         ll l = 0 , h = 1e11;
        while(h - l > 1){
            ll mid = (h + l) >> 1;
            
            if( give(mid) >= k) h = mid;
            else l = mid;
        }
        
        return h;
        
    }
};