class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int>arr(n) , id(n);
        
        for(int i = 0;i<n;i++){
            for(auto& x : mat[i]) arr[i] += x; 
            id[i] = i;
        }
        
        sort(id.begin(),  id.end() , [&](int a, int b){
            if(arr[a] == arr[b]) return a < b;
            return arr[a] < arr[b];
        });
        
        while(id.size() > k) id.pop_back();
        
        return id;
        
    }
};