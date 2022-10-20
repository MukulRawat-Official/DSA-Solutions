class Solution {
public:
    string intToRoman(int num) {
     
   
        
        vector<char>arr;
        
        arr.push_back('I');
        arr.push_back('V');
        arr.push_back('X');
        arr.push_back('L'); // 50
        arr.push_back('C'); // 100
        arr.push_back('D'); // 500
        arr.push_back('M'); // 1000;
        
        int val = 0;
        int idx = 0;
        string ans = "";
        
        while(num>0)
        {
           int rem = num%10;
            
           if(rem>=1 && rem<=3)
           while(rem--)
               ans= arr[idx] + ans;
            
           else if(rem == 4)
           {
               ans =  arr[idx+1] + ans;
               ans = arr[idx] + ans;
           }
           else if(rem == 5)
               ans = arr[idx + 1] + ans;
            
           else if(rem==6 || rem == 7 || rem == 8)
           {
               for(int i=6;i<=rem;i++)
                   ans = arr[idx] + ans;
               
               ans = arr[idx+1] + ans;
               
           }
            
           else if(rem == 9)
           {
               ans =  arr[idx+2] + ans;
               ans = arr[idx] + ans;
           }
            
            idx+=2;
            num/=10;
            val++;
        }
        
    
        return ans;
    }
};