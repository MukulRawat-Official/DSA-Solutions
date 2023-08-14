class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<long>p;
        
        for(auto& x : nums)
        p.push(x);
        
        int c = 1;
        
        while(c != k)
        {
            c++;
            p.pop();
        }
        
        return p.top();
    }
};