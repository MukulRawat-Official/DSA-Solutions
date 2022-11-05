class Solution {
public:
    struct node{
      vector<node*>arr;
      bool nl = true; 
      
      node(){
          arr.resize(26,NULL);
      }
    };
    vector<int> l = {1,0,-1,0} , r = {0,1,0,-1};
    vector<string>ans;
    int n , m;
    void recurr(vector<vector<char>>& board, vector<vector<bool>>& vis, node* head , int i , int j , string& curr)
    {
      if(i == n || j == m) return;
      if(head->nl == false){
       ans.push_back(curr);
       head->nl = true;
      }
      
      for(int k = 0;k<4;k++){
          int x = l[k] + i , y = j + r[k];
          if(x>=0 && x < n && y>=0 && y<m && !vis[x][y] && head->arr[board[x][y] - 'a']){
            node* tmp = head->arr[board[x][y] - 'a'];
            vis[x][y] = 1;
            curr.push_back(board[x][y]);
            recurr(board,vis,tmp,x,y,curr);
            vis[x][y] = 0;
            curr.pop_back();
          }
      }
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)     {
       node* head = new node();
       head->nl = true; 
       for(auto& x : words){
            node* curr = head;
            
            for(auto& t : x){
                if(curr->arr[t-'a'])
                    curr = curr->arr[t-'a'];
                else{
                  node* tmp = new node();
                  curr->arr[t-'a'] = tmp;
                  curr = tmp;
                }
            }
            
            curr->nl = false;
        }       
       n = board.size();
       m = board[0].size();
       vector<vector<bool>>vis(n,vector<bool>(m,0));
       string curr = "";
       for(int i = 0;i<n;i++){
       for(int j = 0;j<m;j++){
           if(head->arr[board[i][j] - 'a']){
               curr.push_back(board[i][j]);
               vis[i][j] = 1;
               recurr(board,vis,head->arr[board[i][j] - 'a'],i,j,curr);
               vis[i][j] = 0;
               curr.pop_back();
           }
          }
       }
        
       return ans;
    }
};