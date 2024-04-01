class Solution {
public:
    int lengthOfLastWord(string s) {
        
        s+= " ";
        
        
        int ans = 0  ,cnt = 0;
        
        for(auto& x: s)
        {
            if(x != 32)
                cnt++;
            
            else
            {
                ans = cnt == 0 ? ans : cnt;
                cnt = 0;
            }
        }
        
        return ans;
        
    }
};