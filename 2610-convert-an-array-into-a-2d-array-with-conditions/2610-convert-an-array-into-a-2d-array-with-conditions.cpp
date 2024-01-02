class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mp;
        
        for(auto& x : nums) mp[x]++;
        
        vector<vector<int>>ans;
        
        while(mp.size()){
            vector<int>tmp;
            
            auto it = mp.begin();
            
            while(it != mp.end()){
                tmp.push_back(it->first);
                if(it->second > 1) it->second-- , it++;
                else{
                    auto it2 = it;
                    it++;
                    mp.erase(it2->first);
                }
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};