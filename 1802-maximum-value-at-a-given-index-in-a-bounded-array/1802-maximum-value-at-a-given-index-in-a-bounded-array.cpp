class Solution {
public:
    
    int maxValue(int n, int index, int maxSum) {
        long long  l = index , r = (n - 1 - index);
        
        int left = 0 , right = maxSum + 1;
        auto chk = [&](int val)->bool{
            long long ll = l * (l+1)   / 2;
            long long rr = r * (r + 1) / 2;
           long long curr = 1ll * n * val - (ll + rr);
           long long d = 0;    
            if(l > val - 1){
              d = (l + 1 - val);
              curr += d * (d + 1) / 2;
            }
            if(r > val - 1){
                d = (r + 1 - val);
                curr += d * (d + 1) / 2;
            }
           return curr <= maxSum;
        };    
        while(right - left > 1){
            int mid = (right + left) / 2;
            
            if(chk(mid)) left = mid;
            else right = mid;
        }
        
        return left;
    }
};