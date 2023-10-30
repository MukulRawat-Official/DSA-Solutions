class Solution {
public:
    #define f(x) (__builtin_popcount(x)) 
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            if(f(a) == f(b)) return a < b;
            return f(a) < f(b);
        });
        
        return arr;
    }
};