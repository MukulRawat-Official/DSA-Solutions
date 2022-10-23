class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>m;
        int n = nums.size();
        
        for(int i = 1;i<=n;i++)m[i]++;
        for(auto& x : nums) m[x]--;
        vector<int>a;
        vector<int>miss;
        for(auto [u,v] : m)
        {
            if(v>0) miss.push_back(u);
            else if(v<0) a.push_back(u); 
        }
        for(auto& x : miss) a.push_back(x);
        return a;
    
    }
};