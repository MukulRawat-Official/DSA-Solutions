class RandomizedSet {
public:
    set<int>s;
    vector<int>arr;
    int n;
    RandomizedSet() {
        n = 0;
    }
    
    bool insert(int val) {
        if(s.count(val)) return 0;
        s.insert(val);
        arr.push_back(val);
        n++;
        return 1;
    }
    
    bool remove(int val) {
        if(!s.count(val)) return 0;
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] == val){
                break;
            } idx++;
        }
        s.erase(val);
        arr.erase(arr.begin() + idx);
        n--;
        return 1;
    }
    
    int getRandom() {
         int idx = rand() % n;
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */