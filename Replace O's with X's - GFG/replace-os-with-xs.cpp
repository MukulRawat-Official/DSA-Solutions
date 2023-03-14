//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> arr)
    {
        queue<long>q;
        vector<int>le ={1,0,-1,0} , ri = {0,1,0,-1};
        
        for(int i = 0;i<n;i++){
            if(arr[i][0] == 'O') q.push({i * m }) , arr[i][0] = 'd';
            if(arr[i][m-1] == 'O') q.push({i*m + m - 1}) , arr[i][m-1] = 'd';
        }
        
        for(int j = 1;j<m-1;j++){
            if(arr[0][j] == 'O') q.push({j}) , arr[0][j] = 'd';
            if(arr[n-1][j] == 'O') q.push({(n-1) * m + j}) , arr[n-1][j] = 'd';
        }
        
        while(q.size()){
            long curr = q.front(); q.pop();
            long r = curr / m , c = curr % m;
            
            for(int k = 0;k<4;k++){
                long x = r + le[k];
                long y = c + ri[k];
                
                if(x < 0 || y < 0 || x == n || y == m || arr[x][y] != 'O') continue;
                arr[x][y] = 'd';
                q.push({x * m + y});
            }
        }
        
        for(auto& x : arr) for(auto& y : x) if(y != 'd') y = 'X'; else y = 'O';  
        return arr;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends