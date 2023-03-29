class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.rbegin(),arr.rend());
        long long ans = 0 , curr = 0 , f= 1 , sum = 0 , neg = 0;
        int  n = arr.size();
        int i = 0;
        for( ;i<n;i++){
           if(arr[i]<0)
            break;
        }
        
        if(!i) return 0;
        for(int j= i-1;j>=0;j--){
             ans += arr[j] * f;
            curr += arr[j];
            f++;
        }
        
        // cout<<curr<<endl;
        
  
        
        while(i<n){
            if(curr > -(neg + arr[i])) {
                ans += curr + neg + arr[i];
                neg += arr[i];
            }
            i++;
        }
        
        return ans;
        
    }
};