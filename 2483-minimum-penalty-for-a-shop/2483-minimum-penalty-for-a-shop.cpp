class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.size();
        vector<int>l(n,0) , r(n,0);
        
        for(int i = 0;i<n;i++){
            if(s[i] == 'N') l[i]++;
            else r[i]++;
            if(i) l[i] += l[i-1];
        }
        
        int ans = n , val = l.back();
        for(int i = n-1;i>=0;i--){
            if(i + 1 < n) r[i] += r[i+1];
            int curr = i ? l[i-1] : 0;
            curr += r[i];
            
            if(curr <= val){
                ans = i;
                val = curr;
            }
        }
        
        return ans;
    }
};