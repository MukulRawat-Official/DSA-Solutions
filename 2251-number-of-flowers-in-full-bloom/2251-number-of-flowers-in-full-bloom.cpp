class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>a , b;
        
        for(auto& x : flowers){
            a.push_back(x[0]);
            b.push_back(x[1]);
        }
        
        vector<int>ans;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        
        for(auto& x : people){
           int curr = lower_bound(a.begin(),a.end() , x + 1) - a.begin();
           int dlt =  lower_bound(b.begin(),b.end() , x) - b.begin();
            
           ans.push_back(curr - dlt);
        }
        
        return ans;
    }
};