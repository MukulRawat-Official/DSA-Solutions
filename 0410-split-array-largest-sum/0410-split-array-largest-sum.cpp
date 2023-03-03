class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        long l = -1 , h = 1;
        for(auto& x : arr) h += x;
        
        auto chk = [&](int sum)->bool{
           
            int cnt = 1 ,curr = 0;
            
            for(auto& x : arr){
                if(x > sum) return false;
                if(curr + x <= sum) curr+=x;
                else curr = x , cnt++;
            }
            
            return cnt<=k;
        };
        
        
        while(h-l>1){
            long mid = (h+l) / 2;
            
            if(chk(mid)) h = mid;
            else l = mid;
        }
        
        return h;
    }
};