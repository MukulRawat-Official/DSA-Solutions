class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c = 0;
        for(auto& x : grid) for(auto& y : x) c += (y < 0);
        return c;
    }
};