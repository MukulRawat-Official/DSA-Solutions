class Solution
{
    public:
        struct node
        {
            int i, j, t;
        };

    int n, m;
    vector<int> l = { 1,0, -1, 0}, r = { 0, 1, 0, -1};
    int i, j;

    int nearestExit(vector<vector < char>> &arr, vector< int > &ent)
    {
        n = arr.size();
        m = arr[0].size();
  
        i = ent[0];
        j = ent[1];
        arr[i][j] = '+';

        queue<node> q;
        int ans = INT_MAX;
        q.push({ i, j, 0});

        while (q.size())
        {
            node t = q.front();
            q.pop();
            if ((t.i == n - 1 || !t.i || !t.j || t.j == m - 1) && (t.i != i || t.j != j))
            {
                ans = min(ans, t.t);
                continue;
            }

            for (int k = 0;k<4;k++){
                int x = t.i + l[k] ;
                int y = t.j + r[k];
                
                if(x>-1 && y>-1 && x<n && y<m && arr[x][y] == '.'){
                   arr[x][y] = '+';
                   q.push({x,y,t.t+1});
                }
            }
        }
        
        if (ans == INT_MAX) ans = -1;
        return ans;
    }
};