class Solution {
public:
    int minSpeedOnTime(vector<int>& arr, double hour) {
        int n = arr.size();
        auto chk = [&](long mid)->bool
        {
           double sum = 0;    
           for(int i= 0;i<n;i++)
           {
               double x = 1.0 * arr[i] / mid;
               if(i != n-1)  sum += ceil(x);
               else sum += x;
           }
          
           return sum <= hour;
        };
        
        long mx = 1e7;
        long l = 0 , h = mx + 1 ;
        while(h - l > 1){
            long mid = (h + l) >> 1;
            if(!chk(mid)) l = mid;
            else h = mid;
        }
        
        return h > mx ? -1 : h;
        
    }
};