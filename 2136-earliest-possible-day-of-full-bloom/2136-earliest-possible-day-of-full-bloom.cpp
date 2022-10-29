class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
     vector<pair<int,int>>arr;
     int n = p.size();
        
     for(int i = 0;i<n;i++) arr.push_back({g[i]+1,p[i]});
     sort(arr.rbegin(),arr.rend());
    
     int mxm = 0 , curr = -1;
        
     for(int i = 0;i<n;i++)
     {
         curr += arr[i].second;
         mxm = max(mxm , curr + arr[i].first);
         // cout<<arr[i].first<<" "<<arr[i].second<<" ";
     }
        
     return mxm;
     
    }
};