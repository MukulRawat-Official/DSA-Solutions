class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string,int>vis, st;
        
        
        for(auto& x : deadends) st[x];
        
        queue<string>q;
        q.push("0000");
        if(st.count("0000")) return -1;
        vis[q.front()];
        
    while (q.size() && !vis.count(target)){
       string curr = q.front();
       q.pop();
        
       int val = vis[curr];
        
       for(int j = 0;j<4;j++){
           char ch = curr[j];
           
           if(ch == '0') curr[j] = '9';
           else curr[j]--;
           
           if(vis.count(curr) || st.count(curr)) {}
           else {
               vis[curr] = val + 1;
               q.push(curr);     
           }
           curr[j] = ch;
           
           if(ch == '9') curr[j] = '0';
           else curr[j]++;
           
           if(vis.count(curr) || st.count(curr)) {}
           else{
           vis[curr] = val + 1;
           q.push(curr);
           }
           
           curr[j] = ch;
          
         }
    }
        
       return !st.count(target) && vis.count(target) ? vis[target] : -1;
    }
};