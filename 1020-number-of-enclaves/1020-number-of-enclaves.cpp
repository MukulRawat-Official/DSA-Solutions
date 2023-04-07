#define ll long long
class Solution {
public:
    int numEnclaves(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<int> l = {0,1,0,-1} , r = {1,0,-1,0};
        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!arr[i][j]) continue;
                queue<ll>q;
                
                q.push(1ll * i * m + j);
                arr[i][j] = 0;
                int cnt = 1;
                bool pos = 1;
                
                while(q.size()){
                    ll curr = q.front(); q.pop();
                    int i =  curr / m , j = curr % m;
                    
                    for(int k = 0;k<4;k++){
                        int x = i + l[k] , y = j + r[k];
                        
                        if(x < 0 || y < 0 || x == n || y == m){pos = 0; continue;}
                        if(!arr[x][y]) continue;
                        arr[x][y] = 0;
                        q.push(1ll * x * m + y);
                        cnt++;
                    } 
                }
                
                ans += pos * cnt;
                
            }
        }
        
        return ans;
        
    }
};