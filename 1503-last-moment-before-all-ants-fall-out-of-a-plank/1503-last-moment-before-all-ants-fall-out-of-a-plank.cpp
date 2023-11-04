class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        
        for(auto& x : right){
            ans = max(ans , n - x);
        }
        for(auto& x : left){
            ans = max(ans , x );
        }
        
        return ans;
    }
};