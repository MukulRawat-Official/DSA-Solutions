class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0 , ans = 0;
        for(int i = 30;i>=0;i--){
            set<int>s;
            mask |= (1<<i);
            for(auto& x : nums)  s.insert(x & mask);
            int curr_ans = ans | (1<<i);
            
            for(auto& x : s){
                if(s.count(x ^ curr_ans)){
                    ans = curr_ans;
                    break;
                }
            }
        }
        
        return ans;
    }
};