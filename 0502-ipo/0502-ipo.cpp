class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pro, vector<int>& cap) {
         priority_queue<int>pq;
         int n = pro.size();
        vector<int>id(n,0);
        iota(id.begin(),id.end(),0);
        
        sort(id.begin(),id.end(),[&](int a, int b){
           if(cap[a] == cap[b]) return pro[a] > pro[b];
            return cap[a] < cap[b];
        });
        
        int get_id = 0;
        int ans = w;
        while(k--){
            while(get_id < n && cap[id[get_id]] <=  ans){
                pq.push(pro[id[get_id]]);
                get_id++;
            }
            
            if(pq.size()) ans += pq.top() , pq.pop();
            else break;
        
                          
        }
        
        return ans;
          
    }
};