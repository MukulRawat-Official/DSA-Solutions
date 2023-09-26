class Solution {
public:
    string removeDuplicateLetters(string str) {
       unordered_map<char,int>m , v;
       
       for(auto&x : str)
       {m[x]++; v[x] = 0;}
        
        stack<char>s;
        for(auto& x : str)
        {
            if(!s.size())
            {s.push(x);  v[x] = 1;}
            
            else
            {
               if(!v[x])
               {
                  while( s.size()&& s.top() > x && m[s.top()])
                  { v[s.top()] = 0; s.pop();}
                 
          
                  s.push(x);
                  v[x] = 1;
               }
            }
            
            m[x]--;
        }
        
        string temp = "";
        
        while(s.size())
        {temp = s.top() + temp; s.pop();}
        
        return temp;
    }
};