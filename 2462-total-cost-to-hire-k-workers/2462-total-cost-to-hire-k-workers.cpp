#define pq_dec(i) priority_queue<i,vector<i>, greater<i>>
class Solution {
public:
    long long totalCost(vector<int>& arr, int k, int cd) {
        // map<pair<int,int>,int> mp;
         priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>l,r;
        int n = arr.size();
        
        for(int i = 0;i<min(n,cd);i++){
            l.push({arr[i],i});
        }
        
        for(int i = max({0,n-cd,cd}); i<n;i++){
            r.push({arr[i],i});
        }
        
        long long  ans = 0 , lidx = min(cd-1,n-1) , ridx = max({0,n-cd,cd});
        // cout<<lidx<<" "<<ridx<<endl;
        
        while(k--){
           
            
            int ll = INT_MAX , rr = INT_MAX;
            
            if(l.size())
                ll = l.top().first;
            if(r.size())
                rr = r.top().first;
            
            if(ll < rr){
                ans += ll;
                l.pop();
               if(lidx < n-1 && lidx + 1<ridx){
                    lidx++;
                    l.push({arr[lidx],lidx});
                }
            }
            
            else if(rr < ll){
                ans += rr;
                r.pop();
                if(ridx && ridx-1>lidx) {
                    ridx--;
                    r.push({arr[ridx],ridx});
                }
            }
            
            else{
                 ans += ll;                                 
              
                
               if(l.top().second < r.top().second) {
                  l.pop();
                if(lidx < n-1 && lidx+1<ridx){
                    lidx++;
                    l.push({arr[lidx],lidx});
                }
               }
                
               else { 
                r.pop();
                 if(ridx && ridx-1>lidx) {
                    ridx--;
                    r.push({arr[ridx],ridx});
                }  
               }
            }
            
            
        }
        
        return ans;
        
        
    }
};