class Solution {
public:
    int closestMeetingNode(vector<int>& arr, int a, int b) {
        
        map<int,int>m , n;
        
        int cnt = 0;
        vector<int>chk(arr.size() , 0);
        while(1)
        {
            m[a] = cnt;
            
            if(arr[a] == -1 || chk[arr[a]]) break;
            
            chk[a] = 1;
            a = arr[a];
            cnt++;
        }
        cnt= 0;
        
        for(auto& x : chk)
            x = 0;
     
        while(1)
        {
            n[b] = cnt;
            
            if(arr[b] == -1 || chk[arr[b]]) break;
            chk[b] = 1;
            b = arr[b];
            cnt++;
        }
        
        int ans = INT_MAX , val = -1;
        for(auto& x : m)
        {
            if(n.count(x.first))
            {int t = max(n[x.first] , x.second);
            
            if(t<ans)
            {
                ans = t;
                val = x.first;
            }
            }
        }
        
        return val;
    }
};