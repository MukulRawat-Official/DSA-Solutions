class Solution {
public:
    int equalPairs(vector<vector<int>>& arr) {
        map<vector<int> , int>mp;
        int n = arr.size();
        for(int j = 0;j<n;j++){
            vector<int>tmp;
            for(int i = 0;i<n;i++) tmp.push_back(arr[i][j]);
            mp[tmp]++;
        }
        
        int ans = 0;
        for(auto& x : arr){
            if(mp.count(x)) ans += mp[x];
        }
        
        return ans;
    }
};