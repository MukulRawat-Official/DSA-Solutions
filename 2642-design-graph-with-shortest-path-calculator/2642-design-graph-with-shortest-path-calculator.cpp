class Graph {
public:
    typedef long long ll;
    ll adj[100][100] , need , n; 
    Graph(int n, vector<vector<int>>& edges) {
        
        for(int i = 0;i<n;i++) 
            for(int j = 0;j<n;j++) 
                if(i == j)adj[i][i] = 0;
                else adj[i][j] = 1e9;
        
        for(auto& x : edges) adj[x[0]][x[1]] = x[2];
        this->n = n;
        need = 1;
    }
    
    void addEdge(vector<int> x) {
        adj[x[0]][x[1]] = x[2];
        need = 1;
    }
    
    int shortestPath(int node1, int node2) {
        if(!need) return (adj[node1][node2] >= 1e9 ? -1 : adj[node1][node2]);
        
        for(int m = 0;m<n;m++){
            for(int i = 0;i<n;i++){
                if(m == i) continue;
                for(int j = 0;j<n;j++){
                    if(i == j || m == j) continue;
                    adj[i][j] = min(adj[i][m] + adj[m][j]  , adj[i][j]);
                }
            }
        }
        need = 0;
        
        return (adj[node1][node2] >= 1e9 ? -1 : adj[node1][node2]); 
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */