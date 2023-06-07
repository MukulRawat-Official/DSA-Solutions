class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0;i<31;i++){
         int mask = (1 << i);
            int f = (a & mask) > 0;
            int s = (b & mask) > 0;
            int t = (c & mask) > 0;
           
            if( (f | s) == t) continue;
            else if(t)ans++;
            else ans += (f + s);
        }
        
        return ans;
    }
};