class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int t) {
      
       int it = lower_bound(arr.begin(),arr.end(),t) - arr.begin();
       if(it == arr.size() || arr[it] != t) return {-1,-1};
       int it2 = lower_bound(arr.begin(),arr.end(),t+1) - arr.begin() - 1;
       return {it,max(it,it2)};  
    }
};