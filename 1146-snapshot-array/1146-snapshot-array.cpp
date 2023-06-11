class SnapshotArray {
public:
    unordered_map<int,int>upd;
    vector<map<int,int>>arr;
    int n;
    int ctr = 0;
    SnapshotArray(int length) {
        n = length;
        arr.resize(n);
        for(int i = 0;i<n;i++) upd[i] = 0; // index ctr , val
    }
    
    void set(int index, int val) {
       upd[index] = val;
    }
    
    int snap() {
        for(auto& x : upd){
            arr[x.first][ctr] = x.second;
        }
        upd.clear();
        return ctr++;
    }
    
    int get(int index, int snap_id) {
       map<int,int>& mp = arr[index];
        auto it = mp.lower_bound(snap_id + 1);
        it--;
        
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */