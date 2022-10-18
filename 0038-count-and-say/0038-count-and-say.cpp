class Solution {
public:
    string f(int n)
    {
        if(n == 1) return "1";
        string curr = f(n-1);
        
        int prev = curr[0] - '0' , cnt = 1;
        string ans = "";
        for(int i = 1;i<curr.size();i++)
        {
          int e = curr[i] - '0';
          if(prev == e)cnt++;
          else
          {
              ans = ans + to_string(cnt) + to_string(prev);
              prev = e;
              cnt = 1;
          }
        }
        
        ans = ans + to_string(cnt) + to_string(prev);
        return ans;
    }   
    string countAndSay(int n) {
       return f(n);   
    }
};