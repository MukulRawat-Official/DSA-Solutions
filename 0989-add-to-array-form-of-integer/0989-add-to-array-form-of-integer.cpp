class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        string s = to_string(k);
        string f = "";
        
        for(auto& x : nums)    f.push_back('0' + x);
        int d = abs((int)f.size()- (int)s.size());
        string t (d,'0');
        if(f.size() < s.size()){
            f = t + f;
        }
        else s = t + s;
        vector<int>ans;
        int c = 0;
        for(int i  = s.size()-1;i>=0;i--){
            int val = s[i] + f[i] + c - 2 * '0';
            ans.push_back(val % 10);
            c = val/10;
        }
        
        if(c) ans.push_back(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};