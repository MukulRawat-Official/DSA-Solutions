class MedianFinder {
public:
    priority_queue<int> mxhp;
    priority_queue<int,vector<int> , greater<int>> mnhp;
    bool even = true;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        even = !even;
        
        if(mxhp.size() == 0){ mxhp.push(num); return; }
        if(mnhp.size() == 0){
            int a = min(num,mxhp.top());
            int b = max(num,mxhp.top()); mxhp.pop();
            mxhp.push(a);
            mnhp.push(b);
            return; 
        }
        if(!even) {
            mnhp.push(num);
            mxhp.push(mnhp.top());
            mnhp.pop();
        }
        
        else
        {
            mxhp.push(num);
            mnhp.push(mxhp.top());
            mxhp.pop();
        }
    }
    
    double findMedian() {
        if(even) return (mxhp.top() + mnhp.top()) * 1.0 / 2;
        else return mxhp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */