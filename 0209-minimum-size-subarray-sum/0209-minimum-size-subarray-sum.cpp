class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
       int n = arr.size() , l = 0;
       long long sum = 0 ,ans = n + 1;
       
       for(int i = 0; i<arr.size();i++){
           sum += arr[i];
           while(sum - arr[l] >= target)    sum -= arr[l++];
           if(sum >= target)     ans = min(ans , 1ll * i - l + 1);
       }
        
       return (ans == n + 1 ? 0 : ans);
    }
};