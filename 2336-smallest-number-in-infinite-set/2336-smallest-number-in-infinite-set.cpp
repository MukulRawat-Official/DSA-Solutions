class SmallestInfiniteSet {
public:
    vector<int>arr;
    SmallestInfiniteSet() {
        arr.resize(1001,1);
    }
    
    int popSmallest() {
        int ans;
        for(int i = 1;i<=1000;i++){
            if(arr[i]){
                arr[i] = 0;
                ans = i;
                break;
            }
        }
        
        return ans;
    }
    
    void addBack(int num) {
        arr[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */