class Solution {
public:
    int strStr(string h, string x) {
        if(h.size()<x.size()) return -1;
        
        for(int i = 0;i<= h.size() - x.size();i++)
        {
            if(h[i] == x[0])
            if(h.substr(i,x.size()) == x) return i;
            
        }
        
        return -1;
        
    }
};