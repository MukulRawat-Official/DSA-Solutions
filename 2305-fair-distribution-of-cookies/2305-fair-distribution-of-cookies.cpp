class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        function<int(int,vector<int>&)> recurr = [&](int i , vector<int>& arr){
          if(i == cookies.size()){
              int val = 0;
              for(auto& x : arr) val = max(x, val);
              return val;
          }  
            
          int ans = INT_MAX;
          for(int j = 0;j<k;j++){
              arr[j]+=cookies[i];
              ans = min(ans, recurr(i+1,arr));
              arr[j]-=cookies[i];
          }
            
          return ans;
        };
        
        vector<int>tmp(k,0);
        return recurr(0,tmp);
    }
};