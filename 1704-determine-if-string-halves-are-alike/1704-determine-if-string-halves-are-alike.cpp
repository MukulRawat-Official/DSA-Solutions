class Solution {
public:
    bool halvesAreAlike(string s) {
      vector<char> t = {'a' , 'e' , 'i' , 'o' , 'u' , 'A', 'E', 'I' , 'O' , 'U'};
      int  f = 0 , ss = 0 , n = s.size() ;
        
      for(int i = 0;i<n/2;i++){
          for(auto& x : t){if(x == s[i])f++;}
      }
          
      for(int i = n/2;i<n;i++){
          for(auto& x : t){if(x == s[i])ss++;}
      }
        
      return f == ss;
    }
};