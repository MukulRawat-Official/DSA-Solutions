class Solution {
public:
    int countOdds(int low, int high) {
       if(low%2 == 0) low++;
        
       if(high < low) return 0;
       return (high - low) / 2 + (low&1);
    }
};