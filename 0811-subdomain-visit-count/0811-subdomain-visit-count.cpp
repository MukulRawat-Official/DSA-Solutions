class Solution {
public:
    
    vector<string> subdomainVisits(vector<string>& arr) {
        int n = arr.size();
        vector<int>val;
        map<string,int>mp;
        auto give = [&](string& s)->string{
            int i = 0;
            while(s[i] != ' ') i++;
            val.push_back(stold(s.substr(0,i)));
            return s.substr(i+1);
        };
        
        auto find = [&](string& s , int val){
            mp[s]+=val;
            string tmp = "";
            reverse(s.begin(),s.end());
            for(auto& x : s){
                if(x == '.'){
                    string chk = tmp;
                    reverse(chk.begin(),chk.end());
                    mp[chk]+=val;
                }
                tmp.push_back(x);
            }
            
    
        };
        
        for(auto& x : arr)  x = give(x);
        for(int i = 0;i<n;i++) find(arr[i],val[i]);
        
        
        vector<string>ans;
        for(auto& x : mp)
        ans.push_back(to_string(x.second) + " " + x.first);
        return ans;
    }
};