class Solution {
public:
    int searchInsert(vector<int>& n, int t) {
        auto it = lower_bound(n.begin(),n.end(),t);
        
        return it - n.begin();
    }
};