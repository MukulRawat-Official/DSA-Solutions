class Graph {
public:
    typedef long long ll;
    vector<vector<pair<ll,ll>>>adj;
    vector<int>vis;
    ll val , node;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n);
        for(auto& x : edges) adj[x[0]].push_back({x[1] , x[2]});
   
    }
    
    void addEdge(vector<int> x) {
        adj[x[0]].push_back({x[1],x[2]});
    }
    
    int shortestPath(int node1, int node2) {
        if(node1 == node2) return 0;
        for(auto& x : vis) x = 0;
        priority_queue<pair<ll,ll>>pq;
        pq.push({-1,node1});
        
        
        while(pq.size()){
            tie(val , node) = pq.top(); pq.pop();
            if(vis[node]) continue;
            vis[node] =  -val;
            for(auto& [x,w]: adj[node]){
                if(vis[x]) continue;
                pq.push({val - w ,  x});
            }
        }
        
        return vis[node2] ? vis[node2] - 1 : -1;
        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */