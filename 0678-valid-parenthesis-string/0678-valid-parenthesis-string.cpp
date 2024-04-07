class Solution {
public:
    
    bool give(string& s , char a  , char b){
          int c = 0 ,sp = 0 , n = s.size();;
        
        vector<int>arr;
        
        for(auto& x : s){
            if(x == a) c++;
            else if(x == b) c--;
            else sp++;
            
            if(c < 0){
                if(sp){
                    sp--;
                    c++;
                }
                
                else return false;
            }
        }
        
        if(c > sp ) return false;
        return true;
    }
    bool checkValidString(string s) {
       if(!give(s,'(' , ')')) return false;
       reverse(s.begin(),s.end());
       if(!give(s,')','(')) return false;
        
       return true;
    }
};