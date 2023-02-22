class Solution {
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int h = 1 , l = 0;
        for(auto& x : arr) h += x;
        
        while(h-l>1){
          int mid = (h+l)/2;
            
          int c = 1 , curr = 0;
            
          for(auto& x : arr){
              if(curr + x <= mid) curr += x;
              else if(x > mid){
                  c = days+1;
                  break;
              }
              else c++ , curr = x;
          }
            
          if(c<=days) h = mid;
          else l = mid;
          
        }
        
        return h;
    }
};