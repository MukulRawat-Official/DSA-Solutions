class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bits(32,0);
        int neg = 0;
        for(auto& t : nums){
            int idx = 0;
            long x = abs(t);
            if(t < 0) neg++;
            while(x){
                if(x & 1){bits[idx] = (bits[idx] + 1) % 3;}
                x>>=1;
                idx++;
            }
        }
        
        long f = 1 , ans = 0;
        
        for(auto& x : bits){
            ans += x * f;
            f *= 2;
        }
        neg = neg % 3;
        return (neg ? -1 : 1) * ans;
    }
};