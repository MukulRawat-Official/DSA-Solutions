class Solution {
public:
    bool flt(string& s){
        return ( ((s[0] == '0') && s.size() > 1) || stoi(s) > 255);
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size() , i , j ,k,l;
        vector<string>ans;
        for(int i = 1;i<=3;i++){
            for(int j = 1;j<=3;j++){
                for(int k = 1;k<=3;k++){
                    for(int l = 1;l<=3;l++){
                        if(i+j+k+l !=  n) continue;
                        string a = s.substr(0,i);
                        string b = s.substr(i,j);
                        string c = s.substr(i+j,k);
                        string d = s.substr(i+j+k,l);
                        if(flt(a) || flt(b) || flt(c) || flt(d)) continue;
                        string tmp = a + "." + b + "." + c + "." + d;
                        ans.push_back(tmp);
                    }
                }
            }
        }
        
        return ans;
    }
};