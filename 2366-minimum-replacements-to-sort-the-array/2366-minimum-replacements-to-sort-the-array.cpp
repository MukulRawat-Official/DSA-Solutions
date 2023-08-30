class Solution {
public:
    typedef long long ll; 
    long long minimumReplacement(vector<int>& arr) {
        int n = arr.size();
        ll ans = 0 , curr = arr.back();
        
        for(int i =n-2;i>=0;i--){
            
            ll f = arr[i] / curr + (arr[i] % curr > 0);
            ans += f - 1;
            curr = arr[i] / f;
        }
        
        return ans;
    }
};