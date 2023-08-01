class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
       
        
        for(int i = 1;i<(1<<n);i++){
            vector<int>arr;
            for(int j = 0;j<n;j++){
                if( i & (1<<j)) arr.push_back(j+1);
            }
            if(arr.size() == k) ans.push_back(arr);
        }
        
        return ans;
    }
};