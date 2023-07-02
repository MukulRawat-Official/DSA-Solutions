class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& arr) {
       int ans = 0;
       int m = arr.size();
       for(int i = 0;i<(1<<m);i++){
           vector<int>f(n,0);
           for(int j = 0;j<m;j++){
               if(i & (1<<j)){
                   int s = arr[j][0];
                   int e = arr[j][1];
                   f[s]--;
                   f[e]++;
               }
           }
           int bal = 0;
           for(auto& x : f) bal |= (x != 0);
           if(!bal) ans = max(ans,__builtin_popcount(i));
       }
        
       return ans;
    }
};