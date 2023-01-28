class SummaryRanges {
public:
    set<int>s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
       vector<vector<int>>ans;
       int l = - 1 , r = -1;
        
      for(auto& x : s){
         if(l == -1) l = r = x;
         else if(r == x - 1)    r++;
         else {
             ans.push_back({l,r});
             l = r = x;
         }
      }
      if(l != -1) ans.push_back({l,r});
      return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */