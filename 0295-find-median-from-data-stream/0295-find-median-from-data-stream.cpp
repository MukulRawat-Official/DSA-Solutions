class MedianFinder {
public:
    multiset<int>s;
    multiset<int>::iterator it;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert(num);
        if(s.size() == 1) it = s.find(num);
        else if(num < *it){
            if(s.size() % 2 == 0) it--;
        }
        else if(num >= *it){
            if(s.size() % 2) it++;
        }
        
        // for(auto& x : s) cout<<x<<" ";
        // cout<<"Middle = "<<*it;
        // cout<<endl;
    }
    
    double findMedian() {
      double  ans = *it;
      auto it2 = it;
      if(s.size() % 2 == 0) {it2++;
       ans += *it2; ans/=2;
        }
      return ans;  
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */