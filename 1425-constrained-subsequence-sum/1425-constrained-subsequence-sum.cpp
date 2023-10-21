class Solution {
public:
    typedef long long ll;
    int constrainedSubsetSum(vector<int>& arr, int k) {
        deque<pair<ll,ll>>dq;
        ll n = arr.size();
        ll ans = -1;
        for(int j = 0;j<n;j++){
           ll curr = arr[j];
           
           while(dq.size() &&  j - dq.front().second > k) dq.pop_front();
           if(dq.size()) curr += dq.front().first;
           ans = max(ans,curr);
            
           while(dq.size() && dq.back().first <= curr) dq.pop_back();
           if(curr >= 0) dq.push_back({curr,j});
        }
        
        return ans;
    }
};