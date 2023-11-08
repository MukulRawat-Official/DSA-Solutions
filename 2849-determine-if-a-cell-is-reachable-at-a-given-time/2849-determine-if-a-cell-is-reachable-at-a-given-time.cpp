class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) return t != 1;
        int a = abs(fx - sx) , b = abs(sy - fy);
        
        return max(a,b) <= t;
        
    }
};