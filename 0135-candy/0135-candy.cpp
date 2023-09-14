class Solution {
public:
    int candy(vector<int>& arr) {
       
        int n = arr.size();
        vector<int>l(n,1) , r(n,1);
        
        for(int i = 1;i<n;i++)
        {
            if(arr[i] > arr[i-1])
                l[i] = l[i-1] + 1;
        }
        
        for(int i =n-2;i>=0;i--)
        {
            if(arr[i] > arr[i+1])
                r[i] = r[i+1] + 1;
        }
        
        int ans = 0;
        
        for(int i =0;i<n;i++)
        {
            ans += max(l[i] , r[i]);
        }
        return ans;
        
    }
};