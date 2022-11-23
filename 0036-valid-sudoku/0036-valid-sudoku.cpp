class Solution {
public:
    bool check(vector<vector<char>>&board,int k,int l)
    {
        bool ans = true;
        unordered_set<char>set;
           for(int  i= k;i<k+3;i++)
           {
               
               for(int j=l;j<l+3;j++)
               {
                    if(set.find(board[i][j])!=set.end())
                    {
                       ans = false;
                       break;
                    }
                   
                   if(board[i][j]!='.')
                       set.insert(board[i][j]);
               }
               if(ans == false)
                   break;
           }
        
        return ans;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<char>set;
        bool ans = true;
        for(auto v:board)
        {
           for(auto u:v)
           {
                if(set.find(u) != set.end())
                {
                    ans = false;break;
                }
               
               if(u != '.')
               set.insert(u);
           }
            if(ans  == false)
            break;
            set.clear();
        }
        
        if(ans == true)
        for(int i=0;i<9;i++)
        {
           for(int j=0;j<9;j++)
           {
               if(set.find(board[j][i]) != set.end())
               {
                   ans = false;
                   break;
               }
               
               if(board[j][i] != '.')
                   set.insert(board[j][i]);
           }
            
            if(ans == false)
                break;
            set.clear();
        }
        
        
        if(ans == true)
        {
            int i=0,j = 0,ctr = 0;
            for(int k=0;k<9;k++)
            {
                   ans = check (board,i,j);
                  i = (i + 3)%9;
                
                  ctr++;
                   if(ctr == 3)
                   {
                       ctr=0;
                       j+=3;
                   }
                    if(ans == false)
                        break;
            }
        }
        
        return ans;
        
    }
};