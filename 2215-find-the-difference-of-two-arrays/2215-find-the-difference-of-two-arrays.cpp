class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>a(2);
        map<int,int>m,n;
        for(auto& x : nums1) m[x]++;
        for(auto& x : nums2) n[x]++;
        for(auto& x : m) if(!n.count(x.first)) a[0].push_back(x.first);
        for(auto& x : n) if(!m.count(x.first)) a[1].push_back(x.first);
        return a;
    }
};