class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
       int ans = 0 , n = arr.size();
       multiset<int>s;
       for(auto& x : arr)s.insert(x);
        
       while(s.size()){
           auto it = --s.end();
           int val = *it;
           s.erase(it);
           
           if(s.size() && limit > val){
               auto it = s.lower_bound(limit - val + 1);
               
               if(it != s.begin())
               it = prev(it);
               
               if(*it + val <= limit) s.erase(it);
           }
           ans++;
           
           // cout<<s.size()<<endl;
       }
        
        return ans;
    }
};