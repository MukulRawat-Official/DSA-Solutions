class Solution {
public:
    double soupServings(int n) {
        if(n > 1e4 - 1) return 1;
        map<pair<int,int> , double>mp;
        function<double(int,int)> recurr = [&](int a , int b)->double{
           if(!a && !b) return 0.5;
           if(!a) return 1;
           if(!b) return 0;
           
           if(mp.count({a,b})) return mp[{a,b}];
           int aa = 100 , bb = 0;
           double ans = 0;
           for(int i = 0;i<4;i++){
               ans += 0.25 * recurr(a- min(a , aa) , b - min(b,bb));
               aa -= 25;
               bb += 25;
           }
            
           return mp[{a,b}] = ans;
        };
        
        return recurr(n,n);
    }
};