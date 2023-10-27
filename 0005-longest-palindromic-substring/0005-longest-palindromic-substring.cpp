class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        int ans = 0;
        string y = "";
        
        for(int i=0;i<n;i++)
        {
            int left = i-1, right = i+1 , count = 1;
            
            while(left>=0 && right <n && s[left] == s[right])
            {
                left--;
                right++;
                count+=2;
            }
            
            if(count>ans)
            { 
                ans = count;
                left++;
                right--;
                y = s.substr(left ,right-left+1);
            }
               
            left = i;
            right = i+1;
            count = 0;
            
             while(left>=0 && right <n && s[left] == s[right])
            {
                left--;
                right++;
                count+=2;
            }
            
             if(count>ans)
             {
                 left++;
                 right--;
                 ans = count;
                 y = s.substr(left,right-left+1);
             }
        
        }
        
        return y;
    }
};