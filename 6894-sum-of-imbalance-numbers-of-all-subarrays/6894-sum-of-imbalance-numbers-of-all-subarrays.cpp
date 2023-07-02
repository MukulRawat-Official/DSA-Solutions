class Solution {
public:
    int sumImbalanceNumbers(vector<int>& arr) {
        // need to destroy previous one and add new one
        // need to look for forward operation only  i -> i + 1
        int n = arr.size();
        int curr , ans = 0;
        vector<int>mp(n+5);
        auto sol = [&](int x, int y)
        {
            if(mp[x] && !mp[x+1]) curr += y;
        };
        for(int i = 0;i<n;i++){
          fill(mp.begin() , mp.end() , 0);
          curr = 0;
          for(int j = i;j<n;j++){
              sol(arr[j] , -1);
              sol(arr[j] - 1, -1); // deleting previous state;
              mp[arr[j]]++;
              sol(arr[j] , 1);
              sol(arr[j] - 1, 1); // inserting current answer;
              ans += curr - 1;  
              /* as first element will also have answer for arr[i] - 1 which will not needed to be count;*/
          }    
        }
        
        return ans;
    }
};