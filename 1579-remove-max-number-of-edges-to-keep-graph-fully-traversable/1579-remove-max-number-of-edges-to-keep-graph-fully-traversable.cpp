class disjointSet{
    vector<int>parent,size;
    public:
        disjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0; i<=n; i++){
                parent[i]=i;
            }
        }
        int findParent(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int parentOfU=findParent(u);
            int parentOfV=findParent(v);
            if(parentOfU==parentOfV) return;
            if(size[parentOfU] < size[parentOfV]){
                parent[parentOfU]=parentOfV;
                size[parentOfV]+=size[parentOfU];
            }
            else{
                parent[parentOfV]=parentOfU;
                size[parentOfU]+=size[parentOfV];
            }
        }
        bool check(int first,int second){
            if(findParent(first)==findParent(second)) 
                return true;
            return false;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        disjointSet ds1(n);
        disjointSet ds2(n);
        int alice=0,bob=0,both=0;
        for(auto it:edges){
            int type=it[0];
            int node1=it[1];
            int node2=it[2];
            if(type==1 || type==2)continue;
            if(ds1.check(node1,node2) && ds2.check(node1,node2)){
                both++;
            }
            else{
                ds1.unionBySize(node1,node2);
                ds2.unionBySize(node1,node2);
            }
        }
        for(auto it:edges){
            int type=it[0];
            int node1=it[1];
            int node2=it[2];
            if(type==1){
                if(ds1.check(node1,node2))alice++;
                else ds1.unionBySize(node1,node2);
            }
            else if(type==2){
                if(ds2.check(node1,node2))bob++;
                else ds2.unionBySize(node1,node2);
            }
        }
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int i=1; i<=n; i++){
            st1.insert(ds1.findParent(i));
            if(st1.size()>1)break;
        }
        for(int i=1; i<=n; i++){
            st2.insert(ds2.findParent(i));
            if(st2.size()>1)break;
        }

        if(st1.size()==1 && st2.size()==1)
        return alice+bob+both;
        return -1;
    }
};