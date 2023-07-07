class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
     
        
        
        auto give = [&](char ch)->int{
         int n = s.size() , l = 0;
         int ans = 0 , m = k;
          for(int i =0;i<n;i++){
              if(s[i] == ch) m--;
              
              while(m<0){
                  if(s[l] == ch)m++;
                  l++;
              }
              ans = max(ans , i - l + 1);
           }
            return ans;
        };
        
        return max(give('T') , give('F'));
    }
};