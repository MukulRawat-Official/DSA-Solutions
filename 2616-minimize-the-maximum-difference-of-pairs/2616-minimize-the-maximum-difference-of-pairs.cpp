class Solution {
public:

    int minimizeMax(vector<int>& arr, int p) {
       int n = arr.size();
       sort(arr.begin() , arr.end());
        
       long long l = -1 , h = 0;
       for(auto& x : arr) h = max(h, 1ll* x + 1);
       
       auto chk = [&](long long curr)->bool{
           int cnt = 0;
           for(int i = 1;i<n;i++){
               if(arr[i] - arr[i-1] <= curr){cnt++; i++;} 
           }
           
           return cnt >= p;
       };
        
       while(h - l > 1){
           long long mid = (h + l) / 2;
           
           if(chk(mid)) h = mid;
           else l = mid;
       }
        
        return h;
    }
};