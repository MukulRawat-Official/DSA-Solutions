class Solution {
public:
    typedef long long ll;
    int maxIncreasingGroups(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        ll sum = 0 , ans = 1;
        for(auto& x : arr){
            sum += x;
            if(sum >= ans){
                sum -= ans;
                ans++;
            }
        }
        
        return ans-1;
    }
};