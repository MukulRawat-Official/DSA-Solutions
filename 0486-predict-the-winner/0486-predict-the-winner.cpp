class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        auto recurr= [&](int i , int j , int t , auto&& recurr)->int{
          if(i == j) return t * nums[i];
          
           int first = recurr(i+1,j,1-t,recurr) + (t == 1? 1 : -1) * nums[i];
           int second = recurr(i,j-1,1-t,recurr) + (t == 1? 1 : -1) * nums[j];
           int ans = 0;
           if(t) ans = max(first,second);
           else ans = min(first,second);
            
           return ans;
        };
        
        return recurr(0,nums.size()-1,1,recurr) >= 0;
    }
};