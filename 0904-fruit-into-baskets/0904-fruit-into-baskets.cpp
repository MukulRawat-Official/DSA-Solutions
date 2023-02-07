class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size();
        vector<int>typ(2,-1);
        vector<int>idx(2,-1);
        int cnt = 0 , ans = 0;
        for(int i = 0;i<n;i++){
            int x = arr[i];
            cnt++;
            if(typ[0] == -1)    typ[0] = x;
            else if(typ[1] == -1) typ[1] = x;
            else if(typ[0] != x && typ[1] != x)
            {
                if(idx[0] > idx[1]){
                    typ[1] = x;
                    cnt = (i-idx[1]);
                }
                
                else{
                    typ[0] = x;
                    cnt = (i - idx[0]);
                }
            }
                  
            
            
            if(typ[0] == x) idx[0] = i;
            else idx[1] = i;
            ans = max(ans,cnt);
        }
        
        return ans;
    }
};