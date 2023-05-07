class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) {
       vector<int>cnt;
       vector<int>ans;
        for(auto& x : arr){
            auto it = upper_bound(cnt.begin(),cnt.end() , x);
            int idx = it - cnt.begin();
            if(it == cnt.end()) cnt.push_back(x);
            else  cnt[idx] = x;
            
            ans.push_back(idx + 1);
        }
        
        return ans;
    }
};