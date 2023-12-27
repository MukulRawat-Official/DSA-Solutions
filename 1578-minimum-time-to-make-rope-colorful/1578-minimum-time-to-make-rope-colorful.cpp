class Solution {
public:
    int minCost(string colors, vector<int>& arr) 
    {
         int n = arr.size() , sum = 0;
          
         for(int i = 0;i<n; ){
             int curr = i;
             vector<int>tmp;
             while(curr < n && colors[i] == colors[curr]) { tmp.push_back(arr[curr]); curr++;}
             i = curr;
             sort(tmp.rbegin(),tmp.rend());
             for(int i = 1;i<tmp.size();i++) sum += tmp[i];
         }  
        
         return sum;
    }
};