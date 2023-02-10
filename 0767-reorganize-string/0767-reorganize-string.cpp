class Solution {
public:
    string reorganizeString(string s) {
        map<int,int>mp;
        int n = s.size();
        for(auto& x : s) { mp[x]++; if(mp[x] >(n+1)/2) return "";}
        priority_queue<pair<int,char>>q;
        
        for(auto& x : mp)    q.push({x.second,x.first});
            
        
        string ans(n,' ');
        pair<int,char> curr = q.top(); q.pop();
        for(int i = 0;i<n;i+=2){
            ans[i] = curr.second;
            if(curr.first == 1){ curr = q.top(); q.pop();}
            else curr.first--;
            
        }
        for(int i = 1;i<n;i+=2){
            ans[i] = curr.second;
            if(curr.first == 1){    curr = q.top(); q.pop();}
            else curr.first--;
        }
        
        return ans;
    }
};