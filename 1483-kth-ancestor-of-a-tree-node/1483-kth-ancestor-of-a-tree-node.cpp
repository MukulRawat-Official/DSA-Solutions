class TreeAncestor {
public:
    vector<vector<int>>tree;
    TreeAncestor(int n, vector<int>& parent) {
      tree.resize(20,vector<int>(n,-1));
      for(int i = 0;i<n;i++) tree[0][i] = parent[i];
        
      for(int i = 1;i<20;i++){
          for(int j = 0;j<n;j++){
              if(tree[i-1][j] == -1) tree[i][j] = -1;
              else tree[i][j] = tree[i-1][tree[i-1][j]];
          }
      } 
        
      // for(int i = 0;i<20;i++){
      //     for(int j = 0;j<n;j++) cout<<tree[i][j]<<" "; cout<<endl;
      // }
        
    }
    
    int getKthAncestor(int node, int k) {
        long curr = node , f = 0;
        while(k && curr != -1)
        {
            if(k & 1)   
            curr = tree[f][curr];
            k >>= 1;
            f++;
         
        }
        
        return curr;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */