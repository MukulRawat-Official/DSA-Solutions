class SmallestInfiniteSet {
public:
    set<int>st;

    SmallestInfiniteSet() {
     
    }
    
    int popSmallest() {
        int ans = 1;
        for(auto& x : st){
            if(x == ans) ans++;
            else break;
        }
        st.insert(ans);
        return ans;
    }
    
    void addBack(int num) {
        if(st.count(num)) st.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */