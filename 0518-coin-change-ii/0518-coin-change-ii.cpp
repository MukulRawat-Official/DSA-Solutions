class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++)
                    prev[i]=0;
    
       prev[0]=1;
            
        for(int i=1;i<=n;i++) // indext
        {
          for(int j=1;j<=amount;j++)
            {
                int notTake= prev[j];
                int take=0;
                if(coins[i-1]<=j)
                    take=prev[j-coins[i-1]];
                
                prev[j]=take+notTake;
            }
        }
        return prev[amount];
    
    }
};