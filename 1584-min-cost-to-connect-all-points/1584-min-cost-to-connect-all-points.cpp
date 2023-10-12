class Solution {
public:
    vector<int>par;
    int comp;
    int find(int a){
        if(par[a] == a) return a;
        return par[a] = find(par[a]);
    }
    
    int join(int a, int b){
        a = find(a);
        b = find(b);
        
        if(a == b) return 0;
        par[a] = b;
        --comp;
        return 1;
    }
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int ans = 0 , n = arr.size();
        par.resize(n,0);
        iota(par.begin(),par.end(),0);
        priority_queue<vector<int>>pq;
        vector<int>tmp(3,0);
        comp = n;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                tmp[0] = abs(arr[i][0] - arr[j][0])  +  abs(arr[i][1] - arr[j][1]);
                tmp[0] = -tmp[0];
                tmp[1] = i;
                tmp[2] = j;                                    
                pq.push(tmp);                                                             
            }
        }
        
     
        while(pq.size() && comp > 1)
        {
           auto arr = pq.top(); pq.pop();
           if(join(arr[1] , arr[2])){
               // cout<<arr[0]<<" ";
               ans -= arr[0]; 
           }
        }
        
        
        
        return ans;
        
    }
};