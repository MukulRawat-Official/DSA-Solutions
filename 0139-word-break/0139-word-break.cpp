class Solution {
public:
    struct Trie{
        Trie* arr[26];
        bool last;
        Trie(){
            for(int i = 0;i<26;i++) arr[i] = NULL;
            last = false;
        }
        
        void insert(string& s){
            Trie* head = this;
            for(auto& x : s){
                int idx = x - 'a';
                if(!head->arr[idx]) head->arr[idx] = new Trie();
                head = head->arr[idx];
            }
           
            head->last = true;
        }
    };
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        Trie* root = new Trie();
        for(auto& x : wordDict){
            root->insert(x);
        }
        
        int dp[n];
        memset(dp,-1,sizeof(dp));
        function<int(int)> recurr = [&](int i){
            if(i == n) return 1;
            int &ans = dp[i];
            if(ans != -1) return ans; ans = 0;
            
            Trie* curr = root;
            for(int j = i;j<n;j++){
                int idx = s[j] - 'a';
                
                if(!curr -> arr[idx]) break;
                curr = curr -> arr[idx];
                if(curr -> last) ans |= recurr(j+1);
            }
            
            return ans;
        };
        
        return recurr(0);
    }
};