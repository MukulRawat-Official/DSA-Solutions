class Solution {
public:
    long expo(long a , long  b , long mod){
        long ans = 1 , f = a;
      
        while(b){
            if(b & 1) ans *= f;
            f *= f;
            f %= mod;
            ans %= mod;
            b >>= 1;
        }
        
        return ans;
    }
    int numSubseq(vector<int>& arr, int t) {
        int mod = 1e9 + 7;
        int n = arr.size();
        sort(arr.begin() , arr.end());
        
        int l = 0 , h = n-1;
        long ans = 0;
        while(1){
            while(h >= l && arr[h] + arr[l] > t) h--;
            
            if(h >= l){
             int len = (h-l);
             ans = (ans + expo(2,len,mod)) % mod;
             l++;
            }
            
            else break;
        }
        
        return ans;
        
        
    }
};