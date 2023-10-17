class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
         vector<int>vis(n,0) , inc(n,0);
         vector<vector<int>>adj(n);
        
         for(int i = 0;i<n;i++){
             if(leftChild[i] != -1){
                 int u = i , v = leftChild[i];
                 adj[u].push_back(v);
                 inc[v]++;
             }
             if(rightChild[i] != -1){
                 int u = i , v = rightChild[i];       
                 adj[u].push_back(v);
                 inc[v]++;
             }
         }
          
         int st = 0;
        
         for(int i = 1;i<n;i++){
             if(!inc[i]) st = i;
         }
     
            queue<int>q;
            q.push(st);
            vis[st] = 1;
            while(q.size()){
                int curr = q.front(); q.pop();
                for(auto& x : adj[curr]){
                    if(vis[x]) return false;
                    q.push(x);
                    vis[x] = 1;
                }
            }
        
            for(auto& x : vis) if(!x) return false;
       
            return true;
    }
};