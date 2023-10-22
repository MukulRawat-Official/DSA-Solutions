class Solution {
public:
    int maximumScore(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>left(n, 0) , right(n,n-1);
        
        
        
        stack<int>st;
     
        for(int i = k;i>=0;i--){
            while(st.size() && arr[st.top()] >=  arr[i]) {
                int curr = st.top(); st.pop();
                left[curr] = i;
            }
            st.push(i);
        }
        while(st.size()) st.pop();
       
        
        for(int i = k;i<n;i++){
            while(st.size() && arr[st.top()] >=  arr[i]) {
                int curr = st.top(); st.pop();
                right[curr] = i;
            }
            st.push(i);
        }
     
        
        int i = k , j = k , ans = arr[k] , minm = arr[k];
        
        while(i > 0 && j + 1 < n){
            
            if(arr[left[i]] >= arr[right[j]])
            {
                ans = max(ans , ( right[j] - left[i] - 1) * minm);
                i = left[i];
                minm = min(minm,arr[i]);
            }
            else{
                ans = max(ans , ( right[j] - left[i] - 1) * minm);
                j = right[j];
                minm = min(minm,arr[j]);   
            }
            ans = max(ans , (j - i + 1) * minm);
            
           // cout<<ans<<" "<<minm<<" "<<i<<" "<<j<<endl;
        }
        
        while(i > 0){
            i = left[i];
            ans = max(ans , (j - i) * minm);
            minm = min(minm,arr[i]);
            ans = max(ans , (j - i + 1) * minm);
        }
        while(j + 1 < n){
            j = right[j];
            ans = max(ans , (j - i) * minm);
            minm = min(minm,arr[j]);
            ans = max(ans , (j - i + 1) * minm);
        }
        ans = max(ans , n * minm);
        return ans;
    }
};