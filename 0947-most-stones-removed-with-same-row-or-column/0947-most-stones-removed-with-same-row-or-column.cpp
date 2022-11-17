class Solution {
public:
    int recurr(map<int,set<int>>&x, map<int,set<int>>&y , pair<int,int>&p ,  map<pair<int,int>,int>& vis){
        int ans = 1;
        
        for(auto& t : x[p.first]){
            if(vis.count({p.first,t})) continue;
            vis[{p.first,t}];
            pair<int,int> tmp = {p.first,t};
            ans += recurr(x,y,tmp,vis);
        }
                        
       for(auto& t : y[p.second]){
            if(vis.count({t,p.second})) continue;
            vis[{t,p.second}];
            pair<int,int> tmp = {t,p.second};
            ans += recurr(x,y,tmp,vis);
        }
        
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        map<int,set<int>> xgraph , ygraph;
        map<pair<int,int>,int> vis;
        for(auto& x : stones){
            xgraph[x[0]].insert(x[1]);
            ygraph[x[1]].insert(x[0]);
        }
        int ans = 0;
 
        for(auto& x : stones){
            if(vis.count({x[0],x[1]})) continue;
            vis[{x[0],x[1]}];
            pair<int,int> tmp = {x[0],x[1]};
            ans += recurr(xgraph,ygraph,tmp,vis)-1;
        }
        
        return ans;
        
    }
};