class Solution {
public:
    int large(vector<int>& h )
    {
        int ans = 0;
        int n = h.size();
        
        stack<int>s;
        s.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(s.size() && h[s.top()] >= h[i])
            {
                int l , r , x ,t = s.top();
                s.pop();  
                
                if(s.size())
                    l = t - s.top() -1;
                
                else
                    l  = t;
                
                r = i - 1 - t;
                
                x = (l+r+1) * h[t];
                
                ans = max(ans,x);
            }
            
            s.push(i);
        }
        
        while(s.size())
        {
            int  l , r , x , t;
            
            t = s.top();
            s.pop();
            
            
            if(s.size())
              l = t - s.top() -1;
                
            else
              l  = t;
              
            r = n-1-t;
            
            x = (l+r+1) * h[t];
            
            ans = max(ans,x);
        }
        
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& a) {
        int m   = a.size();
        int n  = a[0].size();
        
        int ans = 0;
        
        vector<int>h(n,0);
        
        for(int i=0;i<m;i++)
        {
            for(int j= 0;j<n;j++)
            {
                if(a[i][j] == '1')
                h[j]++;
                
                else
                h[j] = 0;
             
                
              
            }
            
            // for(auto& i : h)
            //     cout<<i<<" ";
            // cout<<endl;
            
               ans = max(ans, large(h));
            
             cout<<ans<<" ";
        }
    
        return ans;
    }
};