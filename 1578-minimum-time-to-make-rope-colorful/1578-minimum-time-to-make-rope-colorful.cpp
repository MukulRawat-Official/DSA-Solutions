class Solution {
public:
    int minCost(string colors, vector<int>& arr) 
    {
         int n = arr.size() , sum = 0;
          
         for(int i = 0;i<n; ){
             int curr = i , val = arr[i];
             vector<int>tmp;
             
             while(curr < n && colors[i] == colors[curr]) { 
               sum += arr[curr];
               val = max(val , arr[curr++]);
             }
             
             sum -= val;
             i = curr;
         } 
        
         return sum;
    }
};