class Solution {
public:
    int n;
    int recurr(string curr , string end , vector<string>&bnk,map<string,int>vis){
       if(curr == end){
           return 0;
       }
       
       int ans = 1000;
       for(auto& x : bnk){
           int cnt =  0;
          for(int i = 0;i<n;i++){
              if(x[i] != curr[i]) cnt++;
          }
           
          if(cnt == 1 && !vis.count(x)){
              vis[x] = 1;
              ans = min(ans , recurr(x,end,bnk,vis)+1);
          }
       }
        
       return ans;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(bank.size() == 0){
            if(startGene == endGene) return 0;
            return -1;
        }
        n = bank[0].size();
         map<string,int>vis;
        long ans =  recurr(startGene,endGene,bank,vis);
        if(ans > 15) return -1;
        return ans;
    }
};