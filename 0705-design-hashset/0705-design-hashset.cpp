class MyHashSet {
public:
    set<int>s;
    MyHashSet() {
        
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        if(s.count(key))
        s.erase(key);
    }
    
    bool contains(int key) {
        return s.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */