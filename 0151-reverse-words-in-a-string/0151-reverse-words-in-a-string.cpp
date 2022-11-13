class Solution {
public:
    string reverseWords(string s) {
        
        s+=" ";
        string ans = "" , temp = "";
        int n = s.length();
        
        for(int i =0;i<n;i++)
        {
            if(s[i] != 32)
            temp +=s[i];
            
            else
            {
               if(temp.size() != 0)
               {
                   if(ans.size() == 0)
                       ans = temp;
                   
                   else
                       ans = temp + " " + ans;
               }
                
               temp = "";
            }
            
        }
        
        return ans;
    }
};