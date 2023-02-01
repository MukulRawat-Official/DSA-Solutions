class Solution {
public:
    bool f(string& a , string& b){
        if(a.size() % b.size()) return false;
        string tmp = "";
        
        while(tmp.size()<a.size())  tmp += b;
        return tmp == a;
        
    }
    string gcdOfStrings(string str1, string str2) {
        int ans = 0; string res = "";
        string tmp = str2;
    
            for(int j = str2.size();j;j--)
            {
                if(f(str1,tmp) && f(str2,tmp))   { return tmp;}
                tmp.pop_back();
            }
            
        
        return "";
    }
};