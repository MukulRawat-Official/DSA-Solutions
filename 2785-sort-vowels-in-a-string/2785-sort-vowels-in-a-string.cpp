class Solution {
public:
    string sortVowels(string s) {
       vector<char>vowels;
       for(auto& x : s){
           if(x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U') vowels.push_back(x);
       }
       sort(vowels.rbegin() , vowels.rend());
        
      string ans;
        
       for(auto& x : s){
           if(x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U') 
           {
               ans.push_back(vowels.back());
               vowels.pop_back();
           }
           else ans.push_back(x);
       }
        
       return ans;
        
    }
};