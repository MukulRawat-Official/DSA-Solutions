class Solution {
public:
    

    int minimumDeviation(vector<int>& arr) {
        for(auto& x : arr)  if(x&1) x<<=1;
        
        int mn = INT_MAX;
        priority_queue<int>pq;
        for(auto& x : arr) pq.push(x) , mn = min(x,mn);
        
        int ans = INT_MAX;
        
        while(1) 
        {
            int curr = pq.top(); pq.pop();
            ans = min(ans , curr - mn);
            // cout<<curr<<" "<<mn<<" "<<ans<<endl;
            if(curr & 1) break;
            curr >>= 1;
            mn = min(curr,mn);
            pq.push(curr);
            
        
        }
        
        return ans;
    }
};