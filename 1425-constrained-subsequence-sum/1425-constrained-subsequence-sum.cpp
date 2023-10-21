class Solution {
public:
    typedef long long ll;
    int constrainedSubsetSum(vector<int>& arr, int k) {
        priority_queue<pair<ll,ll>>pq;
        ll n = arr.size();
        ll ans = -1;
        for(int j = 0;j<n;j++){
            while(pq.size() && j - k > pq.top().second) pq.pop();
            ll curr = arr[j];
            if(pq.size()) curr += pq.top().first;
            ans = max(ans,curr);
            if(curr >= 0) pq.push({curr,j});
        }
        
        return ans;
    }
};