class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int n =  arr.size();
        map<int,int>mp;
        int ans = 0 , c = 0 , l = 0 , prv = 1;
        
        for(auto& x : arr){
            mp[x]++;
            
            if(mp.size() > k){
                c = 0;
                while(mp.size() > k)    if(mp[arr[l]] == 1) mp.erase(arr[l++]);
                else mp[arr[l++]]--;
                prv = 1;
            }
            if(mp.size() == k){
                
                while(mp[arr[l]] > 1){
                    mp[arr[l++]]--;
                    prv++;
                }
                ans += prv;
            }
        }
        
        return ans;
        
    }
};