class Solution {
public:
    vector<string>ans;
    vector<string>no;
    
    void recurr(string digits,string formed, int i , int n)
    {
       if(i==n)
       {
           ans.push_back(formed);
           return;
       }
       
       for(auto& x : no[digits[i] - '2'])
       {
           
           recurr(digits,formed + x,i+1,n);
       }
          
           
    }
    
    vector<string> letterCombinations(string digits) {
      
        int n = digits.length();
        
        if(n==0)
            return ans;
        
        char ch = 'a';
        for(int i=2;i<=9;i++)
        {
            int x = 3;
            
            if(i == 7 || i == 9)
                x++;
            
            string temp = "";           
            while(x--)
            {
               temp+=ch;
               ch++;
            }
            
            no.push_back(temp);
        }
        
        
        
        for(auto& i: no)
            cout<<i<<" ";
        
        
        
        recurr(digits,"",0,n);
        
        return ans;
    }
};