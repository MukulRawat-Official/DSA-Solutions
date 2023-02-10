class MyCircularQueue {
public:
    vector<int>arr;
    int l ,r , k;
    MyCircularQueue(int k) {
        arr.resize(k+1,-1);
        l = 0, r = 0;
        this->k = k+1;
    }
    
    bool enQueue(int value) {
        if( (r+1) % k == l) return false;
        arr[r++] = value;
        r %= k;
        return true;
    }
    
    bool deQueue() {
        if(l == r)return false;
        arr[l] = -1;
        l = (l+1) % k;
        return true;
    }
    
    int Front() {
        return arr[l];
    }
    
    int Rear() {
        if(r == 0) return arr[k-1];
        return arr[r-1];
    }
    
    bool isEmpty() {
        return l == r;
    }
    
    bool isFull() {
        return (r+1) % k == l;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */