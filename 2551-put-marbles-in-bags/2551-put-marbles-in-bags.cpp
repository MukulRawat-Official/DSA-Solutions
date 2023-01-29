typedef long long ll;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
      int n  = weights.size();
      vector<ll>arr;
      for(int i = 0;i<n-1;i++){arr.push_back(weights[i] + weights[i+1]);}
      sort(arr.begin(),arr.end());
      ll id = arr.size()-1 ,ans = 0;
      for(int i = 0;i<k-1;i++){
          ans +=  arr[id--] - arr[i]; 
      }
        
      return ans;
    }
};