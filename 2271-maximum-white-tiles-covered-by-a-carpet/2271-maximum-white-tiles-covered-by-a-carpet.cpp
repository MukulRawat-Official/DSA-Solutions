class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& arr, int len) {
        sort(arr.begin(),arr.end()); 
        int n = arr.size();
          vector<int>psum(n,0);
        for(int i = 0;i<n;i++){
            psum[i] = arr[i][1] - arr[i][0] + 1;
            if(i) psum[i] += psum[i-1];
        }
        
        long ans = 0;
        
        for(int i = 0;i<n;i++){
            int l = i - 1 , h = n;  //  i .... n - 1
            int reach = arr[i][0] + len - 1;
            
            while(h-l>1)
            {
                int mid = (h + l) / 2;
                
                bool chk = (arr[mid][0] <= reach);
                // current index is able to reach by carpet
                if(chk) l = mid;
                else h = mid; 
            }
             
            long tmp_ans = psum[l];
            if(i) tmp_ans -= psum[i-1];
            //   L .... R   psum[R] - psum[L-1]
            
            tmp_ans -= max(0 , arr[l][1] - reach);
            //             R1   D   R2
            
            ans = max(ans,tmp_ans);
         }
        
         return ans;
         
    }
};