class Solution {
public:
    bool isPowerOfFour(int n) {
        int cnt = 0;
        while(n % 2 == 0 && n){
            n /= 2;
            cnt++;
        }
        
        return !(cnt & 1) && (n == 1);
    }
};