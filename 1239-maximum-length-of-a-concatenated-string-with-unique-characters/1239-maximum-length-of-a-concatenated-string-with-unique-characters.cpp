class Solution {
public:
    int f(vector<string>&arr , int idx , map<char,int>&m)
    {
        if(idx == arr.size()) return 0;
        int ans = f(arr,idx+1,m);
        
        string& t = arr[idx];
        bool ft = 0;
        int c = 0;
        
        for(auto& x : t) {if(m.count(x)) ft = 1; 
         m[x]++; c++;
        }
        
        if(!ft)
        ans = max(ans,f(arr,idx+1,m)+c);
        
        for(auto& x : t)
        {
            if(m[x] == 1) m.erase(x);
            else m[x]--;
        }
        
        return ans;
        
    }
    int maxLength(vector<string>& arr) {
        map<char,int>m;
        return f(arr,0,m);
    }
};