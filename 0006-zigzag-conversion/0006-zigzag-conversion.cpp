class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>arr(numRows , "");
        int idx = 0 , n = s.size() , d = 1; 
        

        for(int i = 0;i<n;i++){
            arr[idx].push_back(s[i]);
            
            if(d & 1) idx++;
            else idx--;
                   
            
            if(idx<0) { idx = min(numRows-1,1); d = 1;}
            else if(idx == numRows) { idx = max(0,numRows-2);  d = 0;}
            // cout<<idx<<endl;
        
        }
        
        
        string ans = "";
        
        for(auto& x :arr) { ans += x; }
        return ans;
        
    }
};