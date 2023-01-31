class Solution {
public:
    int bestTeamScore(vector<int>& score, vector<int>& age ) {
        int n = score.size();
        vector<int>id(n,0);
        iota(id.begin(),id.end(),0);
        sort(id.begin(),id.end(),[&](int a, int b){
             if(age[a] != age[b])
            return age[a]<age[b];
            return score[a] < score[b];
        });
        
        vector<int>dp(n,0);
        /*
           pair<int,int> dp[i] = maximum value we get till idx i considering first i scores
           and i idx having maximum score
          Transition :- 
          
           dp[i] = dp[i-1]
           
           Base case = dp[0] = 0;
           final :- dp[n][n]
        */
        
        for(int i_id = 0;i_id<n;i_id++){
               int i = id[i_id];
               dp[i_id] = score[i];
            for(int j_id = 0;j_id<i_id;j_id++){
               int j = id[j_id];  
                
               if(score[i] >= score[j])    dp[i_id] = max(dp[i_id] , dp[j_id] + score[i]);
               
            }
        }
       return *max_element(dp.begin(),dp.end());
        
        
    }
};