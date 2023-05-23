class KthLargest {
public:
    int idx , id , n;
    vector<int>num;
    KthLargest(int k, vector<int>& nums) {
        num = nums;
        id = k;
        n = num.size();
        sort(num.begin() , num.end());
    }
    
    int add(int val) {
        num.push_back(val);
        n++;
        for(int i = n-2;i>=0;i--){
            if(num[i] > num[i+1])swap(num[i] , num[i+1]);
            else break;
        }
        
        return num[n-id];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */