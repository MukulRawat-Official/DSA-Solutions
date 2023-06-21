class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<ll>arr , freq , id(n,0);
        iota(id.begin() , id.end() , 0);
        sort(id.begin() , id.end() , [&](ll a , ll b){
           return nums[a] < nums[b]; 
        });
        
        for(int i = 0;i<n;i++){
            int idx = id[i];
            if(arr.size() && arr.back() == nums[idx])    freq.back()+= cost[idx];
            else {
                arr.push_back(nums[idx]);
                freq.push_back(cost[idx]);
            }
        }
      
        n = arr.size();
        vector<ll>pref(n ,0) , suff(n,0);
        ll curr = 0 , sm = 0;
        for(int i = 0;i<n;i++){
            ll d = i ? arr[i] - arr[i-1] : 0;
            curr += sm * d;
            pref[i] = curr;
            sm += freq[i];
         } curr = 0; sm = 0;
        for(int i = n-1;i>=0;i--){
            ll d = i + 1 < n ? arr[i+ 1] - arr[i] : 0;
            curr += sm * d;
            suff[i] = curr;
            sm += freq[i];
        }
        
        ll ans = -1;
        for(int i = 0;i<n;i++){
            if(ans == -1) ans = pref[i] + suff[i];
            else ans = min(ans,pref[i] + suff[i]);
        }
        return ans;
    }
};