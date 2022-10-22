class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        
        int c = 0;
        for(int i=0;i<t.size();i++)
        {
            if(!m[t[i]]) // calc total no of charecters required
                c++;
            m[t[i]]++;
        }
        
      
        
        int ans = INT_MAX, left = 0;
        string x = "";
        for(int i=0;i<s.size();i++)
        {
             m[s[i]]--;
            
             if(!m[s[i]]) // ie t requirement for this character is over
                   c--;
                   
                   
             while(!c)
                   {
                      if(m[s[left]]== 0) // removal will break rules    
                      break;
                      
                      if(m[s[left]])
                      m[s[left]]++; // dropping a character
                 
                      left++;
                   }
                   
                   
             if(!c && ans> i-left+1) // requirement done;
                   {
                      ans = i-left+1;
                      x = s.substr(left,i-left+1);
                     
                   }
                   
        }
                   
                 return x;
        
    }
};