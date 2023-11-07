class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size(); 
        vector<int>idx(n);
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin() , idx.end() , [&](int a , int b){
             a = (dist[a] + speed[a] - 1) / speed[a];
             b = (dist[b] + speed[b] - 1) / speed[b];
             return a < b;
        });
        
        int curr = 0 , time = 0;
        
        for(auto& x : idx){
            x = (dist[x] + speed[x] - 1) / speed[x];
            if(x <= time) break;
            else time++;
        }
        
        return time;
    }
};