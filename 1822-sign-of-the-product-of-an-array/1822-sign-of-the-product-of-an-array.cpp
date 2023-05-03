class Solution {
public:
    int arraySign(vector<int>& nums) {
       int c = 0;
       for(auto& x : nums){
           if(x < 0) c++;
           else if(!x) return 0;
       } 
        
       return c & 1 ? -1 : 1;
    }
};