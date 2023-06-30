class Solution {
public:
    typedef long long ll;
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size() , m = b.size(); 
        vector<int>bidx(m,0);
        priority_queue<vector<int>>pq;
        for(int i = 0;i<n;i++){
            pq.push({-a[i] - b[0] , i , 0});
        }
        
        vector<vector<int>>ans;
        while(pq.size() && k > 0){
           auto tmp = pq.top(); pq.pop();
           ans.push_back({a[tmp[1]] , b[tmp[2]]});
           if(tmp[2] + 1 < m){
               tmp[2]++;
               pq.push({-a[tmp[1]] - b[tmp[2]] , tmp[1] , tmp[2]});
           }
           k--;
        }
        
        return ans;
    }
};