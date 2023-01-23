class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) return 1;
        map<int,int>r , l;
        
        for(auto& x : trust){
           r[x[1]]++;
           l[x[0]]++;
        }
        
        for(auto& x : r){
            if(x.second == n-1 && !l.count(x.first)) return x.first;
        }
        
        return -1;
    }
};